// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

const long long inf = (long long) 4e18;
struct fenwick {
  vector<long long> mn;
  int n;
  fenwick(int _n) : n(_n) {
    mn.resize(n + 1, inf);
  }

  long long get(int x) {
    x += 1;
    long long res = inf;
    while (x > 0) {
      res = min(res, mn[x]);
      x -= x & -x;
    }
    return res;
  }

  void modify(int x, long long add) {
    x += 1;
    while (x <= n) {
      mn[x] = min(mn[x], add);
      x += x & -x;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<int> X(N), W(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> W[i];
  }

  vector<vector<int>> add(N);
  {
    stack<int> st;
    for (int i = 0; i < N; ++i) {
      while (!st.empty() && W[st.top()] > W[i]) {
        st.pop();
      }
      if (!st.empty()) {
        add[i].push_back(st.top());
      }
      st.push(i);
    }
  }
  
  {
    stack<int> st;
    for (int i = N - 1; i >= 0; --i) {
      while (!st.empty() && W[st.top()] > W[i]) {
        st.pop();
      }
      if (!st.empty()) {
        add[st.top()].push_back(i);
      }
      st.push(i);
    }
  }
  debug(add);
  vector<vector<array<int, 2>>> qs(N);
  for (int i = 0; i < Q; ++i) {
    int L, R;
    cin >> L >> R;
    --L, --R;
    qs[R].push_back({L, i});
  }
  vector<long long> ans(Q);
  fenwick fenw(N);
  for (int i = 0; i < N; ++i) {
    for (auto e : add[i]) {
      fenw.modify(N - e - 1, 1LL * abs(X[i] - X[e]) * (W[i] + W[e]));  	 
    }
    for (auto[l, id] : qs[i]) {
      ans[id] = fenw.get(N - l - 1);
    }
  }
  for (auto e : ans) {
    cout << e << '\n';
  }
}