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
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q, s;
  cin >> n >> q >> s;
  --s;
  
  vector<vector<array<int, 2>>> tree;
  tree.resize(n * 2);
  auto Add_edge = [&](int l, int r, int u, int cost) {
    ++r;
    l += n;
    r += n;
    while (l < r) {
      if (l & 1) {
        tree[l].push_back({u, cost});
        ++l;  
      }
      if (r & 1) {
        --r;
        tree[r].push_back({u, cost});
      }
      l >>= 1;
      r >>= 1;
    }
  };
  vector<vector<array<int, 3>>> g(n);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, u, w;
      cin >> v >> u >> w;
      --v, --u;
      g[v].push_back({u, u, w});
    } else if (t == 2) {
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      --v, --l, --r;
      g[v].push_back({l, r, w});
    } else {
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      --v, --l, --r;
      Add_edge(l, r, v, w); 
    }
  }
  debug(g);
  debug(tree);

  const long long inf = (long long) 1e16; 
  vector<long long> cost(n, inf);
  set<int> act;
  for (int i = 0; i < n; ++i) {
    act.insert(i);
  }
  debug(act);

  set<tuple<long long, int, int>> st;
  auto Add = [&](int v, long long c) {
    if (cost[v] <= c) {
      return;
    }
    if (cost[v] < inf) {
      st.erase({cost[v], v, v});
    }
    cost[v] = c;
    st.insert({c, v, v}); 
  };

  auto Apply = [&](int v) {
    debug(v, g[v], act);    
    if (!act.count(v)) {
      return;
    }
    act.erase(v);
    {
      int p = v;
      p += n;
      while (p > 0) {
        for (auto[u, c] : tree[p]) {
          Add(u, cost[v] + c); 
        }
        tree[p].clear();
        p >>= 1; 
      }
    }

    for (auto[l, r, w] : g[v]) {
      st.insert({cost[v] + w, l, r});
    }
    debug(st);
  };

  cost[s] = 0;
  Apply(s);
  while (!st.empty()) {
    auto[c, l, r] = *st.begin();
    st.erase(st.begin()); 
    debug(c, l, r);
    while (act.lower_bound(l) != act.lower_bound(r + 1)) {
      int v = *act.lower_bound(l);
      cost[v] = c;
      Apply(v);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << (cost[i] == inf ? -1LL : cost[i]) << ' ';  
  }
}