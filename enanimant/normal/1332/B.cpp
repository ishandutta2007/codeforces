// March 29, 2020
// https://codeforces.com/contest/1332/problem/B

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


  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ans(n);
    vector<int> id(11, -1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < 11; j++) {
        if (a[i] % primes[j] == 0) {
          if (id[j] == -1) {
            id[j] = cnt++;
          }
          ans[i] = id[j];
          break;
        }
      }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ans[i] + 1;
    }
    cout << '\n';
  }


  return 0;
}