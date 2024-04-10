#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << (a[l] - 2) + (k - a[r] - 1) + 2 * ((a[r] - a[l]) - (r - l - 1)) << '\n';
  }
  return 0;
}