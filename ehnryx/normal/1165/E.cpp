#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  ll a[n]; int b[n];
  for (int i=0; i<n; i++) {
    cin >> a[i];
    a[i] *= (ll) (i+1) * (n-i);
  }
  for (int i=0; i<n; i++) {
    cin >> b[i];
  }
  sort(a,a+n);
  sort(b,b+n,greater<int>());

  ll ans = 0;
  for (int i=0; i<n; i++) {
    ans += a[i]%MOD * b[i] % MOD;
  }
  cout << ans % MOD << nl;

  return 0;
}