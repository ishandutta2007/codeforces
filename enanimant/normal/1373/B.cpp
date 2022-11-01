// June 25, 2020
// https://codeforces.com/contest/1373/problem/B

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
    string s;
    cin >> s;
    int n = (int) s.size();
    int z = 0;
    for (char c : s) {
      if (c == '0') {
        z++;
      }
    }
    int moves = min(z, n - z);
    cout << (moves % 2 == 1 ? "DA" : "NET") << '\n';
  }
  
  
  return 0;
}