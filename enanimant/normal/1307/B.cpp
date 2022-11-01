// February 17, 2020
// https://codeforces.com/contest/1307/problem/B

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = a.back();
    int ans = -1;
    if (x >= mx) {
      ans = (x + mx - 1) / mx;
    } else if (binary_search(a.begin(), a.end(), x)) {
      ans = 1;
    } else {
      ans = 2;
    }
    cout << ans << '\n';
  }


  return 0;
}