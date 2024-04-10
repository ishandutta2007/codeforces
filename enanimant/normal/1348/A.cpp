// May 1, 2020
// https://codeforces.com/contest/1348/problem/A

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
    long long a = (1 << n);
    for (int i = 1; i < n / 2; i++) {
      a += (1 << i);
    }
    long long b = 0;
    for (int i = n / 2; i < n; i++) {
      b += (1 << i);
    }
    long long ans = abs(b - a);
    cout << ans << '\n';
  }


  return 0;
}