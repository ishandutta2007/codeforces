// July 11, 2020
// https://codeforces.com/contest/1372/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> f(2 * n + 1, 0);
  for (int i = 0; i < 2 * n; i++) {
    f[i + 1] = f[i] + a[2 * i % n];
  }
  int m = (n + 1) / 2;
  long long ans = 0;
  for (int i = 0; i + m <= 2 * n; i++) {
    ans = max(ans, f[i + m] - f[i]);
  }
  cout << ans << '\n';
  
  
  return 0;
}