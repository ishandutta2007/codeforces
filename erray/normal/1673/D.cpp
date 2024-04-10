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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int FB, DB, SB;
    cin >> FB >> DB >> SB;
    int FC, DC, SC;
    cin >> FC >> DC >> SC;
    auto Size = [&] {
      return (0LL + (SB - (FC - FB) / DB) + (DC / DB) - 1) / (DC / DB); 
    };

    if (DC % DB != 0 || FB > FC || (FC - FB) % DB != 0 || Size() < SC) {
      debug("NO", Size());
      cout << 0 << '\n';
      continue;
    }
    if (FC - DC < FB || Size() == SC) {
      debug(Size());
      cout << -1 << '\n';
      continue;
    } 
    vector<int> t;
    for (int i = 1; i * i <= DC; ++i) {
      if (DC % i == 0) {
        for (auto x : {i, DC / i}) {
          if (lcm(0LL + x, 0LL + DB) == DC) {
            t.push_back(x);
          } 
        }
      }
    }

    if (int(t.size()) > 1 && t.back() == t[int(t.size()) - 2]) {
      t.pop_back();
    }

    debug(t);
    Mint ans = 0;
    for (auto x : t) {
      ans += Mint(DC / x) * (DC / x);
    }    
    cout << ans << '\n';
  }
}