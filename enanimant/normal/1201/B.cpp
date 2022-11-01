// August 4, 2019
// https://codeforces.com/contest/1201/problem/B

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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long s = accumulate(a.begin(), a.end(), 0LL);
  if (s & 1) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > s / 2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";


  return 0;
}