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
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
struct op {
  ll a; char c; ll b;
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  set <ll> have;
  vector <op> ans;
  auto sm = [&] (ll a, ll b) {
    if (!have.count(a + b)) {
      assert(have.count(a));
      assert(have.count(b));
      ans.push_back({a, '+', b});
      have.insert(a + b);
    }
    return a + b;
  };
  auto xr = [&] (ll a, ll b) {
    if (!have.count(a ^ b)) {
      assert(have.count(a));
      assert(have.count(b));
      ans.push_back({a, '^', b});
      have.insert(a ^ b);
    }
    return a ^ b;
  };
  ll x;
  cin >> x;
  ll st = x;
  have.insert(x);
  for (int it = 0; it < 19; ++it) {
    ll y = sm(x, x);
    ll z = xr(x, y); 
    ll k = sm(z, x);
    if (it < 18) x = xr(y, k);
    else x = k;
  }
  int cnt = __builtin_ctzll(x);
  while (cnt != 0) {
    ll cr = st;
    for (int i = cnt; i < 30; ++i) {
      if (cr & (1LL << i)) {
        cr = xr(cr, 1LL << i);
      }
    }   
    while (cr != (1LL << (cnt - 1))) {
      cr = sm(cr, cr);
      if (cr & (1LL << cnt)) {
        cr = xr(cr, (1LL << cnt));
      }
    }
    --cnt;
  }
  cout << ans.size() << '\n';
  for (auto o : ans) {
    cout << o.a << ' ' << o.c << ' ' << o.b << '\n';
  }
  assert(have.count(1));
}