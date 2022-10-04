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
 
using namespace std;
 
typedef long long ll;

#define int long long
 
const int N = 2e5 + 7;
 
struct fenwick {
  vector <ll> f;
  int n;
 
  fenwick(int _n) {
    n = _n;
    f.resize(n);
  }
 
  void add(int i, ll val) {
    for (; i < n; i |= i + 1) f[i] += val;
  }
 
  ll get(int r) {
    ll res = 0;
    for (; r >= 0; r &= r + 1, --r) res += f[r];
    return res;
  }
 
  ll sum(int l, int r) {
    return get(r) - get(l - 1);
  }
};
 
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  vector <ll> ans(n);
  fenwick f(n);
  for (int i = n - 1; i >= 0; --i) {
    ans[p[i]] += f.get(p[i]);
    f.add(p[i], 1);
  }
  for (int i = 1; i < n; ++i) ans[i] += ans[i - 1];
  set <int> pos;
  vector <int> wh(n);
  for (int i = 0; i < n; ++i) wh[p[i]] = i;
  fenwick sum(n), cnt(n);
 
  auto get = [&] (int id) {
    int l = cnt.sum(0, id);
    int r = cnt.sum(id, n - 1);
    return (ll)id * l - sum.sum(0, id) + sum.sum(id, n - 1) - (ll)id * r - (ll)l * (l - 1) / 2 - (ll)r * (r - 1) / 2;
  };
  for (int i = 0; i < n; ++i) {
    int x = wh[i];
    sum.add(x, x);
    cnt.add(x, 1);
    int l = -1, r = n - 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (cnt.sum(0, m) < cnt.sum(m + 1, n - 1)) {
        l = m;
      } else {
        r = m;
      }
    }
    ans[i] += get(r); 
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
}