#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector <int> d(n), h(n);
    int ma = 0, diff = 0;
    for (int i = 0; i < n; i++)
      cin >> d[i] >> h[i];
    for (int i = 0; i < n; i++)
      ma = max(ma, d[i]), diff = max(diff, d[i] - h[i]);
    if (ma >= x) {
      cout << 1 << '\n';
      continue;
    }
    if (!diff) {
      cout << -1 << '\n';
      continue;
    }
    cout << (x - ma + diff - 1) / diff + 1 << '\n';
  }
  return 0;
}