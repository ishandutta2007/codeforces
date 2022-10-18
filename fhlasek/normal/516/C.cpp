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

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define FORD(i, a, b) for(int i=(a);i>=(b);i--)
#define REP(i, b) for(int i=0;i<b;i++)

using namespace std;

#define MAXN 222222
#define LOG 22
int H[MAXN], D[MAXN];
int N;

int bestL[MAXN][LOG], bestR[MAXN][LOG];
long long pref[MAXN];

long long getDist(int a, int b) {
  if (a <= b) return pref[b] - pref[a];
  return pref[N] - (pref[a] - pref[b]);
}

int combineL(int a, int b) {
  if (getDist(a, b) + 2 * H[a] > 2 * H[b]) return a;
  return b;
}

int combineR(int a, int b) {
  if (getDist(a, b) + 2 * H[b] >= 2 * H[a]) return b;
  return a;
}

int getLeft(int a, int b) {
    int empty;
    if (a <= b) empty = b - a + 1;
    else empty = N - (a - b) + 1;
    int l = 0;
    while ((2 << l) <= empty) ++l;
    int pos1 = a, pos2 = (a + empty - (1 << l)) % N;
    return combineL(bestL[pos1][l], bestL[pos2][l]);
}

int getRight(int a, int b) {
    int empty;
    if (a <= b) empty = b - a + 1;
    else empty = N - (a - b) + 1;
    int l = 0;
    while ((2 << l) <= empty) ++l;
    int pos1 = a, pos2 = (a + empty - (1 << l)) % N;
    return combineR(bestR[pos1][l], bestR[pos2][l]);
}

long long getAns(int a, int b) {
  return getDist(a, b) + 2LL * (H[a] + H[b]);
}

int main(int argc, char *argv[]) {
  int Q;
  scanf("%d%d", &N, &Q);
  REP(i, N) { scanf("%d", D + i); pref[i + 1] = pref[i] + D[i]; }
  REP(i, N) scanf("%d", H + i);
  REP(i, N) bestL[i][0] = bestR[i][0] = i;
  REP(l, LOG - 1) {
    REP(i, N) {
      int ii = (i + (1 << l)) % N;
      bestL[i][l + 1] = combineL(bestL[i][l], bestL[ii][l]);
      bestR[i][l + 1] = combineR(bestR[i][l], bestR[ii][l]);
      // if (l + 1 <= 2) printf("i: %d ii: %d l: %d L: %d R: %d\n", i, ii, l + 1, bestL[i][l + 1], bestR[i][l + 1]);
    }
  }

  while (Q--) {
    int tmp_a, tmp_b;
    scanf("%d%d", &tmp_a, &tmp_b); tmp_a--; tmp_b--;
    int a = (tmp_b + 1) % N, b = (tmp_a - 1 + N) % N;

    long long ans1 = 0, ans2 = 0;
    int aa = getLeft(a, b), bb = 0;
    if (aa != b) { bb = getRight((aa + 1) % N, b); ans1 = getAns(aa, bb); }
    // cerr << ans1 << " " << aa << " " << bb << endl;
    bb = getRight(a, b);
    if (bb != a) { aa = getLeft(a, (bb - 1 + N) % N); ans2 = getAns(aa, bb); }
    // cerr << ans2 << " " << aa << " " << bb << endl;
    cout << max(ans1, ans2) << endl;
  }
  return 0;
}