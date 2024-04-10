// May 1, 2020
// https://codeforces.com/contest/1348/problem/D

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
    int n;
    cin >> n;
    int d = 1;
    while (true) {
      vector<int> a;
      int cur = 1;
      int x = n - d - 1;
      for (int i = d; i >= 1; i--) {
        int add = min(cur, x / i);
        a.push_back(add);
        cur += add;
        x -= add * i;
      }
      if (x == 0) {
        cout << a.size() << '\n';
        for (int i = 0; i < (int) a.size(); i++) {
          if (i > 0) {
            cout << ' ';
          }
          cout << a[i];
        }
        cout << '\n';
        break;
      }
      d++;
    }
  }


  return 0;
}