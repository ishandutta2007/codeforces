// August 22, 2019
// https://codeforces.com/contest/1207/problem/A

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
    int b, p, f, h, c;
    cin >> b >> p >> f >> h >> c;
    if (h < c) {
      swap(h, c);
      swap(p, f);
    }
    int ans = 0;
    int hs = min(b / 2, p);
    b -= 2 * hs;
    ans += h * hs;
    int cs = min(b / 2, f);
    b -= 2 * cs;
    ans += c * cs;
    cout << ans << '\n';
  }


  return 0;
}