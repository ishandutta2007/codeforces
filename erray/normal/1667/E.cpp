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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<Mint> fact(N + 1);
  vector<Mint> inv_fact(N + 1);
  fact[0] = 1;
  for (int i = 0; i < N; ++i) {
    fact[i + 1] = fact[i] * (i + 1);
  }
  inv_fact[N] = 1 / fact[N];
  for (int i = N; i > 0; --i) {
    inv_fact[i - 1] = inv_fact[i] * i;
  }
  auto C = [&](int n, int r) -> Mint {
    assert(r >= 0 && n <= N);
    if (r > n) {
      return 0;
    }
    return fact[n] * inv_fact[r] * inv_fact[n - r];
  };

  vector<Mint> ans(N);
  Mint sum = 0;      
  for (int i = N - 1; i >= 0; --i) {
    int l = N - i - 1;
    Mint p = (i > N / 2 ? 0 : C(l - (N + 1) / 2 + 1 + i, i) / C(l + i, i));
    ans[i] = p - sum;
    sum += p / max(i, 1);
  }
  for (int i = 0; i < N; ++i) {
    cout << ans[i] * fact[N - 1] << " \n"[i == N - 1];
  }
}