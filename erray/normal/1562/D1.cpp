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

constexpr bool HARD = false;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    string s;   
    cin >> n >> q >> s;
    vector<array<int, 3>> qs(q);
    for (int i = 0; i < q; ++i) {
      cin >> qs[i][0] >> qs[i][1];
      qs[i][2] = i;
      --qs[i][0], --qs[i][1];
    }

    debug(n, s.size());                            
    vector<vector<int>> ans(q);
    for (int st = 0; st < 2; ++st) {      
      vector<array<int, 3>> mqs;
      for (auto e : qs) {
        if (e[0] % 2 == st) {
          mqs.push_back(e);
        }
      }
      sort(mqs.begin(), mqs.end(), [&](auto x, auto y) {
        return x[1] < y[1];
      });
      vector<int> pref(n + 1);
      vector<int> a(n);
      for (int i = 0; i < n; ++i) {
        a[i] = (s[i] == '+' ? 1 : -1) * (((i % 2) ^ st) ? -1 : 1);
        pref[i + 1] = pref[i] + a[i];
      }
      debug(a, pref);
      debug(mqs);

      array<vector<int>, 2> pos;
      pos[0].resize(2 * n + 1, -1);
      pos[1].resize(2 * n + 1, -1);
      const int ADD = n;
      int lst = -1;
      for (auto[l, r, id] : mqs) {
        while (lst < r - 1) {
          ++lst;
          pos[(a[lst] > 0)][pref[lst + 1] + ADD] = lst;
        }
        int sum = pref[r + 1] - pref[l];
        debug(id, sum);
        if (sum == 0) {
          debug("zero", id);
          continue;
        } else if (sum - a[r] == 0) {
          ans[id] = {r};
          continue;
        }

        bool even = false;
        if (sum % 2 == 0) {   
          sum -= a[r];
          ans[id] = {r}; 
          even = true;
        }

        debug(sum);

        bool done = false;
        for (int j = 0; j < 2 && !done; ++j) {
          int add = (j ? 1 : -1);
          int new_sum = sum - add; 
          int need = pref[r + !even] - new_sum / 2;
          debug(need);
          if (pos[j][need + ADD] != -1) {
            ans[id].push_back(pos[j][need + ADD]);
            done = true;
          }
        }
        assert(done);   
      }
    }

    for (auto e : ans) {
      cout << int(e.size()) << '\n';
      if (HARD && e.size()) {
        sort(e.begin(), e.end());
        for (auto ee : e) {
          cout << ee + 1 << ' ';
        }
        cout << '\n';
      }
    }
  }
}