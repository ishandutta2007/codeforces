#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

ll f(ll x, ll k) {
  ll newlen = x / k;
  ll mod = x % k;
  return newlen * newlen * (k - mod) + mod * (newlen + 1) * (newlen + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <ll> a(n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i] * a[i];
  }
  multiset <pair <ll, pair <int, int>>> s;
  for (int i = 0; i < n; i++)
    s.insert({f(a[i], 2) - f(a[i], 1), {a[i], 1}});
  k -= n;
  while (k--) {
    pair <ll, pair <int, int>> tmp = *s.begin();
    ans += tmp.first;
    s.erase(s.find(tmp));
    ll len = tmp.second.first, k = tmp.second.second;
    s.insert({f(len, k + 2) - f(len, k + 1), {len, k + 1}});
  }
  cout << ans;
  return 0;
}