// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

//you can define md with template or inside the struct for other uses 
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

  Mint inv(Mint x) {
    int m = md - 2;
    Mint res = 1; 
    while (m > 0) {
      if (m & 1) {
        res *= x;
      }
      x *= x;
      m >>= 1;
    }  
    return res;
  }

  Mint& operator/=(Mint x) {
    return *this *= inv(x);
  }
};

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
ostream& operator<<(ostream& out, Mint x) {
  return out << x();
}

struct DSU {
  vector<int> par;
  DSU(int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }
  int get(int v) {
    return par[v] = (v == par[v] ? v : get(par[v]));
  }
  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    par[y] = x;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int R, C;
  cin >> R >> C;
  vector<string> B(R);
  for (int i = 0; i < R; ++i) {
    cin >> B[i];
  }

  if (R % 2 == 0 && C % 2 == 0) {
    int c = 0;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        c += B[i][j] == '?';
      }
    }
    cout << power(Mint(2), c) << '\n';
    return 0;
  }  
  
  if (R % 2 == 0 || C % 2 == 0) {
    vector<int> er(R), ec(C);
    vector<int> vr(R), vc(C);
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        if (B[i][j] == '?') {
          er[i] += 1;
          ec[j] += 1; 
        } else {
          vr[i] ^= (B[i][j] - '0');
          vc[j] ^= (B[i][j] - '0');
        }
      }
    }
    if (R % 2 == 1) {
      swap(er, ec);
      swap(vr, vc);
    }

    bool ok = true;
    int need = -1;
    Mint ans = 1;
    for (int i = 0; i < int(er.size()); ++i) {
      if (er[i] == 0) {
        ok &= need == -1 || need == vr[i];
        need = vr[i];
      } else {
        ans *= power(Mint(2), er[i] - 1);
      }
    }

    cout << (ok ? (need == -1 ? ans * 2 : ans) : 0) << '\n';
    return 0;
  }

  DSU d(R + C);
  vector<int> cur(R + C);
  vector<int> deg(R + C);
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (B[i][j] == '?') {
        d.unite(i, R + j);
        deg[i] += 1;
      } else {
        int x = B[i][j] - '0';
        cur[i] += x;
        cur[R + j] += x;
      }
    }
  }
  vector<int> ec(R + C);
  vector<int> size(R + C);
  vector<int> c(R + C);
  for (int i = 0; i < R + C; ++i) {
    ec[d.get(i)] += deg[i];
    size[d.get(i)] += 1;
    c[d.get(i)] += cur[i];
  }

  array<Mint, 2> ans = {1, 1};
  for (int i = 0; i < R + C; ++i) {
    if (d.get(i) == i) {
      Mint mul = power(Mint(2), ec[i] - size[i] + 1);
      ans[0] *= (c[i] % 2 == 0 ? mul : 0); 
      ans[1] *= ((size[i] - c[i]) % 2 == 0 ? mul : 0);
    }
  }
  cout << ans[0] + ans[1] << '\n';
}