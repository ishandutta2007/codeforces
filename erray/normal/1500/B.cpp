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

int extgcd(int a, int b, long long &x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  int d = extgcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

bool crt(long long a1, long long n1, long long a2, long long n2, long long& res) {
  long long x, y;
  int d = extgcd(n1, n2, x, y);
  debug(d);
  debug(x, y);
  res = a1 + n1 / d * x * (a2 - a1);
  res %= n1 / d * n2; 
  if (res < 0) {
    res += n1 / d * n2;
  }
  return (res % n1 == a1 && res % n2 == a2);                      
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  long long k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vector<int> b(m);  
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    --b[i];
  }
  
  long long lcm = 1LL * n / gcd(n, m) * m;
  vector<vector<int>> pos(2 * max(n, m));
  for (int i = 0; i < n; ++i) {
    pos[a[i]].push_back(i);
  }

  for (int i = 0; i < m; ++i) {
    pos[b[i]].push_back(i);
  }

  vector<long long> add;
  for (int i = 0; i < int(pos.size()); ++i) {
    if (int(pos[i].size()) > 1) {
      long long res;
      debug(pos[i]);
      if (crt(pos[i][0], n, pos[i][1], m, res)) {
        debug(i, res);
        add.push_back(res + 1);
      }
    }                        
  }

  debug(add);

  auto Check = [&](long long x) {
    long long tot = x;
    for (auto e : add) {
      if (e <= x) {
        tot -= 1 + (x - e) / lcm;
      }
    }
    return (tot >= k);
  };
  
  long long low = 1, high = (long long) 1e18;
  while (low < high) {
    long long mid = (low + high) >> 1;
    if (Check(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
}