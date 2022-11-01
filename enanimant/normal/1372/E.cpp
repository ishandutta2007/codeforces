// July 11, 2020
// https://codeforces.com/contest/1372/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 105;

int n, m;
int l[N][N], r[N][N];
int dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      for (int j = x; j <= y; j++) {
        l[i][j] = x;
        r[i][j] = y;
      }
    }
  }
  for (int a = m - 1; a >= 0; a--) { // left endpoint
    for (int b = a; b < m; b++) { // right endpoint
      int res = 0;
      for (int f = a; f <= b; f++) { // column to maximize sum ("fill")
        int x = 0;
        for (int i = 0; i < n; i++) {
          if (a <= l[i][f] && r[i][f] <= b) {
            x++;
          }
        }
        int p = (f > 0 ? dp[a][f - 1] : 0);
        res = max(res, p + x * x + dp[f + 1][b]);
      }
      dp[a][b] = res;
    }
  }
  cout << dp[0][m - 1] << '\n';
  
  for (int a = 0; a < m; a++) {
    for (int b = a; b < m; b++) {
      cerr << "answer for [" << a << ", " << b << "] is " << dp[a][b] << '\n';
    }
  }
  
  
  return 0;
}