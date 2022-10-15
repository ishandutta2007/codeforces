// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 template<typename A, typename B> string to_string(pair<A, B> p);
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t);
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t);

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(char c) {
  return string("'") + c + "'";
}

string to_string(const char* c) {
  return to_string(string(c));
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}

string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < int(v.size()); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& e : v) {
    if (int(res.size()) > 1) {
      res += ", ";
    }
    res += to_string(e);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(pair<A, B> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(tuple<A, B, C> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + '}';
}
template<typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + '}';
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << "  " << to_string(H);
  debug_out(T...);
}

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(37)
#endif
 
constexpr int md = 998244353;
struct Mint {
  int value;
  template<typename T> int normalize(T x) {
    int res;
    if (-md <= x && x < md) {
      res = int(x);
    } else {
      res = int(x % md);
    }
    if (res < 0) {
      res += md;
    }
    return res;
  }
  Mint() : value() { } 
  template<typename T>  Mint(T x) : value(normalize(x)) { }
  const int& operator()() const { return value; }   
  template <typename T> operator T() const { return static_cast<T>(value); }
  Mint inverse(Mint x) {
    int p = md - 2;
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
  
  Mint& operator+=(Mint x) {
    if ((value += x.value) >= md) {
      value -= md;
    }
    return *this;
  }
  Mint& operator-=(Mint x) {
    if ((value -= x.value) < 0) {
      value += md;
    }
    return *this;
  }
  Mint& operator*=(Mint x) {
    value = normalize(1LL * value * x.value);
    return *this;
  }
  Mint& operator/=(Mint x) {
    value = normalize(1LL * value * inverse(x).value);
    return *this;
  }
  template<typename T> Mint& operator+=(T x) {
    return *this += Mint(x);
  }
  template<typename T> Mint& operator-=(T x) {
    return *this -= Mint(x);
  }
  template<typename T> Mint& operator*=(T x) {
    return *this *= Mint(x);
  }
  template<typename T> Mint& operator/=(T x) {
    return *this /= Mint(x);
  }
  Mint operator-() {
    return Mint(-value);
  }
};

bool operator==(Mint x, Mint y) {
  return x.value == y.value;
}
template<typename T> bool operator==(Mint x, T y) {
  return x == Mint(y);
}
template<typename T> bool operator==(T x, Mint y) {
  return Mint(x) == y;
}

bool operator!=(Mint x, Mint y) {
  return x.value != y.value;
}
template<typename T> bool operator!=(Mint x, T y) {
  return x != Mint(y);
}
template<typename T> bool operator!=(T x, Mint y) {
  return Mint(x) != y;
}

Mint operator+(Mint x, Mint y) {
  return x += y;
}
template<typename T> Mint operator+(Mint x, T y) {
  return x += Mint(y);
}
template<typename T> Mint operator+(T x, Mint y) {
  return Mint(x) += y;
}

Mint operator-(Mint x, Mint y) {
  return x -= y;
}
template<typename T> Mint operator-(Mint x, T y) {
  return x -= Mint(y);
}
template<typename T> Mint operator-(T x, Mint y) {
  return Mint(x) -= y;
}

Mint operator*(Mint x, Mint y) {
  return x *= y;
}
template<typename T> Mint operator*(Mint x, T y) {
  return x *= Mint(y);
}
template<typename T> Mint operator*(T x, Mint y) {
  return Mint(x) *= y;
}

Mint operator/(Mint x, Mint y) {
  return x /= y;
}
template<typename T> Mint operator/(Mint x, T y) {
  return x /= Mint(y);
}
template<typename T> Mint operator/(T x, Mint y) {
  return Mint(x) /= y;
}

string to_string(Mint x) {
  return to_string(x.value);
}

istream& operator>>(istream& s, Mint& x) {
  long long in;
  s >> in;
  x = in;
  return s;
}

ostream& operator<<(ostream& s, Mint x) {
  s << x();
  return s;
}

template<typename T> Mint power(Mint x, T y) {
  assert(y >= 0);
  Mint res = 1;
  while (y > 0) {
    if (y & 1) {
      res *= x;
    }
    x *= x;
    y >>= 1;
  }
  return res;
}


mt19937_64 rng((uint64_t) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Mint> dp(n + 1);
  Mint pref = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      dp[j] += 1;
    }
    dp[i] += pref;
    pref += dp[i];
  }    

  for (int i = 0; i < n; ++i) {
    long long t = rng();
    dp[i] *= t;
    dp[i] /= t;
    dp[i] += t;
    dp[i] -= t;
  }
  cout << dp[n];
}