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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    reverse(s.begin(), s.end());
    debug(s);
    for (auto& e : s) {
      e -= '0';
    }

    vector<int> pwA(n + 1);
    pwA[0] = 1;
    vector<int> pwB(n + 1);
    pwB[0] = 1;
    for (int i = 0; i < n; ++i) {
      pwA[i + 1] = pwA[i] * 10 % a;
      pwB[i + 1] = pwB[i] * 10 % b;
    }
    
    vector<vector<vector<vector<array<int, 5>>>>> dp(n + 1, vector<vector<vector<array<int, 5>>>>(n + 1, 
    vector<vector<array<int, 5>>>(a, vector<array<int, 5>>(b, {0}))));
    dp[0][0][0][0] = {1, -1, -1, 0, 0};
    for (int ctA = 0; ctA <= n; ++ctA) {
      for (int ctB = 0; ctB < n - ctA; ++ctB) {
        for (int mdA = 0; mdA < a; ++mdA) {
          for (int mdB = 0; mdB < b; ++mdB) {
             auto cur = dp[ctA][ctB][mdA][mdB];
             cur = {cur[0], ctA, ctB, mdA, mdB};
            {
              int nw = (mdA + pwA[ctA] * s[ctA + ctB]) % a;
              auto &next = dp[ctA + 1][ctB][nw][mdB];
              next = max(next, cur);
            }

            {
              int nw = (mdB + pwB[ctB] * s[ctA + ctB]) % b;
              auto &next = dp[ctA][ctB + 1][mdA][nw];
              next = max(next, cur);
            }
          }
        }
      }
    }

    int ans = -1;
    for (int i = 1; i < n; ++i) {
      if (dp[i][n - i][0][0][0] && abs(n - i - i) < abs(n - ans - ans)) {
        debug(i);
        ans = i;
      } 
    }

    if (ans == -1) {
      cout << -1 << '\n';
      continue;
    }
    debug(ans);

    array<int, 5> cur = {1, ans, n - ans, 0, 0};
    string res(n, '#');
    for (int i = n - 1; i >= 0; --i) {
      auto me = dp[cur[1]][cur[2]][cur[3]][cur[4]];
      if (me[2] == cur[2]) {
        res[n - i - 1] = 'R';
      } else {
        res[n - i - 1] = 'B';
      }
      cur = me;
    }
    cout << res << '\n';
  }
}