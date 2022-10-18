#include <cstdio>
#include <cassert>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 305;

int N;
char buf[MAXN];
int p[MAXN];
int bio[MAXN];
int sol[MAXN];
int a[MAXN][MAXN];

int main(void) 
{
  scanf("%d", &N);
  REP(i, N) { scanf("%d", p + i); --p[i]; }

  REP(i, N) {
    scanf("%s", buf);
    REP(j, N) a[i][j] = buf[j] - '0';
    a[i][i] = 1;
  }

  REP(k, N) REP(i, N) REP(j, N)
    a[i][j] = a[i][j] || (a[i][k] && a[k][j]);

  REP(i, N) {
    if (bio[i]) continue;
    vector< int > ids, vals;
    REP(j, N) if (a[i][j]) ids.push_back(j), vals.push_back(p[j]), bio[j] = 1;

    sort(vals.begin(), vals.end());
    int n = (int)ids.size();
    REP(j, n) sol[ids[j]] = vals[j];
  }

  REP(i, N) printf("%d ", sol[i] + 1);
  puts("");

  return 0;
}