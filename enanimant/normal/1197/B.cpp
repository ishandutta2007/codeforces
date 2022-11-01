// July 22, 2019
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


  int n;
  cin >> n;
  int last = -1;
  bool inc = true;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (inc) {
      if (a < last) {
        inc = false;
      }
    } else {
      if (a > last) {
        cout << "no\n";
        return 0;
      }
    }
    last = a;
  }
  cout << "yes\n";


  return 0;
}