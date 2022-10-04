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

class segtree {
  public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!
    ll a = 0;
    ll add = 0;
    void apply(int l, int r, ll v) {
      a += v;
      add += v;
    }
  };
  node unite(const node &a, const node &b) const {
    node res;
    res.a = min(a.a, b.a);
    return res;
  }
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  }
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
  int n;
  vector<node> tree;
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
  template <typename M>
  void build(int x, int l, int r, const vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }
  int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }
  int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
  template <typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
  template <typename... M>
  void modify(int ll, int rr, const M&... v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
  // find_first and find_last call all FALSE elements
  // to the left (right) of the sought position exactly once
  int find_first(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
  int find_last(int ll, int rr, const function<bool(const node&)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};
 
const ll Inf = 1e18;

ll smart(vector<int> a) {
  int n = a.size();
  vector<vector<ll>> pref(n + 1, vector<ll>(2));
  for (int i = 0; i < n; ++i) {
    pref[i + 1][0] += pref[i][0];
    pref[i + 1][1] += pref[i][1];
    pref[i + 1][i % 2] += a[i];
  }
  vector <ll> vals;
  for (int i = 0; i <= n; ++i) vals.push_back(pref[i][1] - pref[i][0]);
  sort(vals.begin(), vals.end());
  vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
  auto get = [&](int id) {
    return lower_bound(vals.begin(), vals.end(), pref[id][1] - pref[id][0]) - vals.begin();
  };
  vector<vector<int>> gs(n + 1);
  for (int i = 0; i <= n; ++i) {
    gs[get(i)].push_back(i);
  }
  ll ans = 0;
  segtree tree0(n);
  segtree tree1(n);
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      tree1.modify(i, i, Inf);
    } else {
      tree0.modify(i, i, Inf);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (i % 2 == 0) {
      tree0.modify(i, n - 1, a[i]);
      tree1.modify(i, n - 1, -a[i]);
    } else {
      tree0.modify(i, n - 1, -a[i]);
      tree1.modify(i, n - 1, a[i]);
    }
    int id1 = tree1.find_first(i, n - 1, [&](auto node) {return node.a < 0; });
    int id2 = tree0.find_first(i, n - 1, [&](auto node) {return node.a < 0; });
    if (id1 == -1) id1 = n;
    if (id2 == -1) id2 = n;
    int id = min(id1, id2);
    /*int low = i, high = n;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (tree0.get(i, mid).a >= 0 && tree1.get(i, mid).a >= 0) low = mid;
      else high = mid;
    }
    int id = low;*/
    if (id == -1) id = n;
    auto &v = gs[get(i)];
    if (id >= i) ans += upper_bound(v.begin(), v.end(), id + 1) - lower_bound(v.begin(), v.end(), i + 1);
    //cout << i << ' ' << ans << endl;
    /*for (int j = i; j < id; ++j) {
      if (pref[j + 1][1] - pref[i][1] == pref[j + 1][0] - pref[i][0]) {
        ++ans;
      }
    } */  
  }
  return ans;
}
ll stupid(vector<int> a) {
  int n = a.size();
  ll ans = 0;
  for (int l = 0; l < n; ++l) {
    vector<int> b = a;
    for (int r = l; r < n; ++r) {
      if (r > l) {
        int tk = min(b[r - 1], b[r]);
        b[r - 1] -= tk;
        b[r] -= tk;
      }
      bool ok = true;
      for (int k = l; k <= r; ++k) ok &= (b[k] == 0);
      if (ok) ++ans;
    }
  }
  return ans;
}

void stress() {
  int tt = 10000;
  mt19937 rnd(123);
  while (tt--) {
    int n = rnd() % 5 + 1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd() % 10;
    auto sm = smart(a);
    auto st = stupid(a);
    if (sm != st) {
      cout << 1 << endl;
      cout << n << endl;
      for (auto x : a) cout << x << ' ';
      cout << endl;
      cout << sm << ' ' << st << endl;
      exit(0);
    }
    if (tt % 10 == 0) {
      cout << tt << endl;
    }
  }
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  //stress();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << smart(a) << '\n';
  }
}