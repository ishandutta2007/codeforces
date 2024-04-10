// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct DSU {
  vector<int> link;
  DSU(int n) {
    link.resize(n);
    iota(link.begin(), link.end(), 0);
  }

  int get(int v) {
    return link[v] = (v == link[v] ? v : get(link[v]));
  }

  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    link[y] = x;
    return true;
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
    vector<int> C(N), L(N), R(N);
    for (int i = 0; i < N; ++i) {
      cin >> C[i] >> L[i] >> R[i];
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x, int y) {
      return L[x] < L[y];
    });

    array<priority_queue<pair<int, int>>, 2> segs;  
    vector<vector<int>> furt(2, vector<int>(N, -1));
    for (int i = 0; i < N; ++i) {
      furt[C[i]][i] = R[i];
    }
    DSU d(N);
    for (auto i : ord) {    
      while (!segs[C[i] ^ 1].empty() && segs[C[i] ^ 1].top().first >= L[i]) {
        auto[foo, id] = segs[C[i] ^ 1].top();
        segs[C[i] ^ 1].pop();
        id = d.get(id);
        int x = d.get(i);
        for (int j = 0; j < 2; ++j) {
          furt[j][id] = max(furt[j][id], furt[j][x]);
        }
        d.unite(id, i);
      }
      for (int j = 0; j < 2; ++j) {
        segs[j].emplace(furt[j][d.get(i)], d.get(i));
      }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += d.get(i) == i;
    }
    cout << ans << '\n';
  }
}