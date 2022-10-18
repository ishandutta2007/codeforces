/* Written by Filip Hlasek 2013 */
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

#define MAXN 555
int N, x[MAXN];
long long m[MAXN][MAXN];
long long A[MAXN];

int main(int argc, char *argv[]){
  scanf("%d", &N);
  REP(i, N) REP(j, N) scanf("%d", & (m[i][j]));
  REP(i, N) { scanf("%d", x + i); x[i]--; }
  reverse(x, x + N);
  long long ans = 0;

  REP(i, N) {
    REP(j, i) REP(k, i) m[x[j]][x[i]] = min(m[x[j]][x[i]], m[x[j]][x[k]] + m[x[k]][x[i]]);
    REP(j, i) REP(k, i) m[x[i]][x[j]] = min(m[x[i]][x[j]], m[x[i]][x[k]] + m[x[k]][x[j]]);
    REP(j, i) ans += m[x[j]][x[i]] + m[x[i]][x[j]];
    REP(j, i) REP(k, i) if(m[x[j]][x[i]] + m[x[i]][x[k]] < m[x[j]][x[k]]) {
      ans -= m[x[j]][x[k]] - m[x[j]][x[i]] - m[x[i]][x[k]];
      m[x[j]][x[k]] = m[x[j]][x[i]] + m[x[i]][x[k]];
    }
    A[i] = ans;
  }

  reverse(A, A + N);
  REP(i, N) {
    if(i) printf(" ");
    cout << A[i];
  }
  printf("\n");
  return 0;
}