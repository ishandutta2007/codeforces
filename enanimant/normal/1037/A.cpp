// August 23, 2019
// https://codeforces.com/contest/1037/problem/A

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


  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i <<= 1) {
    ans++;
    n -= i;
  }
  if (n > 0) {
    ans++;
  }
  cout << ans << '\n';


  return 0;
}