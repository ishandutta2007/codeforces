// July 11, 2020
// https://codeforces.com/contest/1372/problem/B

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
    int n;
    cin >> n;
    int mn = n;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        mn = i;
        break;
      }
    }
    cout << n / mn << ' ' << n - n / mn << '\n';
  }
  
  
  return 0;
}