/*
 * author:  ADMathNoob
 * created: 07/22/21 10:35:08
 * problem: https://codeforces.com/contest/1553/problem/G
 */

/*
g++ 1553G.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1553G.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

// can't have namespaces, else to_string(int) is hidden, for example

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(const char c) {
  string s = "'";
  s += c;
  s += "'";
  return s;
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < (int) v.size(); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_commas() {
}

template <typename Head, typename... Tail>
void debug_commas(Head H, Tail... T) {
  // comma before each element
  cerr << ", " << to_string(H);
  debug_commas(T...);
}

template <typename Head, typename... Tail>
void debug_better(Head H, Tail... T) {
  cerr << "[" << to_string(H);
  debug_commas(T...);
  cerr << "]" << endl;
}

// print an empty line
void debug_out() {
#ifdef _DEBUG
  cerr << endl;
#endif
}

// can't call debug with no arguments
#ifdef _DEBUG
#define debug(...)                    \
  cerr << "" << #__VA_ARGS__ << ": "; \
  debug_better(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class Dsu {
 public:
  int n;
  vector<int> p;
  vector<int> sz;  // get that inverse Ackermann time complexity
  vector<int> v;   // version
  int comps;
  int ver;

  Dsu(int _n) : n(_n) {
    p.resize(n, -1);
    sz.resize(n, 1);
    v.resize(n, 0);
    comps = n;
    ver = 0;
  }

  inline int get(int x) {
    if (v[x] != ver) {
      p[x] = -1;
      sz[x] = 1;
      v[x] = ver;
    }
    return (p[x] == -1 ? x : (p[x] = get(p[x])));
  }

  inline bool same(int x, int y) {
    return (get(x) == get(y));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return false;
    }
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    p[x] = y;
    sz[y] += sz[x];
    --comps;
    return true;
  }

  inline void reset() {
    comps = n;
    ++ver;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  const int A = (int) 1e6 + 5;
  vector<int> sieve(A, -1);
  for (int i = 2; i * i < A; i++) {
    if (sieve[i] == -1) {
      for (int j = i * i; j < A; j += i) {
        sieve[j] = i;
      }
    }
  }
  
  vector<int> prime_id(A);
  int pp = 0;
  for (int i = 2; i < A; i++) {
    if (sieve[i] == -1) {
      sieve[i] = i;
      prime_id[i] = pp++;
    }
  }
  const int P = pp;
  
  int n, tt;
  cin >> n >> tt;
  Dsu d(n + P);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int x = a[i];
    while (x > 1) {
      int p = sieve[x];
      d.unite(i, n + prime_id[p]);
      x /= p;
    }
  }
  
  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; i++) {
    vector<int> ids;
    {
      int x = a[i];
      while (x > 1) {
        int p = sieve[x];
        ids.push_back(prime_id[p]);
        x /= p;
      }
    }
    {
      int x = a[i] + 1;
      while (x > 1) {
        int p = sieve[x];
        ids.push_back(prime_id[p]);
        x /= p;
      }
    }
    sort(ids.begin(), ids.end());
    ids.resize(unique(ids.begin(), ids.end()) - ids.begin());
    debug(ids);
    int s = (int) ids.size();
    // assert(s <= 7);
    for (int j = 0; j < s; j++) {
      for (int k = 0; k < j; k++) {
        pairs.push_back(minmax(d.get(n + ids[j]), d.get(n + ids[k])));
      }
    }
  }
  sort(pairs.begin(), pairs.end());
  pairs.resize(unique(pairs.begin(), pairs.end()) - pairs.begin());
  debug(pairs);
  // debug(sieve);
  
  while (tt--) {
    int s, t;
    cin >> s >> t;
    --s; --t;
    s = d.get(s);
    t = d.get(t);
    if (s > t) {
      swap(s, t);
    }
    int ans = -1;
    if (d.same(s, t)) {
      ans = 0;
    } else if (binary_search(pairs.begin(), pairs.end(), make_pair(s, t))) {
      ans = 1;
    } else {
      ans = 2;
    }
    cout << ans << '\n';
  }
  return 0;
}