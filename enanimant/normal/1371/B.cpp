// July 1, 2020
// https://codeforces.com/contest/1371/problem/B

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
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, r;
    cin >> n >> r;
    long long m = min(n - 1, r);
    long long ans = m * (m + 1) / 2;
    if (n <= r) {
      ans++;
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}