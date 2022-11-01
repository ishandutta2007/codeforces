// August 20, 2019
// https://codeforces.com/contest/1204/problem/B

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


  int n, l, r;
  cin >> n >> l >> r;
  int mn = n - l + (1 << l) - 1;
  int mx = (1 << r) - 1 + (n - r) * (1 << (r - 1));
  cout << mn << ' ' << mx << '\n';


  return 0;
}