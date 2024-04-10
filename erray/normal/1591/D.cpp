// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

template<typename T> struct fenwick {
  vector<T> tree;
  int n;
  fenwick(int _n) : n(_n) {
    tree.resize(n + 1);
  }
  
  T get(int x) {
    x += 1;
    T res = 0;
    while (x > 0) {
      res += tree[x];
      x = x & (x - 1);
    }
    return res;
  }

  void modify(int x, T y) {
    x += 1;
    while (x <= n) {
      tree[x] += y;
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
      --A[i];
    }
    fenwick<int> fenw(N);
    int res = 0;
    for (int i = N - 1; i >= 0; --i) {
      res += fenw.get(A[i]);
      fenw.modify(A[i], +1);
    }
    if (res % 2 == 0 || int(set<int>(A.begin(), A.end()).size()) != N) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}