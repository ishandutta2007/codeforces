// July 31, 2020
// https://codeforces.com/contest/1388/problem/A

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
  
  
  vector<int> a = {6, 10, 14};
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n <= 30) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (find(a.begin(), a.end(), n - 30) == a.end()) {
      cout << "6 10 14 " << n - 30 << '\n';
    } else {
      cout << "6 10 15 " << n - 31 << '\n';
    }
  }
  
  
  return 0;
}