// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int p = 1;
  vector<vector<int>> c(n, vector<int>(n, -1));
  int cur = 0;
  while (p < n) {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (i / p % k != j / p % k) {
          c[i][j] = cur;
        }  
      }
    }
    cur += 1;
    p *= k; 
  }

  cout << cur << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cout << c[i][j] + 1 << ' ';
    }
  }
}