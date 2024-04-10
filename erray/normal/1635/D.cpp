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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, P;
  cin >> N >> P;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  vector<Mint> ways(P);
  ways[0] = 1;
  for (int i = 0; i < P; ++i) {
    if (i + 1 < P) {
      ways[i + 1] += ways[i];
    } 
    if (i + 2 < P) {
      ways[i + 2] += ways[i];
    }
  }
  for (int i = 0; i < P - 1; ++i) {
    ways[i + 1] += ways[i];
  }

  sort(A.begin(), A.end());
  Mint ans = 0;
  for (auto e : A) {
    int x = e;
    bool ok = true;
    while (x > 0) {
      if (x % 2 == 1) {
        x /= 2;
      } else if (x % 4 == 0) {
        x /= 4;
      } else {
        break;
      }
      ok &= !binary_search(A.begin(), A.end(), x);
    }
    if (ok && __lg(e) < P) {
      ans += ways[P - __lg(e) - 1];
    }
  }
  cout << ans() << '\n';
}