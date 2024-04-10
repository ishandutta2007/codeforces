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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    vector<int> R(Q), C(Q);
    for (int i = 0; i < Q; ++i) {
      cin >> R[i] >> C[i];
      --R[i], --C[i];
    }
    Mint ans = 1;
    vector<bool> vis_r(N);
    vector<bool> vis_c(M);
    int c_r = 0;
    int c_c = 0;
    for (int i = Q - 1; i >= 0; --i) {
      if (vis_r[R[i]] && vis_c[C[i]]) {
        continue;
      }
      ans *= K;
      c_r += !vis_r[R[i]];
      c_c += !vis_c[C[i]];
      vis_r[R[i]] = true;
      vis_c[C[i]] = true;
      if (c_r == N || c_c == M) {
        break;
      }       	
    }
    cout << ans() << '\n';
  }
}