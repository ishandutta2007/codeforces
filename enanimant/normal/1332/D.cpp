// March 29, 2020
// https://codeforces.com/contest/1332/problem/D

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


  int k;
  cin >> k;
  int x = (1 << 18) - 1;
  int y = (1 << 17) - 1;
  cout << "2 3\n";
  cout << x << ' ' << y << ' ' << "0\n";
  cout << (1 << 17) << ' ' << x << ' ' << k << '\n';


  return 0;
}