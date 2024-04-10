// July 20, 2019
//

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


  int w, h;
  cin >> w >> h;
  int ans = 1;
  for (int i = 0; i < w + h; i++) {
    ans = (ans << 1) % 998244353;
  }
  cout << ans << '\n';


  return 0;
}