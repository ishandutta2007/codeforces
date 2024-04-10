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
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    debug(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      g[x].push_back(i);
      g[i].push_back(x);
    }

    vector<int> a(n);
    for (int i = 1; i < n; ++i) {
      cin >> a[i];
    }
    debug(a);
    
    vector<int> d(n);
    vector<vector<int>> child(n);
    function<void(int, int)> Dfs = [&](int v, int pr) {
      debug(v, pr); 
      for (auto u : g[v]) {
        if (u == pr) {
          continue;
        }

        d[u] = d[v] + 1;
        child[v].push_back(u);
        Dfs(u, v);
      }
    };

    Dfs(0, -1);
    debug(d);
    int mx = (*max_element(d.begin(), d.end())) + 1;
    vector<vector<int>> all(mx);
    for (int i = 0; i < n; ++i) {
      all[d[i]].push_back(i);
    }
    debug(all);

    vector<long long> dp(n);
    vector<long long> val(n);

    for (int depth = mx - 1; depth >= 0; --depth) {
      vector<int> ord = all[depth];
      sort(ord.begin(), ord.end(), [&](int x, int y) {
        return a[x] < a[y];
      });

      const int N = (int) ord.size();
      for (int i = 0; i < N; ++i) {
        for (auto u : child[ord[i]]) {
          val[ord[i]] = max(val[ord[i]], dp[u]); 
        }
        dp[ord[i]] = val[ord[i]] + max(abs(a[ord[0]] - a[ord[i]]), abs(a[ord.back()] - a[ord[i]]));
      }

      {
        long long best = 0;
        int last = a[ord[0]];
        for (auto e : ord) {
          best += abs(a[e] - last);
          dp[e] = max(dp[e], best);
          best = max(best, val[e]);
          last = a[e];
        }
      }

      reverse(ord.begin(), ord.end());
      {
        long long best = 0;
        int last = a[ord[0]];
        for (auto e : ord) {
          best += abs(a[e] - last);
          dp[e] = max(dp[e], best);
          best = max(best, val[e]);
          last = a[e];
        }
      }

    }

    cout << dp[0] << '\n';
  }
}