// August 4, 2019
// https://codeforces.com/contest/1201/problem/C

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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long lo = 0, hi = 2e9 + 1;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    long long add = 0;
    for (int i = n / 2; i < n; i++) {
      add += max(0LL, mid - a[i]);
    }
    if (add > k) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  assert(lo - 1 >= 1);
  cout << lo - 1 << '\n';


  return 0;
}