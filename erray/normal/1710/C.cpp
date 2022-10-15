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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string N;
  cin >> N;
  array<int, 8> xr = {};      
  for (int m = 0; m < 8; ++m) {
    int b = 0;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < i; ++j) {
        xr[m] |= ((m >> i & 1) ^ (m >> j & 1)) << b; 
        b += 1;
      }
    }
    xr[m] >>= 1;
    xr[m] -= 1;
  }

  //reverse(N.begin(), N.end()); I'm a fucking moron
  array<array<Mint, 8>, 8> dp = {};
  dp[0][0] = 1;
  for (char c : N) {
    debug(c, dp);
    array<array<Mint, 8>, 8> new_dp = {};
    for (int m = 0; m < 8; ++m) {
      for (int n = 0; n < 8; ++n) {
        if ((n & (7 ^ m)) > 0 && c == '0') {
          continue;
        }   
        int next = m | (c == '0' ? 0 : (7 ^ n));
        int add = (xr[n] == -1 ? 0 : 1 << xr[n]);
        for (int x = 0; x < 8; ++x) {
          new_dp[next][x | add] += dp[m][x];
        }
      }
    }  
    swap(dp, new_dp);
  }
  Mint ans = 0;
  for (int i = 0; i < 8; ++i) {
    ans += dp[i][7];
  }
  cout << ans << '\n';
}