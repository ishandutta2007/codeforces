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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

#define MOD (1LL << 32)

using namespace std;

#define MAXN 222222
int A[MAXN];

int main(int argc, char *argv[]) {
  int N, K;
  scanf("%d%d", &N, &K);
  REP(i, N + 1) scanf("%d", A + i);

  long long rem = 0;
  FOR(i, 0, N + 32) {
    rem += A[i];
    if (rem % 2) {
      long long old_rem = rem;
      REP(j, 31) rem = (rem + A[i + 1 + j] * (1LL << (j + 1))) % MOD;
      if (rem < 0) rem += MOD;
      int ans = 0;
      {
        bool ok = true;
        long long tmp = rem;
        long long nrem = old_rem - tmp;
        nrem /= 2;
        FOR(j, i + 1, N + 32) {
          nrem += A[j];
          if (nrem % 2) { ok = false; break; }
          nrem /= 2;
        }
        if (ok) {
          FORD(j, i, max(0, i - 31)) {
            if (A[j] - tmp >= -K && A[j] - tmp <= K && j <= N && (j != N || A[j] - tmp)) {
              ans++;
            }
            tmp *= 2;
          }
        }
      }
      {
        bool ok = true;
        long long tmp = MOD - rem;
        long long nrem = old_rem + tmp;
        nrem /= 2;
        FOR(j, i + 1, N + 32) {
          nrem += A[j];
          if (nrem % 2) { ok = false; break; }
          nrem /= 2;
        }
        if (ok) {
          FORD(j, i, max(0, i - 31)) {
            if (A[j] + tmp >= -K && A[j] + tmp <= K && j <= N && (j != N || A[j] + tmp)) {
              ans++;
            }
            tmp *= 2;
          }
        }
      }
      printf("%d\n", ans);
      break;
    }
    rem /= 2;
  }
  return 0;
}