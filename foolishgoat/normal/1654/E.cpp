#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 5;
constexpr int MAGIC = sqrt(N), LEN = (N + MAGIC - 1) / MAGIC;

int calc1(vector<int> a) {
  int n = a.size();
  vector<int> b = a;
  int ans = min(n, 2);
  for (int d = -MAGIC; d <= MAGIC; ++d) {
    for (int i = 0; i < n; ++i) {
      b[i] = a[i] - i * d;
    }
    sort(b.begin(), b.end());
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (b[i] != b[i-1])
        cnt = 0;
      ++cnt;
      ans = max(ans, cnt);
    }
  }
  return n - ans;
}

map<int, int> dp[N];

int calc2(vector<int> a) {
  int n = a.size();
  int ans = min(n, 2);
  for (int i = 0; i < n; ++i) {
    for (int j = max(i-LEN, 0); j < i; ++j) {
      int d = a[i] - a[j];
      if (d % (i-j)) continue;
      d /= (i-j);
      if (abs(d) <= MAGIC) continue;
      auto it = dp[j].find(d);
      int val = 2;
      if (it == dp[j].end())
        dp[i][d] = 2;
      else
        dp[i][d] = val = it->second + 1;
      ans = max(ans, val);
    }
  }
  return n - ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = calc1(a);
  ans = min(ans, calc2(a));
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}