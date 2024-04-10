#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0)
      cnt0++;
    else
      cnt1++;
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      x--;
      if (a[x] == 0)
        cnt0--, cnt1++;
      else
        cnt1--, cnt0++;
      a[x] = 1 - a[x];
    }
    if (t == 2) {
      int k;
      cin >> k;
      if (k <= cnt1)
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
  }
  return 0;
}