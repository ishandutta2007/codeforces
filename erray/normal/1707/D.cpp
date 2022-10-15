// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int md;
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
  cin >> N >> md;
  vector<vector<int>> g(N);  
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  vector<vector<Mint>> dp(N, vector<Mint>(N));
  function<void(int)> Dfs = [&](int v) {
    int s = int(g[v].size());
    vector<vector<Mint>> pref(s + 1, vector<Mint>(N, 1));
    vector<vector<Mint>> suf(s + 1, vector<Mint>(N, 1));
    for (auto u : g[v]) {
      g[u].erase(find(g[u].begin(), g[u].end(), v));
      Dfs(u);
    }
    for (int i = 0; i < s; ++i) {
      int u = g[v][i];
      Mint sum = 0;
      for (int j = 0; j < N; ++j) {
        sum += dp[u][j];
        pref[i + 1][j] = pref[i][j] * sum;
      }
    }
    for (int i = s - 1; i >= 0; --i) {
      int u = g[v][i];
      Mint sum = 0;
      for (int j = 0; j < N; ++j) {
        sum += dp[u][j];
        suf[i][j] = suf[i + 1][j] * sum;
      }
    }
    dp[v] = pref[s];
    if (v != 0) {
      vector<Mint> ways(s);
      for (int i = 0; i < N; ++i) {    
        debug(i, ways);
        for (int j = 0; j < s; ++j) {
          int u = g[v][j];
          dp[v][i] += ways[j] * dp[u][i];
        }
        for (int j = 0; j < s; ++j) {
          ways[j] += pref[j][i] * suf[j + 1][i];
        }
      }
    } 
  };
  Dfs(0);
  vector<vector<Mint>> C(N + 1, vector<Mint>(N + 1, 1));
  for (int i = 2; i <= N; ++i) {
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  auto ans = dp[0];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      ans[i] -= ans[j] * C[i + 1][j + 1];
    }
  }
  for (int i = 0; i < N - 1; ++i) {
    cout << ans[i] << " \n"[i == N - 2];
  }
}