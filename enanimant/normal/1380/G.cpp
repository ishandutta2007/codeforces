// July 12, 2020
// https://codeforces.com/contest/1380/problem/G

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = 998244353;

long long power(long long b, long long e) {
  long long res = 1;
  while (e > 0) {
    if (e & 1) {
      res = res * b % MOD;
    }
    b = b * b % MOD;
    e >>= 1;
  }
  return res;
}

int inverse(int x) {
  return power(x, MOD - 2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  vector<int> f(n + 1, 0);
  for (int i = 0; i < n; i++) {
    f[i + 1] = (f[i] + a[i]) % MOD;
  }
  int inv_n = inverse(n);
  for (int k = 1; k <= n; k++) {
    long long ans = 0;
    for (int i = 0; i < n; i += k) {
      int r = min(i + k, n);
      ans += 1LL * i / k * (f[r] - f[i]) % MOD;
      ans %= MOD;
    }
    ans = ans * inv_n % MOD;
    if (ans < 0) {
      ans += MOD;
    }
    if (k > 1) {
      cout << ' ';
    }
    cout << ans;
  }
  cout << '\n';
  
  
  return 0;
}