#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 3005;

int n, m;
char x[MAX][MAX];

vector< int > l[2 * MAX];
vector< int > r[2 * MAX];

int f[MAX];
int sol[MAX];
vector< int > stop[MAX];

void update(int i) {
  for (++i; i < MAX; i += i & -i)
    f[i] += 1;
}

int query(int i) {
  int ret = 0;
  for (++i; i; i -= i & -i)
    ret += f[i];
  return ret;
}

int solve(int d) {
  vector< int > &L = l[d];
  vector< int > &R = r[d];
  reverse(L.begin(), L.end());
  reverse(R.begin(), R.end());
  int n = L.size();

  int streak = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (L[i] == -1)
      streak = 0;
    else
      L[i] = min(L[i], streak++);
  }

  REP(i, n) stop[i].clear(), sol[i] = 0;
  REP(i, n) if (L[i] != -1) stop[min(n - 1, i + L[i])].push_back(i);

  memset(f, 0, sizeof f);

  REP(i, n) {
    if (L[i] != -1) sol[i] -= query(i);
    if (R[i] != -1) update(max(0, i - R[i]));
    for (int j : stop[i])
      sol[j] += query(j);
  }

  int ret = 0;
  REP(i, n) ret += sol[i];
  return ret;
}

int main(void) 
{
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%s", x[i]);

  REP(i, n) {
    int streak = 0;
    REP(j, m) {
      if (x[i][j] == 'z') 
	r[i + j].push_back(streak++);
      else {
	r[i + j].push_back(-1);
	streak = 0;
      }
    }
    streak = 0;
    for (int j = m - 1; j >= 0; --j) {
      if (x[i][j] == 'z') 
	l[i + j].push_back(streak++);
      else {
	l[i + j].push_back(-1);
	streak = 0;
      }
    }
  }

  llint sol = 0;
  REP(d, n + m - 1) 
    sol += solve(d);

  cout << sol << endl;

  return 0;
}