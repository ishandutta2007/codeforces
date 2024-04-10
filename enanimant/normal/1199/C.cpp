// July 30, 2019
// https://codeforces.com/contest/1199/problem/C

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


  int n, I;
  cin >> n >> I;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int k = 8 * I / n;
  if (k >= 30) {
    cout << "0\n";
    return 0;
  }
  int d = 1 << k;
  sort(a.begin(), a.end());
  auto b = a;
  b.erase(unique(b.begin(), b.end()), b.end());
  int ans = n;
  if (d >= b.size()) {
    ans = 0;
  }
  for (int i = 0; i + d <= b.size(); i++) {
    int l = b[i], r = b[i + d - 1];
    int stay = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
    ans = min(ans, n - stay);
  }
  cout << ans << '\n';


  return 0;
}