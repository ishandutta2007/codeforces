/*
 * author:  ADMathNoob
 * created: 04/21/21 09:48:16
 * problem: https://codeforces.com/contest/1516/problem/D
 */

/*
g++ 1516D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1516D.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SparseTable {
 public:
  int n;
  vector<vector<T>> t;
  function<T(const T&, const T&)> f;

  SparseTable(const vector<T>& a, const function<T(const T&, const T&)>& _f) : f(_f) {
    n = (int) a.size();
    assert(n > 0);
    int max_log = 32 - __builtin_clz(n);
    t.resize(max_log);
    t[0] = a;
    for (int lg = 1; lg < max_log; lg++) {
      t[lg].resize(n - (1 << lg) + 1);
      for (int i = 0; i <= n - (1 << lg); i++) {
        t[lg][i] = f(t[lg - 1][i], t[lg - 1][i + (1 << (lg - 1))]);
      }
    }
  }

  T get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr < n);
    int lg = 31 - __builtin_clz(rr - ll + 1);
    return f(t[lg][ll], t[lg][rr - (1 << lg) + 1]);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  const int A = 100001;
  vector<int> sieve(A, -1);
  for (int i = 2; i * i < A; i++) {
    if (sieve[i] == -1) {
      sieve[i] = i;
      for (int j = i * i; j < A; j += i) {
        sieve[j] = i;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i < A; i++) {
    if (sieve[i] == -1) {
      sieve[i] = i;
    }
    if (sieve[i] == i) {
      primes.push_back(i);
    }
  }
  int n, tt;
  cin >> n >> tt;
  vector<int> a(n);
  vector<map<int, int>> nxt(n);
  vector<int> cur(A, -1);  // only non-(-1) for primes
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      int p = sieve[x];
      // nxt[i][p] = n;
      if (cur[p] != -1) {
        nxt[cur[p]][p] = i;
      }
      cur[p] = i;
      while (x % p == 0) {
        x /= p;
      }
    }
  }
  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    int j = n - 1;
    for (const auto& p : nxt[i]) {
      j = min(j, p.second - 1);
    }
    r[i] = j;
  }
  SparseTable<int> st(r, [&](int x, int y) {
    return min(x, y);
  });
  vector<int> end(n);
  for (int i = 0; i < n; i++) {
    int low = i;
    int high = n - 1;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      if (st.get(i, mid) >= mid) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    end[i] = low;
  }
  int h = 32 - __builtin_clz(n);
  vector<vector<int>> jump(n, vector<int>(h));
  for (int i = 0; i < n; i++) {
    jump[i][0] = end[i] + 1;
  }
  for (int j = 1; j < h; j++) {
    for (int i = 0; i < n; i++) {
      jump[i][j] = (jump[i][j - 1] == n ? n : jump[jump[i][j - 1]][j - 1]);
    }
  }
  while (tt--) {
    int L, R;
    cin >> L >> R;
    --L;
    --R;
    int at = L;
    int ans = 0;
    for (int j = h - 1; j >= 0; j--) {
      if (jump[at][j] <= R) {
        at = jump[at][j];
        ans += (1 << j);
      }
    }
    ans += 1;
    cout << ans << '\n';
  }
  return 0;
}