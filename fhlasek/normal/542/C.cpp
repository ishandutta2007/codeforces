/* Written by Filip Hlasek 2015 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 222
int p[MAXN], N;

long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

long long lcm = 1;
int dist_to_cycle[MAXN];
int dfs(int v, int from_start=1) {
  if (dist_to_cycle[v] == MAXN) {
    dist_to_cycle[v] = -from_start;
    int tmp = dfs(p[v - 1], from_start + 1);
    if (dist_to_cycle[v]) dist_to_cycle[v] = tmp + 1;
    return dist_to_cycle[v];
  }
  else {
    if (dist_to_cycle[v] < 0) {
      long long cycle_len = from_start + dist_to_cycle[v];
      // if (cycle_len % 2 == 0) cycle_len /= 2;
      lcm /= gcd(lcm, cycle_len); lcm *= cycle_len;
      dist_to_cycle[v] = 0;
      int w = p[v - 1];
      while (w != v) { dist_to_cycle[w] = 0; w = p[w - 1]; }
    }
    return dist_to_cycle[v];
  }
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%d", p + i);
  REP(i, N + 1) dist_to_cycle[i] = MAXN;
  int max_dist = 0;
  REP(i, N) max_dist = max(max_dist, dfs(i + 1));
  long long ans = lcm;
  while (ans < max_dist) ans += lcm;
  cout << ans << endl;
  return 0;
}