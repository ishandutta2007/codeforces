// author: erray
#include<bits/stdc++.h>
 
using namespace std;

const int N = 5005, K = 2505, inf = (int) 1e9;

int n, a[N], dp[K][N][2];

int get(int k, int ind, bool bef) {
  if (k == 0) return 0;
  if (ind < 0) return inf;
  return dp[k][ind][bef];
}

int getArr(int ind) {
  if (ind < 0 || ind >= n) return -2;
  return a[ind];
}
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (n == 1) return cout << 0, 0;
  if (n == 2) return cout << (a[0] == a[1]), 0;
  for (int cur = 1; cur <= (n + 1) / 2; ++cur) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 2; ++j) {
        dp[cur][i][j] = get(cur, i - 1, false);
        int bef = (j ? min((i + 2 < n ? a[i + 2] : INT_MAX) - 1, getArr(i + 1)) : getArr(i + 1));
        int need = a[i] - 1;
        dp[cur][i][j] = min(dp[cur][i][j], max(0, bef - need) + max(0, getArr(i - 1) - need) + get(cur - 1, i - 2, true));
      }
    }   
    cout << dp[cur][n - 1][0] << ' ';
  }
}