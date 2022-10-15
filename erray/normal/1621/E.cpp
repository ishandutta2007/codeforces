// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> 
struct SparseTable {
  vector<vector<T>> a;
  vector<int> logs;
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
    logs.resize(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
      logs[i] = logs[(i >> 1)] + 1;
    }
  }
  T get(int l, int r) {
    assert(l >= 0 && r < n && l <= r);
    int lg = logs[r - l + 1];;
    return op(a[lg][l], a[lg][r + 1 - (1 << lg)]);
  }
};


struct fract {
  long long t = 0, b = 1;
  fract() : t(0), b(1) { }
  fract(long long _t, long long _b = 1) : t(_t), b(_b) { }
  bool operator<(const fract& ot) {
    return ot.b * t < b * ot.t;
  }
};

string to_string(fract x) {
  return to_string(x.t) + "/" + to_string(x.b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    sort(A.begin(), A.end());
    A.erase(A.begin(), A.begin() + (N - M));
    N = M;
    vector<vector<int>> B(M);  
    vector<int> K(M);
    vector<pair<fract, int>> val(M);
    vector<int> ss(M + 1);
    for (int i = 0; i < M; ++i) {
      cin >> K[i];
      ss[i + 1] = ss[i] + K[i];
      B[i].resize(K[i]);	
      for (int j = 0; j < K[i]; ++j) {
        cin >> B[i][j];
        val[i].first.t += B[i][j];
      }
      val[i].first.b = K[i];
      val[i].second = i;
    }

    sort(val.begin(), val.end(), [&](auto x, auto y) {
      return x.first < y.first;
    });
    debug(A, val);

    vector<int> diff(N);
    for (int i = 0; i < N; ++i) {
      int low = -1, high = M - 1;
      while (low < high) {
        int mid = 1 + ((low + high) >> 1);
        if (fract(A[i]) < val[mid].first) {
          high = mid - 1;
        } else {
          low = mid;
        }
      }
      diff[i] = low - i;
    }
    debug(diff);

    string ans(ss[M], '0');
    SparseTable st(diff, [&](int x, int y) {
      return min(x, y);
    });

    for (int i = 0; i < N; ++i) {
      int id = val[i].second;
      for (int j = 0; j < K[id]; ++j) {
        long long sum = val[i].first.t - B[id][j];
        int size = K[id] - 1;
        int low = 0, high = N;
        while (low < high) {
          int mid = (low + high) >> 1;
          if (fract(A[mid]) < fract(sum, size)) {
            low = mid + 1; 
          } else {
            high = mid;
          }
        }
        if (low != N) {
          int old = i;
          int nw = low;
          int l = old;
          int r = nw;
          if (l > r) {
            swap(l, r);
          }
          bool ok = (l == 0 || (st.get(0, l - 1) >= 0)) && (r == N - 1 || (st.get(r + 1, N - 1) >= 0));
          ok &= (old == nw || (old < nw ? (st.get(old, nw - 1) >= 1) : (st.get(nw + 1, old) >= -1)));          
          ans[ss[id] + j] = '0' + ok;
        }
      }  
    }
    cout << ans << '\n';
  }          
}