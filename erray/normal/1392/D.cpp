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
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string  p;
    cin >> n >> p;
    auto solve = [&](string s) -> int {
      vector<int> dp(n + 1);
      dp[1] = 1e9;
      dp[2] = (s[0] != 'R') + (s[1] != 'L');
      for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i - 2] + (s[i - 1] != 'L') + (s[i - 2] != 'R'), dp[i - 3] + (s[i - 1] != 'L') + (s[i - 3] != 'R'));
        if (i >= 4) {
          dp[i] = min(dp[i], dp[i - 4] + (s[i - 1] != 'L') + (s[i - 2] != 'L') + (s[i - 3] != 'R') + (s[i - 4] != 'R'));
        }
      }
      debug(s, dp);
      return dp[n];
    };
    int ans = INT_MAX;
    for (int i = 0; i < 5; ++i) {
      ans = min(ans, solve(p));
      p += p[0];
      p.erase(p.begin());
    }
    cout << ans << '\n';
  }
}