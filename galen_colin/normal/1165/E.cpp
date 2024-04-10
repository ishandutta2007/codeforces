#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll a[300000], b[300000], d[300000];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (ll i = 0; i < n; i++) d[i] = a[i] * (i + 1) * (n - i);
  sort(b, b+n);
  sort(d, d+n);
  reverse(d, d+n);
  ll ans = 0;
  for (int i = 0; i < n; i++) 
    ans = (ans + (b[i] * (d[i]%mod) % mod)) % mod;
  cout << ans << endl;
}