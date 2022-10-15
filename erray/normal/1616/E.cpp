// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

struct fenwick {
  vector<int> tree;
  int n;
  fenwick(int _n) : n(_n) {
    tree.resize(n + 1);
  }

  int get(int x) {
    x += 1;
    int res = 0;
    while (x > 0) {
      res += tree[x];
      x = x & (x - 1);
    }
    return res;
  }
  void modify(int x, int d) {
    x += 1;
    while (x <= n) {
      tree[x] += d;
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
    string S, T;
    cin >> N >> S >> T;
    auto s = S;
    sort(s.begin(), s.end());
    if (s >= T) {
      cout << -1 << '\n';
      continue;
    }

    array<vector<int>, 26> pos;
    for (int i = N - 1; i >= 0; --i) {
      pos[S[i] - 'a'].push_back(i);
    }
    
    debug(pos);
    fenwick f(N);
    for (int i = 0; i < N; ++i) {
      f.modify(i, +1);
    }
    long long ans = 1LL * N * N;
    long long cur = 0;
    for (int i = 0; i < N; ++i) {
      if (T[i] != 'a') {
        int best = N;
        for (int j = 0; 'a' + j < T[i]; ++j) {
          if (!pos[j].empty()) {
            best = min(best, pos[j].back());
          }
        }
        if (best != N) {
          ans = min(ans, cur + f.get(best) - 1);        
        }
      }

      if (pos[T[i] - 'a'].empty()) {
        break;
      }
      int x = pos[T[i] - 'a'].back();
      f.modify(x, -1);
      cur += f.get(x);
      pos[T[i] - 'a'].pop_back();
    }
    cout << ans << '\n';
  }
}