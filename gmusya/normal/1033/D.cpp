#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  ll ans = 1;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  vector <ll> d(n);
  vector <bool> flag(n);
  for (int i = 0; i < n; i++) {
    for (ll j = 2; j <= 4; j++) {
      ll sqrti = pow(a[i], 1.0 / j);
      for (ll x = sqrti - 3; x <= sqrti + 3; x++) {
        ll mult = 1;
        for (int d = 0; d < j; d++)
          mult *= x;
        if (mult == a[i]) {
          flag[i] = true;
          d[i] = j + 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++)
    if (!flag[i])
      d[i] = 4;
  vector <ll> b = a;
  for (int i = n - 1; i >= 0; i--) {
    int l = i;
    while (l >= 0 && a[l] == a[i])
      l--;
    l++;
    vector <ll> p;
    for (int j = l - 1; j >= 0; j--)
      if (__gcd(a[j], a[i]) != 1)
        p.push_back(__gcd(a[j], a[i]));
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    for (ll x : p) {
      int cnt = 1;
      for (int j = 0; j < n; j++) {
        while (b[j] % x == 0) {
          b[j] /= x;
          cnt++;
        }
      }
      ans = ans * cnt % MOD;
    }
  }
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n && b[j] == b[i])
      j++;
    j--;
    if (a[i] == b[i]) {
      if (flag[i])
        ans = ans * (1 + (j - i + 1) * (d[i] - 1) % MOD) % MOD;
      else
        ans = ans * ((j - i + 2) * (j - i + 2) % MOD) % MOD;
    } else {
      ans = ans * (1 + (j - i + 1) * (b[i] != 1) % MOD) % MOD;
    }
    i = j;
  }
  cout << ans;
  return 0;
}