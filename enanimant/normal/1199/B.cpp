// July 30, 2019
// https://codeforces.com/contest/1199/problem/B

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


  long long H, L;
  cin >> H >> L;
  cout.precision(6);
  cout << fixed;
  cout << (double) (L * L - H * H) / (2 * H) << '\n';


  return 0;
}