/* Written by Filip Hlasek 2016 */
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

#define MAXN 222222
long long T[MAXN];

priority_queue<long long> pq[5];
long long sum_pq[5];

int main(int argc, char *argv[]) {
  int N, K, B, C;
  scanf("%d%d%d%d", &N, &K, &B, &C);
  B = min(B, 5 * C);
  REP(i, N) {
    int t;
    scanf("%d", &t);
    T[i] = t + 1000000000;
  }
  sort(T, T + N);

  long long ans = 1000000000000000000LL;

  REP(i, N) {
    REP(d, 5) {
      int r = (T[i] + d) % 5;
      long long c = d * C - (long long)(T[i] + d) / 5 * B;
      if (i < K) {
        pq[r].push(c);
        sum_pq[r] += c;
      }
      else if (c < pq[r].top()) {
        sum_pq[r] = sum_pq[r] - pq[r].top() + c;
        pq[r].pop();
        pq[r].push(c);
      }
      if (i + 1 >= K) {
        ans = min(ans, sum_pq[r] + (long long)(T[i] + d) / 5 * B * K);
      }
    }
  }

  cout << ans << endl;

  return 0;
}