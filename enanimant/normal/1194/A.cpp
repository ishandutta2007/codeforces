// July 14, 2019
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


  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    int steps = (n + 1) / 2;
    cout << (x <= steps ? 2 * x : 2 * x + (x - steps)) << '\n';
  }


  return 0;
}