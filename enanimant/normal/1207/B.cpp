// August 22, 2019
// https://codeforces.com/contest/1207/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 50;


int n, m;
int a[N][N], b[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i + 2 <= n; i++) {
    for (int j = 0; j + 2 <= m; j++) {
      if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1) {
        b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
        ans.emplace_back(i, j);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (b[i][j] != a[i][j]) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  cout << ans.size() << '\n';
  for (const auto &p : ans) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }


  return 0;
}