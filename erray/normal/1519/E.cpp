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

struct Rint {
  long long t, b;
  bool normalize() {
    long long g = gcd(t, b);
    t /= g;
    b /= g;
    return g != 1;
  }
  Rint(long long _t, long long _b) : t(_t), b(_b) { 
    normalize();
  }
  Rint() { }

  void add(int ss) {
    t += b * ss;
  }
  bool operator<(const Rint& ot) const {
    return make_pair(t, b) < make_pair(ot.t, ot.b);
  }
  bool operator==(const Rint& ot) const {
    return (t == ot.t) && (b == ot.b);
  }
};

Rint operator/(Rint x, Rint y) {
  Rint res;
  res.t = x.t * y.b;
  res.b = x.b * y.t;
  res.normalize();
  return res;
} 

struct Point {
  Rint x, y;
  Point(Rint _x, Rint _y) : x(_x), y(_y) { }   
  Point() { }
  Rint slope() {
    return y / x;
  }  
  void add_x(int ss) {
    x.add(ss);
  }
  void add_y(int ss) {
    y.add(ss);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> a(n);
  for (int i = 0; i < n; ++i) {
    long long xt, xb, yt, yb;
    cin >> xt >> xb >> yt >> yb;
    a[i] = Point(Rint(xt, xb), Rint(yt, yb));   
  }

  vector<array<Rint, 2>> es(n);
  for (int i = 0; i < n; ++i) {
    a[i].add_x(1);
    es[i][0] = a[i].slope();
    a[i].add_x(-1);
    a[i].add_y(1);
    es[i][1] = a[i].slope();
    a[i].add_y(-1);
  }
  
  vector<Rint> all;
  for (auto[x, y] : es) {
    all.push_back(x);
    all.push_back(y);
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  map<Rint, int> id;
  for (int i = 0; i < int(all.size()); ++i) {
    id[all[i]] = i;
  }

  vector<array<int, 2>> es_real(n);
  for (int i = 0; i < n; ++i) {
    es_real[i] = {id[es[i][0]], id[es[i][1]]};
  }

  debug(es_real);
  const int N = int(all.size());
  vector<vector<int>> g(N);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      g[es_real[i][j]].push_back(i);
    }
  }
      
  debug(g);
  vector<bool> vis(n);
  vector<bool> vis_n(N);
  vector<pair<int, int>> ans;
  function<bool(int, int)> Dfs = [&](int v, int pr) {
    vis_n[v] = true;
    vector<int> add;
    for (auto id : g[v]) {
      int u = es_real[id][0] ^ es_real[id][1] ^ v;
      if (vis[id] || id == pr) {
        continue;
      }
      if (vis_n[u] || !Dfs(u, id)) {
        vis[id] = true;
        add.push_back(id);      
      }
    }
    if (int(add.size()) % 2 == 1 && pr != -1) {
      add.push_back(pr);
      vis[pr] = true;
      pr = -1;
    } 
    debug(v, add);
    for (int i = 0; i < int(add.size()) - 1; i += 2) {
      ans.emplace_back(add[i], add[i + 1]);
    }
    return (pr == -1);
  };  
  
  for (int i = 0; i < N; ++i) {
    if (!vis_n[i]) {
      Dfs(i, -1);
    }
  }
  cout << int(ans.size()) << '\n';
  for (auto[x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }
}