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

#define MAXN 111111
int f[MAXN], L, R;
void add(int x, int val) {
  while (x < MAXN) {
    f[x] += val;
    x += x & (-x);
  }
}
int get(int x) {
  int ans = 0;
  while (x) {
    ans += f[x];
    x -= x & (-x);
  }
  return ans;
}
int get(int start, int end) { // both inclusive, 1 - indexed
  return get(end) - get(start - 1);
}

int main(int argc, char *argv[]) {
  int N, Q;
  scanf("%d%d", &N, &Q);
  REP(i, N) add(i + 1, 1);
  L = 1; R = N;
  while (Q--) {
    // if (L < R) { FOR(i, L, R) printf(" %d", get(i, i)); printf("\n"); }
    // else {      FORD(i, L, R) printf(" %d", get(i, i)); printf("\n"); }

    int cmd;
    scanf("%d", &cmd);
    if (cmd == 1) {
      int p;
      scanf("%d", &p);
      if (L < R) {
        if (L + 2 * p - 1 <= R) {
          REP(i, p) add(L + p + i, get(L + p - i - 1, L + p - i - 1));
          L += p;
        }
        else {
          p = R - L + 1 - p;
          REP(i, p) add(R - p - i, get(R - p + i + 1, R - p + i + 1));
          R -= p;
          swap(L, R);
        }
      }
      else {
        if (L - p - (p - 1) >= R) {
          REP(i, p) add(L - p - i, get(L - p + i + 1, L - p + i + 1));
          L -= p;
        }
        else {
          p = L - R + 1 - p;
          REP(i, p) add(R + p + i, get(R + p - i - 1, R + p - i - 1));
          R += p;
          swap(L, R);
        }
      }
    }
    else {
      int l, r;
      scanf("%d%d", &l, &r);
      int ans;
      if (L < R) ans = get(L + l, L + r - 1);
      else ans = get(L - (r - 1) , L - l);
      printf("%d\n", ans);
    }
  }
  return 0;
}