#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAX = 2005;
const int mod = 1000000007;

int add(int a, int b) { return (a + b) % mod; }

int n, m, d;
string a, b;

int dp[2][2][MAX][MAX];

int solve(int ta, int tb, int i, int r) {
  if (i == n) return r == 0;

  int &ret = dp[ta][tb][i][r];
  if (ret >= 0) return ret;
  ret = 0;

  int lo = ta ? a[i] - '0' : 0;
  int hi = tb ? b[i] - '0' : 9;

  if (i % 2) {
    if (d >= lo && d <= hi)
      ret = solve(ta && d == lo, tb && d == hi, i + 1, (r * 10 + d) % m);
  } else {
    FOR(j, lo, hi + 1) {
      if (j == d) continue;
      ret = add(ret, solve(ta && j == lo, tb && j == hi, i + 1, (r * 10 + j) % m));
    }
  }

  return ret;
}

int main(void) 
{
  cin >> m >> d;
  cin >> a;
  cin >> b;
  n = (int)a.size();

  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(1, 1, 0, 0));
  
  return 0;
}