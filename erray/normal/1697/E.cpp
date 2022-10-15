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
  cin >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
  }

  vector<vector<int>> d(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      d[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
    }
  }

  vector<vector<int>> can(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    iota(can[i].begin(), can[i].end(), 0);
    sort(can[i].begin(), can[i].end(), [&](int x, int y) {
      return d[i][x] < d[i][y];
    });
    while (d[i][can[i][1]] < d[i][can[i].back()]) {
      can[i].pop_back();
    }
    sort(can[i].begin(), can[i].end());
  }

  vector<Mint> dp(N + 1);
  dp[0] = 1;
  vector<bool> skip(N);
  for (int i = 0; i < N; ++i) {
    if (skip[i]) {
      continue;
    }
    bool based = true;
    for (auto u : can[i]) {
      based &= (can[u] == can[i]);
    }
    if (based) {
      int s = int(can[i].size());
      for (auto u : can[i]) {
        skip[u] = true;
      }
      for (int j = N - 1; j >= 0; --j) {
        dp[j + 1] += dp[j];
        if (j + s <= N) {
          dp[j + s] += dp[j];
        }
        dp[j] = 0;
      }
    } else {
      //Karinc :thumbsdown:
      for (int j = N - 1; j >= 0; --j) {
        dp[j + 1] = dp[j];
      }
      dp[0] = 0;
    }
  }

  vector<Mint> fact(N + 1), inv_fact(N + 1);
  fact[0] = inv_fact[0] = 1;
  for (int i = 0; i < N; ++i) {
    fact[i + 1] = fact[i] * (i + 1);
  }
  inv_fact[N] = 1 / fact[N];
  for (int i = N - 1; i > 0; --i) {
    inv_fact[i] = inv_fact[i + 1] * (i + 1);
  }
  auto C = [&](int n, int k) -> Mint {
    assert(k >= 0);
    if (k > n) {
      return 0;
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
  };

  Mint ans = 0;
  for (int i = 0; i <= N; ++i) {
    ans += C(N, i) * fact[i] * dp[i]; 
  }
  cout << ans << '\n';
}