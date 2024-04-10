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
  int N;
  string S;
  cin >> N >> S;
  int Q;
  cin >> Q;
  vector<int> T(Q);
  for (int  i = 0; i < Q; ++i) {
    string foo;
    cin >> foo;
    for (char c : foo) {
      T[i] |= 1 << (c - 'a');
    }
  }
  vector<Mint> ans(Q);
  int n = 18;
  for (int len = 1; len < n; ++len) {
    vector<Mint> dp(1 << n);
    vector<Mint> pw(N + 1, 1);
    for (int i = 0; i < N; ++i) {
      pw[i + 1] = pw[i] * len;
    }
    int tot = count(S.begin(), S.end(), '?');
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 2; ++j) {
        int l = i;
        int r = i + j;
        int mask = 0;
        int fix = 0;
        while (l >= 0 && r < N && (S[l] == '?' || S[r] == '?' || S[l] == S[r])) {
          if (S[l] != S[r]) {
            mask |= 1 << (S[S[l] == '?' ? r : l] - 'a');
          }
          if ((S[l] == '?' || S[r] == '?') && l != r) {
            fix += 1;
          }
          --l, ++r;
          dp[mask] += pw[tot - fix];
        }
      }
    }

    for (int b = 1; b < (1 << n); b <<= 1) {
      for (int i = 0; i < (1 << n); ++i) {
        if (~i & b) {
          dp[i | b] += dp[i];
        }
      }
    }
    for (int i = 0; i < Q; ++i) {
      if (__builtin_popcount(T[i]) == len) {
        ans[i] = dp[T[i]];
      }
    }
  }

  for (int i = 0; i < Q; ++i) {
    cout << ans[i] << '\n';
  }
}