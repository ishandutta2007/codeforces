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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

map<pair<vector<int>, int>, double> dp;

double solve(vector<int> p, int K) {
  if (!K) {
    int ans = 0;
    REP(i, p.size()) REP(j, i) if (p[j] > p[i]) ans++;
    return ans;
  }
  pair<vector<int>, int> state = make_pair(p, K);
  if (dp.count(state)) return dp[state];
  double ans = 0;
  double den = p.size() * (p.size() + 1) / 2;
  REP(r, p.size()) REP(l, r + 1) {
    reverse(p.begin() + l, p.begin() + r + 1);
    ans += solve(p, K - 1);
    reverse(p.begin() + l, p.begin() + r + 1);
  }
  return dp[state] = ans / den;
}

int main(int argc, char *argv[]) {
  vector<int> p;
  int N, K;
  scanf("%d%d", &N, &K);
  REP(i, N) {
    int a;
    scanf("%d", &a);
    p.push_back(a);
  }
  printf("%.12lf\n", solve(p, K));
  return 0;
}