#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2036;
int n, a[N];
int main() {
  cin >> n;
  n <<= 1;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a+n);
  if (a[0] == a[n - 1]) {
    cout << -1 << endl;
    exit(0);
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i + 1 == n];
  }
}