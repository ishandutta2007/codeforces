#undef DEBUG 
// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct fenwick {
  vector<long long> sum;
  int n;
  fenwick(int _n) : n(_n) {
    sum.resize(n + 1, 0);
  }
  long long get(int x) {
    x += 1;
    long long res = 0;
    while (x > 0) {
      res += sum[x];
      x -= x & -x;
    }
    return res;
  }
  void modify(int x, long long v) {
    x += 1;
    while (x <= n) {
      sum[x] += v;
      x += x & -x;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  vector<int> L(T), R(T);
  for (int i = 0; i < T; ++i) {
    cin >> L[i] >> R[i];
  }

  const int MAX = (*max_element(R.begin(), R.end())) + 1;
  vector<vector<int>> divs(MAX * 2);
  for (int i = MAX * 2; i >= 1; --i) {
    for (int j = i * 2; j < MAX * 2; j += i) {
      divs[j].push_back(i);
    }
  }
  debug(divs);
  vector<vector<int>> qs(MAX);
  for (int i = 0; i < T; ++i) {
    qs[R[i]].push_back(i);
  }
  fenwick fw(MAX);
  vector<long long> ans(T);
  auto C = [&](int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; ++i) {
      res *= n - i;
      res /= (i + 1);
    }
    return res;
  };
  for (int i = 1; i < MAX; ++i) {
    debug(i);
    for (int j = 0; j < int(divs[i].size()); ++j) {
      debug(divs[i][j], C(j + 1, 2) - C(j, 2));
      fw.modify(divs[i][j], C(j + 1, 2) - C(j, 2));
    }
    if (i % 3 == 0) {
      int big = i / 3 * 2;
      for (auto d : divs[i * 2]) {
        if (d < big && d + big > i) {
          fw.modify(d, +1);
          debug("UPD", d);
        }   
      } 
    }
    for (auto id : qs[i]) {
      debug(id, fw.get(i), fw.get(L[id] - 1));
      ans[id] = C(R[id] - L[id] + 1, 3) - (fw.get(i) - fw.get(L[id] - 1));
    }
  }
  for (int i = 0; i < T; ++i) {
    cout << ans[i] << '\n';
  }
}