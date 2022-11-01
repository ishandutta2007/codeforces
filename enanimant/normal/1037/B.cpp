// August 23, 2019
// https://codeforces.com/contest/1037/problem/B

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


  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  if (a[n / 2] < s) {
    for (int i = n / 2; i < n; i++) {
      ans += max(0, s - a[i]);
    }
  } else {
    for (int i = 0; i <= n / 2; i++) {
      ans += max(0, a[i] - s);
    }
  }
  cout << ans << '\n';


  return 0;
}