// author: erray
#include <bits/stdc++.h>
 
using namespace std;

template<typename T> struct fenwick {
  int n;
  vector<T> tree;

  void build(vector<T> x) {
    vector<T> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1] + x[i - 1];
      tree[i] = pref[i] - pref[i - (i & -i)];
    }
  }

  fenwick(int _n, T def = T{}) : n(_n) {
    tree.resize(n + 1);
  tree[0] = def;
    build(vector<T>(n, def));
  }

 void modify(int i, T x) {
    assert(i >= 0 && i < n);
    ++i;
    while (i <= n) {
      tree[i] += x;
      i += (i & -i);
    }
  }

  T get(int i) {
    assert(i >= 0 && i < n);
    ++i;
    T res = tree[i];
  i -= (i & -i);
    while (i > 0) {
      res += tree[i];
      i -= (i & -i);
    }
    return res;
  }

  T get(int l, int r) {
    return (l == 0 ? get(r) : get(r) - get(l - 1));
  }

  template<class F, typename... Q> int find_first(F op, Q... qs) {
    //true for suffix, find first index which returns true from suffix
    int cur = 0;
    T sum = tree[0];
    for (int i = __lg(n); i >= 0; --i) {
      if (cur + (1 << i) <= n && !op(sum + tree[cur + (1 << i)], qs...)) {
        cur += (1 << i);
        sum = sum + tree[cur];
      }
    }
    return (cur == n ? -1 : cur);
  }

  template<class F, typename... Q> int find_last(F op, Q... qs) {
    //true for prefix, find last index which returns true from prefix
    int cur = 0;
    T sum = tree[0];
    for (int i = __lg(n); i >= 0; --i) {
      if (cur + (1 << i) <= n && op(sum + tree[cur + (1 << i)], qs...)) {
        cur += (1 << i);
        sum = sum + tree[cur];
      }
    }
    return (cur == 0 ? -1 : cur - 1);
  }

  void clear() {
    build(vector<T>(n, tree[0]));
  }
};

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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    assert(n == 1);
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
    }

    auto sa = a;
    sort(sa.begin(), sa.end());
    for (auto& e : a) {
      e = int(lower_bound(sa.begin(), sa.end(), e) - sa.begin());
    }

    debug(a);
    fenwick<int> sum(m + 1);
    long long ans = 0;
    for (auto e : a) {
      ans += sum.get(e);
      sum.modify(e + 1, + 1);
    }
    cout << ans << '\n';
  }

}