/*
 * author:  ADMathNoob
 * created: 07/21/21 09:00:28
 * problem: https://codeforces.com/contest/1268/problem/C
 */

/*
g++ 1268C.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1268C.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }
  Fenwick<int> ft(n);
  Fenwick<long long> ft_sum(n);
  long long invs = 0;
  for (int i = 0; i < n; i++) {
    invs += ft.get(n - 1) - ft.get(pos[i]);
    ft.modify(pos[i], +1);
    ft_sum.modify(pos[i], pos[i]);
    long long cntL = i / 2 + 1;
    long long cntR = i + 1 - cntL;
    int mid = ft.lower_bound(cntL);
    long long left = ft_sum.get(mid);
    long long right = ft_sum.get(n - 1) - left;
    long long ans = 0;
    ans += mid * cntL - left - (cntL - 1) * cntL / 2;
    ans += right - mid * cntR - cntR * (cntR + 1) / 2;
    ans += invs;
    if (i > 0) {
      cout << ' ';
    }
    cout << ans;
  }
  cout << '\n';
  return 0;
}