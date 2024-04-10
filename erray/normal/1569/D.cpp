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
  const int MAX = int(1e6) + 1;
  vector<vector<int>> hor(MAX);
  vector<vector<int>> ver(MAX);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    set<int> vr;
    set<int> hr;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      vr.insert(x);
    }
    
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      hr.insert(x);
    }

    vector<int> tp;
    for (int i = 0; i < k; ++i) {
      int x, y;
      cin >> x >> y;
      tp.push_back(x);
      tp.push_back(y);
      if (!vr.count(x)) {
        hor[y].push_back(x);
      } else if (!hr.count(y)) {
        ver[x].push_back(y);
      }
    }

    sort(tp.begin(), tp.end());
    tp.resize(unique(tp.begin(), tp.end()) - tp.begin());


    auto Count = [&](vector<vector<int>>& x, set<int> roads) {
      roads.insert(-1);
      auto F = [&](vector<int> y) {
        long long res = 0;
        sort(y.begin(), y.end());
        for (int i = 0; i < int(y.size()); ++i) {
          int lst = *prev(roads.lower_bound(y[i] + 1));
          int j = lower_bound(y.begin(), y.end(), lst + 1) - y.begin();
          assert(j <= i);
          res += (i - j);
        }    
        return res;
      }; 

      long long dec = 0;
      vector<int> all;
      for (auto i : tp) {
        dec += F(x[i]);
        all.insert(all.end(), x[i].begin(), x[i].end());
      }
      return F(all) - dec;
    };

    cout << Count(ver, hr) + Count(hor, vr) << '\n';
    for (auto e : tp) {
      hor[e].clear();
      ver[e].clear();
    }
  }
}