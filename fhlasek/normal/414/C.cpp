/* Written by Filip Hlasek 2014 */
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

#define MAXN 21
#define MAX (1 << MAXN)
int N;
int a[MAX];

long long inv[MAXN][2];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, (1 << N)) scanf("%d", a + i);

  FOR(n, 1, N) {
    inv[n][0] = inv[n - 1][0];
    inv[n][1] = inv[n - 1][1];
    REP(b, (1 << N) / (1 << n)) {
      int start = (1 << n) * b, sz = 1 << (n - 1);
      sort(a + start, a + start + sz);
      REP(ii, sz) {
        int i = start + sz + ii;
        {
          int left = 0, right = sz;
          while (left < right) {
            int middle = (left + right) / 2;
            if (a[start + middle] <= a[i]) left = middle + 1;
            else right = middle;
          }
          inv[n][0] += sz - left;
        }

        {
          int left = 0, right = sz;
          while (left < right) {
            int middle = (left + right) / 2;
            if (a[start + middle] < a[i]) left = middle + 1;
            else right = middle;
          }
          inv[n][1] += left;
        }
      }
    }
  }

  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int q;
    scanf("%d", &q);
    REP(i, q) swap(inv[i][0], inv[i][1]);
    long long diff = inv[q][0] - inv[q][1];
    FOR(i, q, N) {
      inv[i][0] -= diff;
      inv[i][1] += diff;
    }
    printf("%I64d\n", inv[N][0]);
  }

  return 0;
}