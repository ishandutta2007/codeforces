// April 5, 2020
// https://codeforces.com/problemset/problem/372/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 150005;

long long dp[2][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, m, d;
  cin >> n >> m >> d;
  vector<tuple<int, int, int>> v;
  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    a--;
    v.emplace_back(t, a, b);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    int t, a, b;
    tie(t, a, b) = v[i];
    if (i == 0) {
      for (int j = 0; j < n; j++) {
        dp[0][j] = b - abs(j - a);
      }
      continue;
    }
    int k = t - get<0>(v[i - 1]);
    deque<int> q;
    function<void(int)> insert = [&](int x) {
      while (!q.empty() && dp[0][q.back()] <= dp[0][x]) {
        q.pop_back();
      }
      q.push_back(x);
    };
    int r = 0;
    for (int j = 0; j < n; j++) {
      long long ll = (long long) j - 1LL * k * d;
      long long rr = (long long) j + 1LL * k * d;
      while (r <= min(rr, (long long) n - 1)) {
        insert(r++);
      }
      if (!q.empty() && q.front() < ll) {
        q.pop_front();
      }
      dp[1][j] = dp[0][q.front()] + b - abs(j - a);
    }
    swap(dp[0], dp[1]);
  }
  long long ans = -1e18;
  for (int j = 0; j < n; j++) {
    ans = max(ans, dp[0][j]);
  }
  cout << ans << '\n';


  return 0;
}