// August 23, 2019
// https://codeforces.com/contest/1037/problem/C

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
  string a, b;
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] != a[i + 1] && a[i] == b[i + 1] && a[i + 1] == b[i]) {
      ans++;
      swap(a[i], a[i + 1]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      ans++;
    }
  }
  cout << ans << '\n';


  return 0;
}