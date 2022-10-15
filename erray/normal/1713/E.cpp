// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

struct DSU {
  vector<vector<int>> s;
  vector<int> link;
  int n;
  DSU(int _n) : n(_n) {
    link.resize(n * 2);
    iota(link.begin(), link.end(), 0);
  }
  int get(int v) {
    return link[v] = (link[v] == v ? v : get(link[v]));
  }
  bool same(int x, int y) {
    return get(x) == get(y);
  }
  int inv(int x) {
    return x + (x >= n ? -1 : 1) * n; 
  }
  void Link(int x, int y) {
    x = get(x), y = get(y);
    link[y] = x;
  }
  bool unite(int x, int y, bool v) {
    if (v) {
      x = inv(x);
    }
    if (same(x, y)) {
      return true;
    }
    if (same(inv(x), y)) {
      return false;
    }
    Link(x, y);
    Link(inv(x), inv(y));
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
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> A[i][j];
      }
    }                                
    DSU d(N);
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        int mn = min(A[i][j], A[j][i]);
        int mx = A[i][j] ^ A[j][i] ^ mn;
        if (A[i][j] == A[j][i] || d.unite(i, j, A[i][j] > A[j][i])) {
          A[i][j] = mn, A[j][i] = mx;
        } else {
          A[i][j] = mx, A[j][i] = mn;
        }
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << A[i][j] << " \n"[j == N - 1];
      }
    }
  }
}