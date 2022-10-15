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

    const long long INF = (long long) 1e16;
    long long ans = 0;
    for (int right = 0; right < 2; ++right) {
      debug(right);
      vector<long long> suf(N + 1);
      for (int i = N - 1 - (N % 2 == right); i >= 0; --i) {
        suf[i] = A[i] - suf[i + 1];
      }
      debug(suf);

      array<vector<long long>, 2> es;
      array<SparseTable<long long>, 2> mn;
      es[0] = es[1] = vector<long long>(N, INF);
      for (int i = 0; i < N; ++i) {
        es[i % 2][i] = suf[i];   
      }

      for (int j = 0; j < 2; ++j) {
        mn[j] = SparseTable<long long>(es[j], [&](auto x, auto y) {
          return min(x, y);
        });
      }

      array<map<long long, vector<int>>, 2> pos;
      auto Range = [&](int x, int mx, long long need) {
        auto& v = pos[x][need];
        return int(v.size()) - int(lower_bound(v.begin(), v.end(), mx) - v.begin());
      };

      long long res = 0;
      for (int i = 0; i < N; ++i) {
        pos[i % 2][suf[i]].push_back(i);
        if (i % 2 != right) {
          continue;
        }
        int left = -1;
        {
          int low = 0, high = i;
          while (low < high) {
            int mid = (low + high) >> 1;
            if (min(mn[right].get(mid, i) + suf[i + 1], mn[right ^ 1].get(mid, i) - suf[i + 1]) >= 0) {
              high = mid;
            } else {
              low = mid + 1;
            }
          }
          left = low;        
        }
        long long del = suf[i + 1];
        ans += Range(right, left, -del) + Range(right ^ 1, left, del);
      }

      
      ans += res;
      debug(res);
    }
  
    cout << ans << '\n';
  }
}