/*
 * author:  ADMathNoob
 * created: 12/29/21 10:35:16
 * problem: https://codeforces.com/contest/1616/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Fenwick {
 public:
  const int n;
  const int max_power; // smallest power of 2 larger than n
  vector<T> tree;

  Fenwick(int _n) : n(_n), max_power(1 << (32 - __builtin_clz(n))), tree(n) {
    assert(n > 0);
  }

  T get(int x) const {
    assert(-1 <= x && x < n);
    T res{};
    while (x >= 0) {
      res += tree[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }

  void modify(int x, T v) {
    assert(0 <= x && x < n);
    while (x < n) {
      tree[x] += v;
      x |= (x + 1);
    }
  }
};

const long long INF = 1e18;
const int A = 26;

void TestCase() {
  int n;
  string ss, stt;
  cin >> n >> ss >> stt;
  vector<int> s(n), t(n);
  for (int i = 0; i < n; i++) {
    s[i] = ss[i] - 'a';
    t[i] = stt[i] - 'a';
  }
  Fenwick<int> ft(n);
  for (int i = 0; i < n; i++) {
    ft.modify(i, 1); // not moved yet
  }
  vector<int> nxt(A, 0);
  long long ans = INF;
  long long cur = 0;
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < A; c++) {
      while (nxt[c] < n && s[nxt[c]] != c) {
        ++nxt[c];
      }
    }
    for (int c = 0; c < t[i]; c++) {
      if (nxt[c] < n) {
        ans = min(ans, cur + ft.get(nxt[c] - 1));
      }
    }
    if (nxt[t[i]] == n) {
      break;
    }
    cur += ft.get(nxt[t[i]] - 1);
    ft.modify(nxt[t[i]], -1);
    nxt[t[i]] += 1;
  }
  cout << (ans < INF ? ans : -1) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    TestCase();
  }
  return 0;
}