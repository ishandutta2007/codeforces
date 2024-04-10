#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 5, mod = 998244353;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return (fac[n] * inv[n-k] % mod) * inv[k] % mod;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> b;
  int cnt = 0;
  for (int x : a) {
    if (x == 0) {
      ++cnt;
      continue;
    }
    b.emplace_back(0, cnt);
    b.emplace_back(x, 0);
    cnt = 1;
  }
  b.emplace_back(0, cnt-1);
  int l = 0, r = b.size()-1;
  long long ans = 1;
  long long suml = 0, sumr = 0;
  while (l <= r) {
    if (suml == sumr) {
      if (l == r) {
        ans = ans * powmod(2, b[l].second) % mod;
        break;
      } else {
        int lef = b[l].second, rig = b[r].second;
        long long tot = 0;
        for (int i = 0; i <= min(lef, rig); ++i) {
          tot = (tot + C(lef, i) * C(rig, i)) % mod;
        }
        ans = ans * tot % mod;
        suml += b[l+1].first;
        l += 2;
        continue;
      }
    } else {
      if (suml < sumr) {
        suml += b[l+1].first;
        l += 2;
      } else {
        sumr += b[r-1].first;
        r -= 2;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i-1] * i % mod;
    inv[i] = powmod(fac[i], mod-2);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}