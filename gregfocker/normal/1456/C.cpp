#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 5e5 + 7;
int n;
int k;
ll a[N];
ll suf[N];
ll suf_val[N];


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  k++;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + a[i];
    suf_val[i] = suf_val[i + 1] + suf[i + 1];
  }
  ll sol = suf_val[1], pre = 0;
  for (int i = 1; i <= n; i++) {
    ll coef = (i - 1) / k;
    pre += coef * a[i];
    ll mx = coef + 1;
    ll now = pre + suf[i + 1] * mx + suf_val[i + 1];
    sol = max(sol, now);
  }
  cout << sol << "\n";

}