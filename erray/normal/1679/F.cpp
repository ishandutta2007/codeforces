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
  int N, M;
  cin >> N >> M;
  constexpr int n = 10;
  vector<int> good(n);
  for (int i = 0; i < M; ++i) {
    int V, U;
    cin >> V >> U;
    good[V] |= 1 << U;
    good[U] |= 1 << V;
  }

  array<Mint, 1 << n> dp{};
  dp[0] = 1;
  for (int it = 0; it < N; ++it) {
    array<Mint, 1 << n> new_dp{};
    for (int m = 0; m < (1 << n); ++m) {
      for (int i = 0; i < n; ++i) {
        if ((good[i] & m & ((1 << i) - 1)) == 0) {
          int new_m = (m & good[i]) | (1 << i);
          new_dp[new_m] += dp[m]; 
        } 
      }
    }
    swap(dp, new_dp);
  }
  cout << accumulate(dp.begin(), dp.end(), Mint(0)) << '\n';
}