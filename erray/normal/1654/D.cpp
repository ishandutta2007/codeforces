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


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<vector<array<int, 3>>> g(N);
    for (int i = 0; i < N - 1; ++i) {
      int I, J, X, Y;
      cin >> I >> J >> X >> Y;
      --I, --J;
      int d = gcd(X, Y);
      X /= d;
      Y /= d;
      g[I].push_back({J, X, Y});
      g[J].push_back({I, Y, X});
    }

    vector<vector<int>> ps(N + 1);
    for (int i = 2; i <= N; ++i) {
      if (!ps[i].empty()) {
        continue;
      }
      for (int j = i; j <= N; j += i) {
        int x = j;
        while (x % i == 0) {
          ps[j].push_back(i);
          x /= i;
        }
      }
    }

    vector<int> ct(N + 1);
    vector<int> mx(N + 1);
    function<void(int)> Dfs = [&](int v) {
      for (auto[u, x, y] : g[v]) {
        g[u].erase(find(g[u].begin(), g[u].end(), array{v, y, x}));
        for (auto p : ps[x]) {
          ct[p] += 1;
          mx[p] = max(mx[p], ct[p]);
        }
        for (auto p : ps[y]) {
          ct[p] -= 1;
        }
        Dfs(u);
        for (auto p : ps[x]) {
          ct[p] -= 1;
        }
        for (auto p : ps[y]) {
          ct[p] += 1;
        }
      }
    };
    Dfs(0);

    vector<Mint> val(N);
    val[0] = 1;
    for (int i = 2; i <= N; ++i) {
      val[0] *= power(Mint(i), mx[i]);
    } 

    function<void(int)> E = [&](int v) {
      for (auto[u, x, y] : g[v]) {
        val[u] = val[v] / x * y;
        E(u);
      }
    };
    E(0);
    debug(val);
    cout << accumulate(val.begin(), val.end(), Mint(0))() << '\n';
  }
}