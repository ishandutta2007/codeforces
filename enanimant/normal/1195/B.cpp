// July 28, 2019
// https://codeforces.com/contest/1195/problem/B

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


  int n, k;
  cin >> n >> k;
  // cout << (2 * n + 3 - (int) sqrt(8LL * n + 8LL * k + 9)) / 2 << '\n';
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    long long tot = 1LL * (n - mid) * (n - mid + 1) / 2 - mid;
    if (tot > k) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  cout << lo << '\n';


  return 0;
}