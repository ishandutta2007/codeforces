#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

mt19937_64 rnd(time(0));

ll sum(ll a, ll b) {
  ll res = 0;
  ll x = 1;
  while (a || b) {
    ll c = (a + b) % 3;
    res += c * x;
    x *= 3;
    a /= 3, b /= 3;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  vector <ll> h(n + 1);
  for (ll i = 1; i <= n; i++)
    h[i] = rnd() % (ll)(1e17);
  map <ll, ll> cnt;
  vector <ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  vector <vector <ll>> vhod(n + 1);
  vector <ll> curh(n + 1);
  for (ll i = 1; i <= n; i++)
    curh[i] = sum(curh[i - 1], h[a[i - 1]]);
  map <ll, vector <ll>> arr;
  arr[curh[0]].push_back(0);
  long long ans = 0;
  ll l = 0;
  for (ll i = 1; i <= n; i++) {
    vhod[a[i - 1]].push_back(i);
    if (vhod[a[i - 1]].size() > 3)
      l = max(l, vhod[a[i - 1]][vhod[a[i - 1]].size() - 4]);
    ans += arr[curh[i]].end() - lower_bound(arr[curh[i]].begin(), arr[curh[i]].end(), l);
    arr[curh[i]].push_back(i);
  }
  cout << ans;
  return 0;
}