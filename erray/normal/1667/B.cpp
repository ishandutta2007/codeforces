// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

const int inf = int(1e9);
struct fenwick {
  vector<int> tree;
  int n;
  fenwick(int _n) : n(_n) {
    tree.resize(n + 1, -inf);
  }
  int get(int x) {
    x += 1;
    int res = -inf;
    while (x > 0) {
      res = max(res, tree[x]);
      x -= x & -x;
    }
    return res;
  }
  void modify(int x, int v) {
    x += 1;
    while (x <= n) {
      tree[x] = max(tree[x], v);
      x += x & -x;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    vector<long long> pref(N + 1);
    for (int i = 0; i < N; ++i) {
      pref[i + 1] = pref[i] + A[i];
    }
    auto c = pref;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    vector<int> id(N + 1);
    for (int i = 0; i <= N; ++i) {
      id[i] = int(lower_bound(c.begin(), c.end(), pref[i]) - c.begin());
    }
    debug(id);

    fenwick pos(N + 1);
    fenwick neg(N + 1);   
    vector<int> zero(N + 1, -inf);
    vector<int> dp(N + 1);
    for (int i = 0; i <= N; ++i) {
      int x = id[i];
      int inv_x = N - x;
      dp[i] = max({zero[x], -i + neg.get(inv_x), i + (x == 0 ? -inf : pos.get(x - 1))});
      if (i == 0) {
        dp[i] = 0;  
      }
      pos.modify(x, dp[i] - i);
      neg.modify(inv_x, dp[i] + i);
      zero[x] = dp[i];
    }
    debug(dp);
    cout << dp[N] << '\n';
  }
}