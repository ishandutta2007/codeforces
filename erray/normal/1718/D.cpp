// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> 
struct SparseTable {
  vector<vector<T>> a;
  int n;
  F op;
  SparseTable() { }
  SparseTable(vector<T> _a, F _op) : op(_op) {
    n = int(_a.size());
    int lg = 32 - __builtin_clz(n);
    a.resize(lg); 
    a[0] = _a;
    for (int j = 1; j < lg; ++j) {
      int size = n - (1 << j) + 1;
      a[j].resize(size);
      for (int i = 0; i < size; ++i) {
        a[j][i] = op(a[j - 1][i], a[j - 1][i + ((1 << (j - 1)))]);
      }
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int lg = __lg(r - l + 1);
    return op(a[lg][l], a[lg][r + 1 - (1 << lg)]);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i];
      --P[i];
    }
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      --A[i];
    }
    int K = count(A.begin(), A.end(), -1);
    vector<int> S(K - 1);
    for (int i = 0; i < K - 1; ++i) {
      cin >> S[i];
      --S[i];
    }
    vector<int> foo(N);
    iota(foo.begin(), foo.end(), 0);
    SparseTable mxP(foo, [&](int x, int y) {
      return P[x] > P[y] ? x : y;
    });
    SparseTable mxA(A, [&](int x, int y) {
      return max(x, y);
    });
              
    vector<array<int, 2>> ranges;
    bool ok = true;
    function<void(int, int, int)> Add = [&](int l, int r, int high) {
      if (l > r) {
        return;
      }                    
      debug(l, r, high);
      int i = mxP.get(l, r);
      int low = mxA.get(l, r);
      if (A[i] != -1) {
        high = A[i];
        ok &= low == A[i];
      } else {
        ranges.push_back({low + 1, high - 1});
        ok &= (low + 1 <= high - 1);
      }
      Add(l, i - 1, high);
      Add(i + 1, r, high);
    };
    Add(0, N - 1, int(1e6));
    debug(ranges);
    int R = -1;
    {
      sort(ranges.begin(), ranges.end(), [&](auto x, auto y) {
        return x[1] < y[1];
      }); 
      set<int> st(S.begin(), S.end());
      for (auto[l, r] : ranges) {
        auto it = st.lower_bound(l);
        if (it == st.end() || *it > r) {
          if (R == -1) {
            R = r;
          } else {
            ok = false;
            break;
          }
        } else {
          st.erase(it);
        }
      }
    }
    int L = -1;
    {
      sort(ranges.rbegin(), ranges.rend());
      set<int> st(S.begin(), S.end());
      for (auto[l, r] : ranges) {
        auto it = st.lower_bound(r + 1);
        if (it == st.begin() || *prev(it) < l) {
          if (L == -1) {
            L = l;
          } else {
            ok = false;
            break;
          }
        } else {
          st.erase(prev(it));
        }
      }  
    }
    debug(L, R);
    while (Q--) {
      int D;
      cin >> D;
      --D;
      cout << (L <= D && D <= R && ok ? "YES" : "NO") << '\n';
    }
  }
}