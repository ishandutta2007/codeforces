#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2020;
int dp[N][N];
string s;

int get(char a, char b, int res) {
  if (res != 0)
    return res;
  if (a < b)
    return -1;
  else if (a == b)
    return 0;
  else
    return 1;
}

int solve(int l, int r) {
  if (r < l)
    return 0;
  int& ret = dp[l][r];
  if (ret != -2)
    return ret;
  {
    int res = get(s[l], s[l+1], solve(l+2, r));
    res = max(res, get(s[l], s[r], solve(l+1, r-1)));
    ret = res;
  }
  {
    int res = get(s[r], s[l], solve(l+1, r-1));
    res = max(res, get(s[r], s[r-1], solve(l, r-2)));
    ret = min(ret, res);
  }
  return ret;
}

void solve() {
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i][j] = -2;
    }
  }
  int ans = solve(0, n-1);

  if (ans < 0)
    cout << "Alice\n";
  else if (ans == 0)
    cout << "Draw\n";
  else
    cout << "Bob\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}