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

#define MAXN 1111111
int ans[MAXN], U, tans[MAXN];
int N;

map< pair<int, int>, int > m;
int M = 0;
vector<int> v[MAXN];

pair<int, int> c[MAXN];
#define O ((long double)1.0)
#define EPS 1e-15

long double s(int A, int B, int C) {
  return (O / c[B].first - O / c[A].first)*(O / c[C].second - O / c[A].second)
       - (O / c[B].second - O / c[A].second)*(O / c[C].first - O / c[A].first);
}

void convex_hull() {
  sort(c, c + N);
  U = 0;
  REP(i, N) {
    while ((U && c[tans[U - 1]].second <= c[i].second) || (U > 1 && s(i, tans[U - 1], tans[U - 2]) < -EPS)) U--;
    tans[U] = i;
    ans[U++] = m[c[i]];
  }
}

vector<int> t;

int main(int argc, char *argv[]) {
  int M;
  scanf("%d", &M);
  REP(i, M) {
    scanf("%d%d", &c[N].first, &c[N].second);
    pair<int, int> p = c[N];
    if (!m.count(p)) m[p] = N++;
    v[m[p]].push_back(i);
  }
  /*
  REP(i, N) {
    printf("x: %d y: %d", c[i].first, c[i].second);
    REP(j, v[i].size()) printf(" %d", v[i][j]); printf("\n");
  }
  */
  convex_hull();
  REP(i, U) t.insert(t.end(), v[ans[i]].begin(), v[ans[i]].end());
  sort(t.begin(), t.end());
  REP(i, t.size()) {
    if (i) printf(" ");
    printf("%d", t[i] + 1);
  }
  printf("\n");
  return 0;
}