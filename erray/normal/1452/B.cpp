// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long sum  = accumulate(a.begin(), a.end(), 0LL);
    long long left = sum % (n - 1);
    if (left == 0) {
      left = n - 1;
    }
    cout << max(n - 1 - left, a[0] * (n - 1) - sum) << '\n';
  }
}