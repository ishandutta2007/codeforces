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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto Get = [&](int x) {
    cout << "? " << x + 1 << endl;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      cin >> res[i];
    }
    return res;
  };

  vector<pair<int, int>> g;
  auto root = Get(0);
  auto Add = [&](int x, int y) {
    if (x > y) {
      swap(x, y);
    }
    g.emplace_back(x, y);
  };

  vector<int> ct(2);
  for (int i = 1; i < n; ++i) {
    ++ct[root[i] % 2];
  }

  int go = 0;
  if (ct[1] < ct[0]) {
    go = 1;
  }

  auto Edge = [&](int v) {
    debug(v);
    vector<int> cur;
    if (v == 0) {
      cur = root;
    } else {
      cur = Get(v);
    }

    for (int i = 0; i < n; ++i) {
      if (cur[i] == 1) {
        Add(i, v);
      }
    }
  };

  Edge(0);

  for (int i = 1; i < n; ++i) {
    if (root[i] % 2 == go) {
      Edge(i);
    }
  }

  sort(g.begin(), g.end());
  g.erase(unique(g.begin(), g.end()), g.end());
  cout << "!\n";
  for (auto[v, u] : g) {
    cout << v + 1 << ' ' << u + 1 << '\n';
  }
  cout << endl;
}