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

void normalize(char a[], int start, int end) {
  if ((end - start) % 2) return;
  int m = (start + end) / 2;
  normalize(a, start, m);
  normalize(a, m, end);
  bool change = false;
  REP(i, m - start) {
    if (a[start + i] > a[m + i]) { change = true; break; }
    else if (a[start + i] < a[m + i]) break;
  }
  if (change) REP(i, m - start) swap(a[start + i], a[m + i]);
}

#define MAXN 222222
char A[MAXN], B[MAXN];
int N;

int main(int argc, char *argv[]) {
  scanf("%s", A);
  scanf("%s", B);
  N = strlen(A);
  normalize(A, 0, N);
  normalize(B, 0, N);
  bool equal = true;
  REP(i, N) if (A[i] != B[i]) equal = false;
  if (equal) printf("YES\n");
  else printf("NO\n");
  return 0;
}