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
ostream& operator<<(ostream& out, Mint& x) {
  return out << x();
}

vector<Mint> fac(1, 1), inv_fac(1, 1);

void fill_fac(int n) {
  while ((int) fac.size() <= n) {
    fac.push_back(fac.back() * (int) fac.size());
    inv_fac.push_back(1 / fac.back());
  }
}

Mint fact(int x) {
  assert(x >= 0);
  fill_fac(x);
  return fac[x];
}

bool reserve_fact(int n) {
  if (int(fac.size()) > n) {
   return false;
  }
  inv_fac.resize(n + 1);
  fac.resize(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i - 1] * i;
  }
  inv_fac[n] = 1 / fac[n];
  for (int i = n; i > 0; --i) {
    inv_fac[i - 1] = inv_fac[i] * i;
  }
  return false;
}

Mint C(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return fac[x] * inv_fac[y] * inv_fac[x - y];
}

Mint P(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return fac[x] * inv_fac[x - y];
}

Mint inverse_C(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return inv_fac[x] * fac[y] * fac[x - y];
}

Mint inverse_P(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return inv_fac[x] * fac[x - y];
}


struct fenwick {
  vector<Mint> tree;
  int n;
  fenwick(int _n) : n(_n) {
    tree.resize(n + 1, 0);
  }

  Mint get(int v) {
    v += 1;
    Mint res = 0;
    while (v > 0) {
      res += tree[v];
      v -= v & -v;
    }
    return res;
  }

  void modify(int v, Mint p) {
    v += 1;
    while (v <= n) {
      tree[v] += p;
      v += v & -v;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  reserve_fact(int(3e5));
  vector<Mint> inv(int(3e5) + 1);
  for (int i = 1; i <= int(3e5); ++i) {
    inv[i] = Mint(1) / i;
  }

  int N, M;
  cin >> N >> M;
  vector<int> S(N);
  int mx = 0;
  for (int i = 0; i < N; ++i) {
    cin >> S[i];
    --S[i];
    mx = max(mx, S[i]);
  }
  vector<int> T(M);
  for (int i = 0; i < M; ++i) {
    cin >> T[i];
    --T[i];
    mx = max(mx, T[i]);
  }

  mx += 1;
  vector<int> ct(mx);
  for (int i = 0; i < N; ++i) {
    ct[S[i]] += 1;
  }

  fenwick fenw(mx + 1);
  for (int i = 0; i < mx; ++i) {
    fenw.modify(i, ct[i]);
  }
  
  Mint ans = 0;
  Mint mul = 1;
  for (int i = 0; i < mx; ++i) {
    mul *= inv_fac[ct[i]];
  }

  for (int i = 0; i < M; ++i) {  
    int x = T[i];
    if (i == N - 1 && ct[x] == 1 && M > N) {
      ans += 1;
    }
    if (x > 0 && N - i - 1 >= 0) {
      Mint add = 0;
      add = mul * fenw.get(x - 1) * fac[N - i - 1]; 
      ans += add;
    }
    if (ct[x] == 0) {
      break;
    }
    mul *= ct[x]; 
    ct[x] -= 1;
    fenw.modify(x, -1);
  }
  cout << ans << '\n';
}