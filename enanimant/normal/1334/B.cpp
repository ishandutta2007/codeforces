// April 10, 2020
// https://codeforces.com/contest/1334/problem/B

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
    long long sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum >= 1LL * x * (i + 1)) {
        ans = i + 1;
      }
    }
    cout << ans << '\n';
  }


  return 0;
}