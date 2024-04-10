// August 16, 2020
// 

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) {
        cout << ' ';
      }
      cout << (i % 2 == 0 ? 0LL : (1LL << (i + j - 1)));
    }
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    int x = 0, y = 0;
    cout << x + 1 << ' ' << y + 1 << endl;
    for (int i = 0; i < 2 * (n - 1); i++) {
      if ((k + x) % 2 == 1) {
        x++;
      } else {
        y++;
      }
      cout << x + 1 << ' ' << y + 1 << endl;
      k >>= 1;
    }
  }
  
  
  return 0;
}