// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

//you can define md with template or inside the struct for other uses 
constexpr int md = int(1e9) + 7;
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
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      --A[i];
    }
    DSU d(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
      --B[i];
      d.unite(A[i], B[i]);
    }
    
    vector<bool> bad(N);
    for (int i = 0; i < N; ++i) {
      cin >> C[i];
      --C[i];
      if (C[i] != -1) {
        bad[d.get(A[i])] = true;
      }
    }

    vector<int> size(N);
    for (int i = 0; i < N; ++i) {
      size[d.get(i)] += 1;
    }
    Mint ans = 1;
    for (int i = 0; i < N; ++i) {
      if (!bad[i] && d.get(i) == i && size[i] != 1) {
        ans *= 2;
      }
    }
    cout << ans << '\n';
  }
}