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

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 5555
#define MAX 1111111
int N, K;
int a[MAXN];
int s[MAX][11], m[MAX][11], S[MAX], M[MAX];

void _insert(int t, int a) {
  bool ok = false;
  REP(k, S[t]) if(s[t][k] == a) { ok = true; break; }
  if(!ok) s[t][S[t]++] = a;
  a %= t;
  ok = false;
  REP(k, M[t]) if(m[t][k] == a) { ok = true; break; }
  if(!ok) m[t][M[t]++] = a;
}

int main(int argc, char *argv[]){
  scanf("%d%d", &N, &K);
  REP(i, N) scanf("%d", a + i);
  REP(i, N) REP(j, i) {
    int t = abs(a[i] - a[j]);
    if (S[t] - M[t] <= K) _insert(t, a[i]);
    if (S[t] - M[t] <= K) _insert(t, a[j]);
  }
  FOR(t, 1, MAX-1) {
    for(int j = 2 * t; j < MAX && S[t] - M[t] <= K; j += t) REP(i, S[j]) _insert(t, s[j][i]);
    if(S[t] - M[t] <= K) { printf("%d\n", t); break; }
  }
  return 0;
}