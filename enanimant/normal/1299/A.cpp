// February 9, 2020
// https://codeforces.com/contest/1299/problem/A

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
  int x = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x ^= a[i];
  }
  vector<int> poa(n), soa(n);
  poa[0] = a[0];
  for (int i = 1; i < n; i++) {
    poa[i] = poa[i - 1] | a[i];
  }
  soa[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    soa[i] = soa[i + 1] | a[i];
  }
  int ans = 0, bid = 0;
  for (int i = 0; i < n; i++) {
    int x = 0;
    if (i - 1 >= 0) {
      x |= poa[i - 1];
    }
    if (i + 1 < n) {
      x |= soa[i + 1];
    }
    int res = (a[i] | x) - x;
    if (res > ans) {
      ans = res;
      bid = i;
    }
  }
  swap(a[0], a[bid]);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';


  return 0;
}