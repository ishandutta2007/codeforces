/*
 * author:  ADMathNoob
 * created: 12/12/21 10:15:57
 * problem: https://codeforces.com/contest/1591/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Fenwick {
 public:
  int n;
  int max_power;  // smallest power of 2 larger than n
  vector<T> tree;

  Fenwick(int _n) : n(_n) {
    assert(n >= 0);
    tree.resize(n + 1, 0);
    max_power = (1 << (32 - __builtin_clz(n)));
  }

  T get(int x) const {
    assert(-1 <= x && x < n);
    T res{};
    ++x;
    while (x > 0) {
      res += tree[x];
      x -= x & -x;
    }
    return res;
  }

  void modify(int x, T v) {
    assert(0 <= x && x < n);
    x++;
    while (x <= n) {
      tree[x] += v;
      x += x & -x;
    }
  }

  /*
  returns the first index p such that sum(a[0..p]) >= t
  returns -1 if the empty sum works and n if no sum works

  NOTE: it only makes sense to use this function when all values
  in the array we are maintaining are non-negative;
  this method allows such queries in O(log(n)) instead of O(log^2(n))
  */
  int lower_bound(T t) const {
    if (t <= 0) {
      return -1;
    }
    int res = 0;
    for (int p = max_power; p > 0; p >>= 1) {
      if ((res | p) <= n && tree[res | p] < t) {
        res |= p;
        t -= tree[res];
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<vector<int>> g(n);
    vector<int> pv(n, -1);
    for (int i = 1; i < n; i++) {
      cin >> pv[i];
      --pv[i];
      g[pv[i]].push_back(i);
    }
    vector<vector<int>> qs(n);
    vector<int> L(q), k(q);
    for (int i = 0; i < q; i++) {
      int v;
      cin >> v >> L[i] >> k[i];
      --v;
      qs[v].push_back(i);
    }
    Fenwick<int> ft(n + 1);
    vector<int> ans(q);
    vector<int> cnt(n);
    vector<set<int>> has_cnt(n + 1);
    for (int i = 0; i < n; i++) {
      cnt[i] = 0;
      has_cnt[0].insert(i);
      ft.modify(cnt[i], +1);
    }
    auto Modify = [&](int x, int delta) {
      has_cnt[cnt[x]].erase(x);
      ft.modify(cnt[x], -1);
      cnt[x] += delta;
      has_cnt[cnt[x]].insert(x);
      ft.modify(cnt[x], +1);
    };
    function<void(int)> Dfs = [&](int v) {
      Modify(a[v], +1);
      for (int qid : qs[v]) {
        int small = ft.get(L[qid] - 1);
        int want = ft.lower_bound(small + k[qid]);
        if (want == n + 1) {
          ans[qid] = -1;
        } else {
          ans[qid] = *has_cnt[want].begin();
        }
      }
      for (int u : g[v]) {
        Dfs(u);
      }
      Modify(a[v], -1);
    };
    Dfs(0);
    for (int i = 0; i < q; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << (ans[i] != -1 ? ans[i] + 1 : -1);
    }
    cout << '\n';
  }
  return 0;
}