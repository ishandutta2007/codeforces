// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

template<typename T> struct fenwick {
  int n;
  vector<T> tree;
 
  void build(vector<T> x) {        
    vector<T> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1] + x[i - 1];
      tree[i] = pref[i] - pref[i - (i & -i)];
    }
  }
 
  fenwick(int _n, T def = T{}) : n(_n) {
    tree.resize(n + 1);
	tree[0] = def;
    build(vector<T>(n, def));
  }

 void modify(int i, T x) {
    assert(i >= 0 && i < n);
    ++i;
    while (i <= n) {
      tree[i] += x;
      i += (i & -i);
    }
  }

  T get(int i) {
    assert(i >= 0 && i < n);
    ++i;
    T res = tree[i];
	i -= (i & -i);
    while (i > 0) {
      res += tree[i];
      i -= (i & -i);
    }
    return res;
  }

  T get(int l, int r) {
    return (l == 0 ? get(r) : get(r) - get(l - 1));
  }

  template<class F, typename... Q> int find_first(F op, Q... qs) { 
    //true for suffix, find first index which returns true from suffix
    int cur = 0;
    T sum = tree[0];
    for (int i = __lg(n); i >= 0; --i) {
      if (cur + (1 << i) <= n && !op(sum + tree[cur + (1 << i)], qs...)) {
        cur += (1 << i);
        sum = sum + tree[cur];
      }
    }
    return (cur == n ? -1 : cur);
  }

  template<class F, typename... Q> int find_last(F op, Q... qs) { 
    //true for prefix, find last index which returns true from prefix
    int cur = 0;
    T sum = tree[0];
    for (int i = __lg(n); i >= 0; --i) {
      if (cur + (1 << i) <= n && op(sum + tree[cur + (1 << i)], qs...)) {
        cur += (1 << i);
        sum = sum + tree[cur];
      }
    }
    return (cur == 0 ? -1 : cur - 1);
  }

  void clear() {
    build(vector<T>(n, tree[0]));
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
    }
    sort(b.begin(), b.end());
    debug(a, b);
    priority_queue<int> pq;
    long long ans = 0;
    for (auto x : a) {
      int left = int(lower_bound(b.begin(), b.end(), x) - b.begin());
      int right = int(lower_bound(b.begin(), b.end(), x + 1) - b.begin());
      /*
      if (right > 0 && b[right - 1] != x) {
        --right;
      }
      */
      debug(left, right, pq);
      pq.push(left);
      if (pq.top() > right) {
        ans += pq.top() - right;
        pq.pop();
        pq.push(right);
      }
      debug(pq, ans);
    }
    debug(ans);

    long long a_inv = 0;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.rbegin(), ord.rend(), [&](int x, int y) {
      return a[x] < a[y];
    });
    fenwick<int> fenw(n);
    int lst = 0;
    for (int i = 0; i < n; ++i) {
      a_inv += fenw.get(ord[i]);
      if (i < n - 1 && a[ord[i]] != a[ord[i + 1]]) {
        while (lst <= i) {
          fenw.modify(ord[lst], +1);
          ++lst;
        }
      }
    }

    debug(ans, a_inv);
    cout << ans + a_inv << '\n';
  }
}