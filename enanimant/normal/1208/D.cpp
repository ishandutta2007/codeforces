// August 25, 2019
// https://codeforces.com/contest/1208/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


template <typename T>
class Fenwick {
public:
  int n;
  vector<T> tree;

  Fenwick(int _n) : n(_n) {
    tree.resize(n + 1, 0);
  }

  T sum(int x) {
    assert(-1 <= x && x < n);
    x++;
    T s = 0;
    while (x >= 1) {
      s += tree[x];
      x -= x & -x;
    }
    return s;
  }

  T sum(int a, int b) {
    return sum(b) - sum(a - 1);
  }

  void add(int x, T v) {
    assert(0 <= x && x < n);
    x++;
    while (x <= n) {
      tree[x] += v;
      x += x & -x;
    }
  }

  void assign(int x, T v) {
    add(x, v - sum(x, x));
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<long long> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<int> ans(n);
  Fenwick<long long> ft(n);
  for (int i = 0; i < n; i++) {
    ft.assign(i, i + 1);
  }
  set<int> unused;
  for (int i = 1; i <= n; i++) {
    unused.insert(i);
  }
  for (int i = n - 1; i >= 0; i--) {
    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      long long sum = ft.sum(0, mid - 2);
      if (sum >= s[i]) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    ans[i] = *unused.lower_bound(lo);
    unused.erase(ans[i]);
    ft.assign(ans[i] - 1, 0);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i < n - 1 ? ' ' : '\n');
  }


  return 0;
}