// author: erray
#include<bits/stdc++.h>
 
using namespace std;

typedef __int128 int128;
istream& operator>>(istream& in, int128& n) {
  string s;
  in >> s;
  n = 0;
  for (char c : s) {
    n *= 10;
    n += c - '0';
  }
  return in;
}

ostream& operator<<(ostream& out, int128 n) {
  if (n == 0) {
    out << 0;
    return out;
  }
  string res;
  bool neg = n < 0;
  while (n > 0) {
    res += char('0' + n % 10);
    n /= 10;
  }
  if (neg) {
    res += '-';
  }
  reverse(res.begin(), res.end());
  out << res;
  return out;
}
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    g[x - 1].push_back(i);
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto check = [&](int128 w) {
    vector<int128> dp(n);
    for (int v = n - 1; v >= 0; --v) {
      int128 take = 0;
      if (g[v].empty()) {
        take = w;
      } 
      for (auto u : g[v]) {
        take += dp[u];
      }
      dp[v] = take - a[v];
      if (dp[v] < 0) {
        return false;
      }
    }
    return true;
  };
  
  int128 low = 0, high = int128(1e15);
  while (low < high) {
    int128 mid = (low + high) >> 1;
    if (check(mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
}