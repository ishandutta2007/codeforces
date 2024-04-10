// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
template<typename T, typename F> string to_string(pair<T, F> p);
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(char c) {
  return (string) "'" + c + "'";
}
string to_string(const char* p) {
  return to_string((string) p);
}
string to_string(bool B) {
  return (B ? "true" : "false");
}
string to_string(vector<bool> v) {
  string res = "{";
  for (int i = 0; i < (int) v.size(); ++i) {
    if ((int) res.size() > 1) res += ", ";
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template<size_t T> string to_string(bitset<T> bs) {
  return bs.to_string();
}
template<typename T> string to_string(T v) {
  string res = "{";
  for (auto& el : v) {
    if ((int) res.size() > 1) res += ", ";
    res += to_string(el);
  }
  res += "}";
  return res;
}
template<typename T, typename F> string to_string(pair<T, F> p) {
  return '(' + to_string(p.first) + ", " + to_string(p.second) + ')';
}
void debug_out() {
  cerr << endl;
}
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" , debug_out(__VA_ARGS__)
#else
#define debug(...) (void) 37
#endif
 
const int mod = (int) 1e9 + 7;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; ++i) cin >> p[i];
    while ((int) p.size() < n - 1) p.push_back(1);
    sort(p.begin(), p.end());
    vector<int> best;
    best.reserve(n - 1);
    vector<int> ct(n, 1);
    function<int(int, int)> dfs = [&](int v, int pr) {
      for (auto u : g[v]) {
        if (u == pr) continue;
        ct[v] += dfs(u, v); 
      }
      if (v != 0) {
        best.push_back(max(ct[v], n - ct[v]));
      }
      return ct[v];
    };
    dfs(0, -1);
    sort(best.begin(), best.end());
    debug(p, best);
    long long ans = 0, sum = 1;
    while ((int) p.size() > n - 1) {
      (sum *= p.back()) %= mod;
      p.pop_back();  
    }
    for (int i = 0; i < n - 1; ++i) {
      (sum *= p.back()) %= mod;
      p.pop_back();
      (ans += sum * (1LL * best[i] * (n - best[i]) % mod)) %= mod;  
      sum = 1;
    }     
    cout << ans << '\n';
  }
}