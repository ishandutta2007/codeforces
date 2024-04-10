// March 19, 2020
// https://codeforces.com/contest/1325/problem/A

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


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "-1\n";
      continue;
    }
    cout << "2";
    for (int i = 0; i < n - 1; i++) {
      cout << "3";
    }
    cout << '\n';
  }


  return 0;
}