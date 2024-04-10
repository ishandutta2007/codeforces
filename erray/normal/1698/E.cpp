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
  int TT;
  cin >> TT;
  while (TT--) {
    int N, S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      --A[i];
    }
    vector<int> p(N, -1);
    vector<bool> b(N);
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
      if (B[i] != -1) {
        --B[i];
        p[B[i]] = A[i];
        b[A[i]] = true;
      }
    }

    debug(p);
    debug(b);
    Mint ans = 1;
    bool ok = true;
    int c = 0;
    for (int i = 0; i < S; ++i) {
      c += !b[i];
    }
    int used = 0;
    for (int i = 0; i < N; ++i) {
      c += (i + S < N && !b[i + S]);
      if (p[i] != -1) {
        ok &= (p[i] - i <= S);
      } else {
        debug(c, used);
        ans *= max(0, c - used);
        used += 1;
      }
    }

    if (!ok) {
      ans = 0;
    }
    cout << ans << '\n';
  }
}