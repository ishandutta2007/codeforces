#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <map>
#include <vector>
#include <algorithm>
#include <functional>

#include <sstream>
#include <iostream>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

const int MAXN = 2005;
const int mod = 998244353;

int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (llint)a * b % mod; }

int fact[2*MAXN];
int choose[2*MAXN][2*MAXN];

int len(int x) {
  return x ? len(x / 10) + 1 : 0;
}

void precalc() {
  fact[0] = 1;
  FOR(i, 1, MAXN) 
    fact[i] = mul(fact[i - 1], i);

  REP(i, MAXN) REP(j, MAXN) {
    if (i < j) choose[i][j] = 0;
    else if (i == 0) choose[i][j] = 1;
    else choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
  }
}

void calc(int f[MAXN][11], vector<int> x) {
  static int dp[MAXN][MAXN][11];

  int N = x.size();
  memset(dp[N], 0, sizeof dp[N]);
  dp[N][0][0] = 1;

  for (int i = N - 1; i >= 0; --i) {
    REP(k, N + 1) {
      REP(r, 11) {
	dp[i][k][r] = dp[i + 1][k][(r + x[i]) % 11];
	if (k) dp[i][k][r] = add(dp[i][k][r], dp[i + 1][k - 1][(r - x[i] + 11) % 11]);
      }
    }
  }

  REP(k, N + 1) REP(r, 11)
    f[k][r] = dp[0][k][r];
}

void solve() {
  static int f[MAXN][11];
  static int g[MAXN][11];

  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  vector<int> ones;
  vector<int> zeros;

  REP(i, n) {
    // TRACE(a[i] _ len(a[i]));
    if (len(a[i]) % 2 == 1)
      ones.push_back(a[i] % 11);
    else
      zeros.push_back(a[i] % 11);
  }

  int N = ones.size();
  int M = zeros.size();

  // TRACE("prije calc");

  calc(g, ones);
  calc(f, zeros);

  // TRACE("nakon calc");

  int pos_groups = (N + 2) / 2;
  int neg_groups = (N + 1) / 2;
  int pos_ones = (N + 1) / 2;
  int neg_ones = N / 2;

  // TRACE(N _ M);

  if (N == 0) {
    int sum = 0;
    for (int x : zeros) sum += x;

    if (sum % 11 == 0)
      cout << fact[M] << endl;
    else
      cout << 0 << endl;

    return;
  }

  int sol = 0;
  REP(k, M + 1) {
    if (neg_groups == 0 && k < M) continue;
    
    REP(r, 11) {
      // TRACE(k _ r);
      // TRACE(pos_ones _ neg_ones);
      int ones = mul(fact[pos_ones], mul(fact[neg_ones], g[pos_ones][r]));

      // TRACE("ones");
      // TRACE(pos_groups + k - 1);
      // TRACE(neg_groups + M - k - 1);
      // TRACE(neg_groups _ pos_groups);

      // TRACE(ones);

      int put_zeros = mul(fact[k],
			  mul(fact[M - k],
			      mul(choose[pos_groups + k - 1][k],
				  choose[neg_groups + M - k - 1][M - k])));


      // TRACE("put");
      int zeros = mul(put_zeros, f[k][(11 - r) % 11]);
      // TRACE("zeros");

      // TRACE(zeros);
      sol = add(sol, mul(ones, zeros));
    }
  }

  cout << sol << endl;
}

int main(void) 
{

  precalc();
  // TRACE(fact[6]);
  // TRACE(choose[4][2]);
  
  int T;
  cin >> T;
  while (T--) solve();

  return 0;
}