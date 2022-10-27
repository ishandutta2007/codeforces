// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

constexpr int md = 998244353;
struct Mint {
  int val = 0;  
  Mint() : val{} {}
  template<typename T> Mint(T x) {
    if (x >= -md && x < md) {
      val = x;
    } else {
      val = x % md;
    }
    if (val < 0) {
      val += md;
    }
  }
  int& operator()() { return val; }
  Mint& operator+=(Mint x) {
    if ((val += x.val) >= md) {
      val -= md;
    }
    return *this;
  }
  Mint& operator-=(Mint x) {
    if ((val -= x.val) < 0) {
      val += md;
    }
    return *this;
  }
  Mint& operator*=(Mint x) {
    val = int((1LL * val * x.val) % md);      
    return *this;
  }
};
template<typename T> Mint power(Mint x, T p) {
  Mint res = 1;
  while (p > 0) {
    if (p & 1) {
      res *= x;
    }
    x *= x;
    p >>= 1;
  }
  return res;
}
Mint& operator/=(Mint& x, Mint y) {
  return x *= power(y, md - 2);
}

Mint operator+(Mint x, Mint y) {
  return x += y;
}
Mint operator-(Mint x, Mint y) {
  return x -= y;
}
Mint operator*(Mint x, Mint y) {
  return x *= y;
}
Mint operator/(Mint x, Mint y) {
  return x /= y;
}
string to_string(Mint x) {
  return to_string(x());
}
ostream& operator<<(ostream& out, Mint x) {
  return out << x();
}

using mat = array<array<Mint, 2>, 2>;

mat operator*(mat x, mat y) {
  mat res = {};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        res[i][j] += x[i][k] * y[k][j];
      }
    }
  }
  return res;
}

struct SegTree {
  vector<mat> tree;
  int n;
  SegTree(int _n) : n(_n) {
    tree.resize(n * 2, {});
  }
  mat get() {
    mat resL = {}, resR = {};
    resL[0][0] = resL[1][1] = resR[0][0] = resR[1][1] = 1;
    for (int l = n, r = 2 * n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        resL = resL * tree[l++]; 
      } 
      if (r & 1) {
        resR = tree[--r] * resR;
      }
    }
    return resL * resR;
  }
  void modify(int p, mat t) {
    tree[p += n] = t;
    while (p > 1) {
      p >>= 1;
      tree[p] = tree[p << 1] * tree[p << 1 | 1];
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> L(N), R(N);
  for (int i = 0; i < N; ++i) {
    cin >> L[i] >> R[i];
  }
  int mx = *max_element(R.begin(), R.end()) + 2;
  vector<vector<int>> upd(mx);  
  for (int i = 0; i < N; ++i) {
    upd[L[i]].push_back(i);
    upd[R[i] + 1].push_back(~i);
  }
  using what_the_fuck_is_this_bullshit = array<Mint, 2>;
  mat mat_false = mat{what_the_fuck_is_this_bullshit{3, 0}, what_the_fuck_is_this_bullshit{1, 2}};
  mat mat_true = mat{what_the_fuck_is_this_bullshit{1, 2}, what_the_fuck_is_this_bullshit{1, 2}};
  SegTree st(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    st.modify(i, mat_false);
  }
  Mint ans = 0;
  int start = 0;
  for (int i = 0; i < mx; ++i) {
    for (auto id : upd[i]) {
      debug(i, id);
      if (id == 0 || ~id == 0) {
        start ^= 1; 
      } else if (id >= 0) {
        st.modify(id - 1, mat_true); 
      } else {
        st.modify(~id - 1, mat_false);
      }
    } 
    ans += st.get()[start][1];
  }
  cout << ans << '\n';
}