// author: erray
#include <bits/stdc++.h>
 
using namespace std;

template<typename A, typename B> string to_string(const pair<A, B>& p);
template<typename A, typename B, typename C> string to_string(const tuple<A, B, C>& t);
template<typename A, typename B, typename C, typename D> string to_string(const tuple<A, B, C, D>& t);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char& c) {
  return string("'") + c + "'";
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
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
  }
  res += "}";
  return res;
}

template<typename T, class C> string to_string(priority_queue<T, vector<T>, C> pq) {
  string res = "{";
  while (!pq.empty()) {
    T cur = pq.top();
    pq.pop();
    if ((int) res.size() > 1) {
      res += ", ";
    }
    res += to_string(cur);
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


mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count()); 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = int(2e5);
  vector<bool> ip(MAX + 1, true);
  for (int i = 2; i <= MAX; ++i) {
    if (ip[i]) {
      for (int j = i * 2; j <= MAX; j += i) {
        ip[j] = false;
      }
    }  
  }

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    #ifdef LOCAL
      for (int i = 0; i < n; ++i) {
        cin >> a[i];
      }
    #endif
    auto Ask = [&](int x, int y) {
      if (x > y) {
        swap(x, y);
      }
      assert(x >= 0 && y < n);
      #ifdef LOCAL
        return lcm(1LL * a[x], a[y]);
      #else
        cout << "? " << x + 1 << ' ' << y + 1 << endl;
        long long res;
        cin >> res;
        return res;
      #endif
    };

    vector<long long> ans(n);    
    if (1LL * n * (n - 1) / 2 <= n + 5000) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
          long long x = Ask(i, j);
          ans[i] = gcd(ans[i], x);
          ans[j] = gcd(ans[j], x);
        }
      }

      if (n == 3 && ans[0] % 2 == 0 && ans[1] % 2 == 0 && ans[2] % 2 == 0) {
        *max_element(ans.begin(), ans.end()) /= 2;
      }
    } else {
      int pct = 0;
      for (int i = MAX; i > MAX - n; --i) {
        if (ip[i] && i * 2 > MAX) {
          ++pct;
        }
      }    
      int possib = (n + (pct - 1)) / pct;
      debug(possib);
      int tries = possib * 10;
      long long p = 0;
      int ind = -1;
      for (int it = 0; it < tries; ++it) {
        int x = rng() % n;
        long long val = 0;
        for (int qit = 0; qit < 5001 / tries; ++qit) {
          int y;
          do {
            y = rng() % n;
          } while (y == x);
          val = gcd(val, Ask(x, y));
        }
       
        if (val <= MAX && ip[val]) {
          if (p < val) {
            p = val;
            ind = x;
          }    
        }
      }
      debug(p, ind);
      for (int i = 0; i < n; ++i) {
        ans[i] = (i == ind ? p : Ask(i, ind) / p);
      }
    }

    //debug(a);
    //debug(ans);
    
    #ifdef LOCAL
      debug(ans);
      debug(a);
      assert(ans == a);
    #else 
      cout << "! ";
      for (auto e : ans) {
        cout << e << ' ';
      }
      cout << endl;
    #endif
  }
}