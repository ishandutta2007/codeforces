#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;

int a[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a+n);
  n = unique(a, a+n) - a;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = a[i]+a[i]; j < a[n-1]+a[i]; j += a[i]) {
      int k = lower_bound(a, a+n, j) - a;
      ans = max(ans, a[k-1] % a[i]);
    }
  }
  cout << ans <<  '\n';
}