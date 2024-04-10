// August 18, 2019
// https://codeforces.com/contest/1205/problem/A

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
  if (2LL * n * (2LL * n + 1) / 2 % 2 == 0) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<int> a(2 * n);
  for (int i = 0; i < n; i++) {
    a[i] = 2 * i + (i & 1);
    a[i + n] = 2 * i + ((i & 1) ^ 1);
  }
  for (int i = 0; i < 2 * n; i++) {
    cout << a[i] + 1 << (i < 2 * n - 1 ? ' ' : '\n');
  }


  return 0;
}