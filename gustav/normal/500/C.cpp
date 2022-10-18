#include <cstdio>
#include <cassert>

#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 505;
const int MAXM = 1005;

int N, M;
int w[MAXN];
int b[MAXM];

int main(void) 
{
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%d", w + i);
  REP(i, M) { scanf("%d", b + i); --b[i]; }

  int sol = 0;
  REP(i, M) {
    int j = i - 1;
    while (j >= 0 && b[j] != b[i]) --j;
    
    set< int > must;
    FOR(k, j + 1, i) must.insert(b[k]);

    for (int k : must) sol += w[k];
  }

  printf("%d\n", sol);

  return 0;
}