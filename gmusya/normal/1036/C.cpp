#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

vector <ll> d;
map <pair <bool, pair <int, int>>, ll> dp;

ll get(bool flag, int pos, int nonzero) {
  if (nonzero > 3)
    return 0;
  if (pos == 19)
    return 1;
  pair <bool, pair <int, int>> st = {flag, {pos, nonzero}};
  if (dp.find(st) != dp.end())
    return dp[st];
  ll res = 0;
  if (flag) {
    for (int i = 0; i <= d[pos]; i++)
      res += get(i == d[pos], pos + 1, nonzero + (i != 0));
  } else {
    for (int i = 0; i <= 9; i++)
      res += get(false, pos + 1, nonzero + (i != 0));
  }
  return dp[st] = res;
}

ll get(ll x) {
  dp = map <pair <bool, pair <int, int>>, ll>();
  d.resize(0);
  for (int i = 0; i < 19; i++) {
    d.push_back(x % 10);
    x /= 10;
  }
  reverse(d.begin(), d.end());
  return get(true, 0, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll l, r;
    cin >> l >> r;
    cout << get(r) - get(l - 1) << '\n';
  }
  return 0;
}