// author: erray
#include <bits/stdc++.h>
 
using namespace std;

template<typename T> struct fenwick {
  int n;
  vector<T> tree;
  fenwick(int _n, T def = T{}) : n(_n) {
    tree.resize(n + 1);
    tree[0] = def;
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
    T res = tree[0];
    while (i > 0) {
      res += tree[i];
      i -= (i & -i);
    }
    return res;
  }

  T get(int l, int r) {
    return get(r) - (l == 0 ? tree[0] : get(l - 1));
  }

  template<class F> int find_first(F op) {
    int cur = 0;
    T sum = tree[0];
    for (int i = __lg(n); i >= 0; --i) {
      if (cur + (1 << i) <= n && !op(sum + tree[cur + (1 << i)])) {
        cur += (1 << i);
        sum = sum + tree[cur]; 
      }      
    }
    return (cur == n ? -1 : cur);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  const int MAX = (*max_element(a.begin(), a.end())) + 1;
  vector<long long> ans(n);
  long long pref = 0;
  fenwick<int> ct(MAX);
  fenwick<long long> sub(MAX);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    ans[i] = ans[i - !!i] + pref + 1LL * i * x;
    pref += x;
    ans[i] -= sub.get(x);
    for (int j = x; j < MAX; j += x) {
      sub.modify(j, x);
      ans[i] -= 1LL * x * ct.get(j, MAX - 1);  
    }
    ct.modify(x, 1); 
  }

  for (auto e : ans) {
    cout << e << ' ';
  }
  cout << '\n';
}