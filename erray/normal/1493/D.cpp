// author: erray
#include<bits/stdc++.h>
 
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
 
const int md = (int) 1e9 + 7;
int add(int x, int y) {
  return (x + y) % md;
}

int mul(int x, int y) {
  return 1LL * x * y % md;
}

int power(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = mul(res, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  const int MN = (int) 2e5 + 1;
  const int SN = int(sqrt(MN)) + 5;
  vector<bool> ip(SN, true);
  vector<int> p;
  for (int i = 2; i < SN; ++i) {
    if (!ip[i]) {
      continue;
    }
    p.push_back(i);
    for (int j = i * 2; j < SN; j += i) {
      ip[j] = false;
    }
  }

  cerr << (int) p.size() << '\n';

  const int N = (int) p.size();
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 1;
  vector<map<int, int>> l(MN);
  vector<multiset<int>> con(MN);
  vector<int> cur(MN);

  auto add = [&](int x, int w, int ct) {
  debug(w, x, ct);
    if (l[w][x] == 0) {
      con[w].insert(0);
    }
    con[w].erase(con[w].find(l[w][x])); 
    l[w][x] += ct;
    con[w].insert(l[w][x]);
    if ((int) con[w].size() == n) {
      int nw = *con[w].begin();
      ans = mul(ans, power(w, nw - cur[w]));
      cur[w] = nw;
    }
  };


  auto Add = [&](int x, int y) {
    for (int i = 0; i < N && p[i] * p[i] <= y; ++i) {
      if (y % p[i]) {
        continue;
      }

      int c = 0;
      while (y % p[i] == 0) {
        y /= p[i];
        ++c;
      }
      add(x, p[i], c);
    }    

    if (y > 1) {
      add(x, y, 1);
    }
  };

  for (int i = 0; i < n; ++i) {
    debug(l, con);
    Add(i, a[i]);
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x;
    Add(x, y);
    cout << ans << '\n';
  }
}