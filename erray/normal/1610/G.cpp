// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

constexpr int m1 = int(1e9 + 7);
constexpr int m2 = 998244053;
vector<int> pw1;
vector<int> pw2;

struct Hash {
  int h1 = 0;
  int h2 = 0;
  int size = 0;
  
  Hash(char c) {
    h1 = h2 = (c == ')') + 1;
    size = 1;
  }

  Hash() { }

  Hash operator+(Hash& ot) {
    Hash res;
    res.h1 = (h1 + (1LL * pw1[size] * ot.h1)) % m1;
    res.h2 = (h2 + (1LL * pw2[size] * ot.h2)) % m2;      
    res.size = size + ot.size;
    return res;
  }
};

bool operator==(Hash x, Hash y) {
  return x.h1 == y.h1 && x.h2 == y.h2;
}

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
  string S;
  cin >> S;
  int N = int(S.size());
  S += '$';
  pw1.resize(N + 1, 1);
  pw2.resize(N + 1, 1);
  for (int i = 0; i < N; ++i) {
    pw1[i + 1] = pw1[i] * 3;
    pw2[i + 1] = pw2[i] * 3;
  }

  const int LG = __lg(N) + 1;
  vector<vector<int>> up(LG, vector<int>(N + 1));
  vector<vector<Hash>> val(LG, vector<Hash>(N + 1));
  vector<int> d(N + 1);
  for (int i = 0; i < LG; ++i) {
    up[i][N] = N;
  }

  vector<bool> use(N, true);
  auto Link = [&](int x, int pr) {
    up[0][x] = pr;
    d[x] = d[pr] + 1;
    for (int j = 1; j < LG; ++j) {
      up[j][x] = up[j - 1][up[j - 1][x]];
      val[j][x] = val[j - 1][up[j - 1][x]] + val[j - 1][x];    
    }
  };

  auto Cmp = [&](int x, int y) {
    Hash hx;
    Hash hy;
    for (int j = LG - 1; j >= 0 && x != N && y != N; --j) {
      if (min(d[x], d[y]) >= (1 << j) && hx + val[j][x] == hy + val[j][y]) {
        hx = hx + val[j][x];
        hy = hy + val[j][y];
        x = up[j][x];
        y = up[j][y];
      }
    }

    return (x == N ? -1 : val[0][x].h1) < (y == N ? -1 : val[0][y].h1);  
  };

  vector<int> pref(N + 1);
  for (int i = 0; i < N; ++i) {
    pref[i + 1] = pref[i] + (S[i] == '(' ? +1 : -1);
  }

  debug(pref);

  SparseTable st(pref, [&](auto x, auto y) {
    return min(x, y);
  });

  map<int, int> mp;
  vector<int> linked(N + 1);
  iota(linked.begin(), linked.end(), 0);
  for (int i = N - 1; i >= 0; --i) {
    val[0][i] = Hash(S[i]);
    Link(i, linked[i + 1]);  
    if (mp.count(pref[i])) {
      int l = mp[pref[i]];
      if (st.get(i, l) == pref[i] && Cmp(linked[l], i)) {
        linked[i] = linked[l];
      }
    }
    mp[pref[i + 1]] = i + 1;
  }
  debug(up[0]);

  string res;
  int p = 0;
  while (p < N) {
    res += S[p];
    p = linked[up[0][p]];
  }
  cout << res << '\n';
}