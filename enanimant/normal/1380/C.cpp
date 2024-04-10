// July 12, 2020
// https://codeforces.com/contest/1380/problem/C

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      cnt++;
      if ((long long) cnt * a[i] >= x) {
        cnt = 0;
        ans++;
      }
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}