#include <cstdio>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <complex>
#include <bitset>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 3000;

int x[MAX];
int y[MAX];
bitset< MAX > M[MAX];

int sq(int x) { return x * x; }

int main(void) 
{
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d%d", x + i, y + i);

  vector< pair< int, pair< int, int > > > E;
  REP(i, n) REP(j, i) 
    E.push_back({sq(x[i] - x[j]) + sq(y[i] - y[j]), {i, j}});

  sort(E.rbegin(), E.rend());

  for (auto &e : E) {
    int i = e.second.first;
    int j = e.second.second;
    if ((M[i] & M[j]).count()) {
      printf("%.10lf\n", 0.5 * sqrt(e.first));
      exit(0);
    }
    M[i][j] = 1;
    M[j][i] = 1;
  }

  return 0;
}