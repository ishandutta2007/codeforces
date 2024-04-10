// author: erray
#include <bits/stdc++.h>
#undef DEBUG 
using namespace std;

template<typename A, typename B> string to_string(const pair<A, B>& p);
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t);
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char& c) {
  return "'"s + c + "'";
}

string to_string(const char *c) {
  return to_string(string(c));
}

string to_string(const bool& b) {
  return (b ? "true" : "false");
}

string to_string(const vector<bool>& v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if (i > 0) {
      res += ", ";
    }
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<size_t T> string to_string(const bitset<T>& bs) {
  return bs.to_string();
}

template<typename T> string to_string(queue<T> q) {
  string res = "{";
  size_t sz = q.size();
  while (sz--) {
    T cur = q.front();
    q.pop();
    q.push(cur);
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T, class C> string to_string(priority_queue<T, vector<T>, C> pq) {
  vector<T> tmp;
  string res = "{";
  while (!pq.empty()) {
    T cur = pq.top();
    pq.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
    tmp.push_back(cur);
  }
  for (auto el : tmp) {
    pq.push(el);
  }
  res += "}";
  return res;
}

template<typename T> string to_string(const T& v) {
  string res = "{";
  for (auto &el : v) {
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(el);
  }
  res += "}";
  return res;
}

template<typename A, typename B> string to_string(const pair<A, B>& p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ')';
}
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t) {
  return '(' + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ')';
}

void debug_out(int size, bool first, string name) {
  vector<string> tmp = {name};
  vector<int> tmp2 = {size, first};
  cerr << endl;
}

constexpr int buffer_size = 255;

template<typename Head, typename... Tail> void debug_out(int size, bool first, string name, Head H, Tail... T) {
  string tmp;
  int off = 0;
  while ((!name.empty() && name[0] != ',') || off != 0) {
    tmp += name[0];
    name.erase(name.begin());
    char c = tmp.back();
    if (c == '{' || c == '(') {
      ++off;
    } else if (c == '}' || c == ')'){
      --off;
    }
  }
  if (!name.empty()) {
    name.erase(name.begin());
  }
  if (tmp[0] == ' ') {
    tmp.erase(tmp.begin());
  }

  string buff = to_string(H);
  if ((int) buff.size() + size + (int) tmp.size() > buffer_size - 5 && !first) {
    cerr << '\n';
    size = 0;
  }
  cerr << '[' << tmp << ": " << buff << "] ";
  debug_out(((int) buff.size() + size + (int) tmp.size() + 5) % buffer_size, false, name, T...);
}

#ifdef DEBUG
#define debug(...) cerr << "-> ", debug_out(3, true, string(#__VA_ARGS__), __VA_ARGS__)
#define here cerr << "-> " << __LINE__ << endl
#else
#define debug(...) void(37)
#define here void(37)
#endif

int md;
int power(int x, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) {
      res = 1LL * res * x % md;
    }
    x = 1LL * x * x % md;
    p >>= 1;
  }
  return res;
} 

int add(int& x, int y) {
  x = (0LL + x + y) % md;
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n >> md;
  vector<int> inv(n + 1);
  vector<int> fact(n + 1, 1);
  for (int i = 0; i < n; ++i) {
    fact[i + 1] = 1LL * fact[i] * (i + 1) % md;
  }

  for (int i = 1; i <= n; ++i) {
    inv[i] = power(fact[i], md - 2);
  }
  
  /*
  vector<vector<int>> ct(n + 1, vector<int>(n + 1));
  ct[0][0] = 1;  
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < i; ++k) {  
        if (j + k != i - 1) {
          continue;
        }
        add(ct[j + 1][k], ct[j][k]);
        add(ct[j][k + 1], ct[j][k]);
      }
    }
  }

  debug(ct);

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      int tot = i + j;
      if (tot > n) {
        continue;
      }
      add(many[tot], ct[i][j]);
    }
  }

  debug(many);
  */
  vector<int> many(n + 1);
  for (int i = 1; i <= n; ++i) {
    many[i] = 1LL * power(2, i - 1) * inv[i] % md;
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int ct = 1; ct <= i; ++ct) {
      if (i - ct == 1) {
        continue;
      }
      int go = max(0, i - ct - 1);
      for (int from = 0; from <= i - ct; ++from) {
        int w = 1LL * dp[go][from] * many[ct] % md;
        add(dp[i][from + ct], w);
        debug(i, from + ct, go, from, w);
      }
    }
  }


  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cerr << dp[i][j] * fact[j] % md << ' ';
    }
    cerr << '\n';
  }
  #endif

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    add(ans, (1LL * dp[n][i] * fact[i]) % md);
  }
  cout << ans << '\n';
}