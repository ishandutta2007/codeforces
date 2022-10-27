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
  int N;
  long long M;
  cin >> N >> M;
  Mint bad = M;
  Mint cur = M;
  Mint pw = M;
  Mint tot = M;
  long long d = 1;
  vector<bool> ip(N + 1, true);
  for (int i = 2; i <= N; ++i) {
    if (ip[i] && d <= M) {
      d *= i;
      for (int j = i * 2; j <= N; j += i) {
        ip[j] = false;
      }
    }
    cur *= M / d;
    bad += cur;
    pw *= M;
    tot += pw;
  }
  cout << tot - bad << '\n';
}