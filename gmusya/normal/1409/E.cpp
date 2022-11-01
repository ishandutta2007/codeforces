#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector <ll> x(n);
    for (ll i = 0; i < n; i++)
      cin >> x[i];
    for (ll i = 0; i < n; i++) {
      ll val;
      cin >> val;
    }
    sort(x.begin(), x.end());
    vector <pair <ll, ll>> p;
    {
      ll cnt = 0, l = 0;
      for (ll i = 0; i < n; i++) {
        if (l != x[i]) {
          if (cnt) p.push_back({l, cnt});
          cnt = 0;
          l = x[i];
        }
        cnt++;
      }
      if (cnt) p.push_back({l, cnt});
    }
    ll ans = 0;
    ll m = p.size();
    vector <ll> po(m);
    {
      ll val = 0, l = 0;
      for (ll i = 0; i < m; i++) {
        while (p[l].first + k < p[i].first) val -= p[l].second, l++;
        val += p[i].second;
        po[i] = val;
      }
    }
    vector <ll> pre(m), suf(m);
    pre[0] = po[0];
    for (ll i = 1; i < m; i++)
      pre[i] = max(pre[i - 1], po[i]);
    suf[m - 1] = po[m - 1];
    for (ll i = m - 2; i >= 0; i--)
      suf[i] = max(suf[i + 1], po[i]);
    for (ll i = 0; i < m; i++) {
      pair <ll, ll> tmp = {p[i].first + k + 1, 0};
      ll id = upper_bound(p.begin(), p.end(), tmp) - p.begin();
      if (id < m) ans = max(ans, pre[i] + suf[id]);
    }
    ll val = 0, l = 0;
    for (ll i = 0; i < m; i++) {
      while (p[l].first + 2 * k < p[i].first) val -= p[l].second, l++;
      val += p[i].second;
      ans = max(ans, val);
    }
    cout << ans << '\n';
  }
  return 0;
}