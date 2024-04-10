// July 14, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int n, k;

bool winning(int x) {
  if (x < k || k % 3 != 0) {
    return (x % 3 != 0);
  }
  x %= k + 1;
  return (x % 3 != 0 || x == k);
}

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
    cin >> n >> k;
    cout << (winning(n) ? "Alice" : "Bob") << '\n';
  }


  return 0;
}