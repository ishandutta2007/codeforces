// July 30, 2019
// https://codeforces.com/contest/1199/problem/A

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


  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    bool works = true;
    for (int j = max(0, i - x); j < i; j++) {
      works &= (a[j] > a[i]);
    }
    for (int j = i + 1; j <= min(n - 1, i + y); j++) {
      works &= (a[j] > a[i]);
    }
    if (works) {
      cout << i + 1 << '\n';
      return 0;
    }
  }


  return 0;
}