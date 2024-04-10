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

#define MAXN 111111
int N, P, R;
int A[MAXN], B[MAXN];
int o[MAXN];

bool cmp(int x, int y) {
  if (A[x] == A[y]) return B[x] > B[y];
  return A[x] < A[y];
}

int q[MAXN], Q = 0;

long long s(int a, int b, int c) {
  return ((long long)A[b]-A[a])*(B[c]-B[a]) - ((long long)B[b]-B[a])*(A[c]-A[a]);
}

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  scanf("%d%d", &P, &R);

  double ans = -1;
  REP(i, N) {
    int a, b;
    scanf("%d%d", &a, &b);
    A[i] = a;
    B[i] = b;
    if (ans < 0 || max((double)P / A[i], (double)R / B[i]) < ans) {
      ans = max((double)P / A[i], (double)R / B[i]);
    }
  }

  REP(i, N) o[i] = i;
  sort(o, o + N, cmp);
  REP(ii, N) {
    int i = o[ii];
    while (Q && B[q[Q - 1]] <= B[i]) Q--;
    if (!Q) { q[Q++] = i; continue; }
    if (A[i] == A[q[Q - 1]]) continue;
    while (Q > 1 && s(i, q[Q - 1], q[Q - 2]) <= 0) Q--;
    q[Q++] = i;

    if ((long long)A[q[Q - 2]] * R == (long long)B[q[Q - 2]] * P) continue;
    if ((long long)A[i] * R == (long long)B[i] * P) continue;

    double a1 = A[q[Q - 2]], b1 = B[q[Q - 2]];
    double a2 = A[i], b2 = B[i];
    a1 /= P; a2 /= P; b1 /= R; b2 /= R;
    if ((a1 > b1) == (a2 > b2)) continue;
    double val = ((a1 - a2) + (b2 - b1)) / (a1 * b2 - a2 * b1);
    ans = min(ans, val);
  }

  printf("%.15lf\n", ans);
  return 0;
}