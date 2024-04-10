#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  long long x = (s * 2 - (long long) n * n + n) / (2 * n);
  s -= (x * 2 + n - 1) * n / 2;
  for (int i = 0; i < n; i++) {
    a[i] = x + i + (i < s);
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
  
  
  return 0;
}