// August 20, 2019
// https://codeforces.com/contest/1204/problem/A

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


  string s;
  cin >> s;
  // if (s == "0") {
  //   cout << "0\n";
  //   return 0;
  // }
  bool all = true;
  int n = (int) s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] == '1') {
      all = false;
    }
  }
  int ans = (n + 1) / 2;
  if (n % 2 == 1 && all) {
    ans--;
  }
  cout << ans << '\n';


  return 0;
}