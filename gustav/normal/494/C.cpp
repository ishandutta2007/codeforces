#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MAXN = 100005;
const int MAXQ = 5005;
const int inf = 1000000000;

int N, Q;
int a[MAXN];

int I[MAXQ];
int l[MAXQ];
int r[MAXQ];
double p[MAXQ];
int maxi[MAXQ];

int dad[MAXQ];
vector< int > T[MAXQ];

set< int > s;
int get_first(int lo) {
  auto it = s.lower_bound(lo);
  if (it == s.end()) return inf;
  return *it;
}

bool bio[MAXQ][MAXQ];
double memo[MAXQ][MAXQ];

double P(int i, int x) {
  int d = x - maxi[i];
  if (x < maxi[i]) return 0.0;
  if (x > maxi[i] + Q) return 1.0;

  if (bio[i][d]) return memo[i][d];
  bio[i][d] = true;
  
  double &ret = memo[i][d];
  ret = 1.0;

  double p_take = p[i];
  double p_leave = 1.0 - p[i];

  if (T[i].size() == 0) {
    if (maxi[i] > x - 1)
      return ret = p_leave;
    return ret = 1.0;
  }

  if (maxi[i] == x) p_take = 0;

  for (int j : T[i]) {
    p_take *= P(j, x - 1);
    p_leave *= P(j, x);
  }

  ret *= (p_take + p_leave);

  return ret;
}

int main(void) {
  scanf("%d%d", &N, &Q);

  REP(i, N) scanf("%d", a + i);
  ++Q;
  FOR(i, 1, Q) {
    scanf("%d%d%lf", l + i, r + i, p + i), I[i] = i;
    --l[i];
    --r[i];
  }

  l[0] = 0;
  r[0] = N - 1;
  p[0] = 0.0;
  I[0] = 0;

  sort(I, I + Q, [](int a, int b) {
      int la = r[a] - l[a];
      int lb = r[b] - l[b];
      if (la != lb) return la > lb;
      return a < b;
    });

  memset(dad, -1, sizeof dad);

  REP(i, Q) {
    int li = l[I[i]];
    int ri = r[I[i]];
    for (int j = i - 1; j >= 0; --j) {
      int lj = l[I[j]];
      int rj = r[I[j]];
      if (lj <= li && ri <= rj) {
	dad[I[i]] = I[j];
	T[I[j]].push_back(I[i]);
	break;
      }
    }
  }

  REP(i, N) s.insert(i);
  for (int i = Q - 1; i >= 0; --i) {
    int now = I[i];
    int lo = l[now];
    int hi = r[now];

    for (int child : T[now]) maxi[now] = max(maxi[now], maxi[child]);

    while (get_first(lo) <= hi) {
      maxi[now] = max(maxi[now], a[get_first(lo)]);
      s.erase(get_first(lo));
    }
  }

  int r = 0;
  double sol = 0.0;

  for (int i = 0; i <= Q; ++i) {
    int x = maxi[r] + i;
    sol += x * (P(r, x) - P(r, x - 1));
  }

  printf("%.10lf\n", sol);

  return 0;
}