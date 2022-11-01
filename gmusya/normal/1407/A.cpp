#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i])
        cnt1++;
      else
        cnt0++;
    }
    if (cnt0 >= n / 2) {
      cout << n / 2 << '\n';
      for (int i = 0; i < n / 2; i++)
        cout << 0 << ' ';
    } else {
      int k = n / 2;
      if (k & 1)
        k++;
      cout << k << '\n';
      for (int i = 0; i < k; i++)
        cout << 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}