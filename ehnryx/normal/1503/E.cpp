#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr char nl = '\n';
constexpr int MOD = 998244353;

int add(int a, int b) {
  return a+b < MOD ? a+b : a+b - MOD;
}

const int N = 2021 + 1;
int ncr[2*N][2*N], f[N][N], g[N][N];

int solve(int n, int m) {
  for(int i=1; i<n; i++) {
    g[i][m] = 0;
    for(int j=m-1; j>0; j--) {
      g[i][j] = add(g[i][j+1], (ll)f[i][m-1-j] * f[i-1][j] % MOD);
    }
  }

  int ans = 0;
  for(int s=1; s<n; s++) {
    for(int t=1; t<m; t++) {
      ans = add(ans, (ll)f[s][t-1] * f[s-1][m-t] % MOD * g[n-s][t+1] % MOD);
    }
  }
  return ans;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  for(int i=0; i<2*N; i++) {
    ncr[i][0] = ncr[i][i] = 1;
    for(int j=1; j<i; j++) {
      ncr[i][j] = add(ncr[i-1][j], ncr[i-1][j-1]);
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      f[i][j] = ncr[i+j][j];
    }
  }

  int n, m;
  cin >> n >> m;
  int ans = add(solve(n, m), solve(m, n));
  for(int i=1; i<n; i++) {
    for(int j=1; j<m; j++) {
      ans = add(ans, (ll)f[i][j-1] * f[i-1][m-j] % MOD * f[n-i][m-j-1] % MOD * f[n-i-1][j] % MOD);
    }
  }
  cout << add(ans, ans) << nl;

  return 0;
}