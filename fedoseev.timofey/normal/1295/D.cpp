#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <cassert>
#include <complex>
#include <functional>
 
using namespace std;
 
typedef long long ll;

ll gcd(ll a, ll b) {
  return (b == 0 ? a : gcd(b, a % b));
}

vector <pair <ll, int>> factor(ll x) {
  vector <pair <ll, int>> ret;
  for (ll d = 2; d * d <= x; ++d) {
    if (x % d == 0) {
      int cnt = 0;
      while (x % d == 0) {
        x /= d;
        ++cnt;
      }
      ret.push_back({d, cnt});
    }
  }
  if (x > 1) ret.push_back({x, 1});
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    ll a, m;
    cin >> a >> m;
    ll g = gcd(a, m);
    ll sg = g;
    auto pr = factor(m);
    vector <ll> who;
    for (auto &p : pr) {
      while (g % p.first == 0) {
        g /= p.first;
        --p.second;
      }
      if (p.second > 0) who.push_back(p.first);
    } 
    g = sg;
    ll ans = 0;
    for (int mask = 0; mask < (1 << who.size()); ++mask) {
      ll cr = 1;
      for (int i = 0; i < (int)who.size(); ++i) {
        if (mask & (1 << i)) cr *= who[i];
      }
      cr *= g;
      ll need = (cr - (a % cr)) % cr;
      ll have = m / cr + (m % cr > need);
      if (__builtin_popcount(mask) % 2 == 0) ans += have;
      else ans -= have;
    } 
    cout << ans << '\n';
  }
}