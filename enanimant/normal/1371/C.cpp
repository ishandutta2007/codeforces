// July 1, 2020
// https://codeforces.com/contest/1371/problem/C

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
    long long v, c, n, m;
    cin >> v >> c >> n >> m;
    if (v + c >= n + m && min(v, c) >= m) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
  
  
  return 0;
}