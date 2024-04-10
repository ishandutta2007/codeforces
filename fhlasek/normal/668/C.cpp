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

using namespace std;

#define MAXN 111111
int N;
double M[MAXN], m[MAXN];
long double A[MAXN], B[MAXN];

int main(int argc, char *argv[]) {
  scanf("%d", &N);
  REP(i, N) scanf("%lf", M + i);
  REP(i, N) scanf("%lf", m + i);
  long double suma = 0, sumb = 0;
  REP(i, N) {
    long double b = suma - sumb - m[i] - M[i];
    long double c = M[i] - suma * (m[i] + M[i]);
    long double d = b * b - 4 * c;
    if (d < 0) d = 0;
    A[i] = (-b + sqrt(d)) / 2;
    if (A[i] < 0) A[i] = 0;
    B[i] = m[i] + M[i] - A[i];
    if (B[i] < 0) B[i] = 0;
    suma += A[i];
    sumb += B[i];
  }
  if (abs(suma - 1) > 0.00001 || abs(sumb - 1) > 0.000001) {
    while (true) { suma += 1; sumb *= 2; } // Cycle...
  }
  REP(i, N) { if (i) printf(" "); printf("%.15lf", (double)A[i]); } printf("\n");
  REP(i, N) { if (i) printf(" "); printf("%.15lf", (double)B[i]); } printf("\n");
  return 0;
}