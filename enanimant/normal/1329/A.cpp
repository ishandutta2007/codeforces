// April 3, 2020
// https://codeforces.com/contest/768/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n, m;
  cin >> n >> m;
  vector<int> len(m);
  int r = 0;
  long long sum = 0;
  for (int i = 0; i < m; i++) {
    cin >> len[i];
    sum += len[i];
    r = max(r, i + len[i] - 1);
  }
  if (r >= n || sum < n) {
    cout << "-1\n";
    return 0;
  }
  vector<int> ans(m);
  int x = n - len[m - 1];
  for (int i = m - 1; i >= 0; i--) {
    ans[i] = x;
    if (i == 0) {
      break;
    }
    while (x >= i && (x + len[i - 1] - 1 >= ans[i] || x + len[i - 1] - 1 >= n)) {
      x--;
    }
  }
  for (int i = 0; i < m; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << ans[i] + 1;
  }
  cout << '\n';


  return 0;
}