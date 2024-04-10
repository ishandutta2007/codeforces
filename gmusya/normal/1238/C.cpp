#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int h, n;
    cin >> h >> n;
    vector <int> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];
    int ans = 0;
    int pos = 0;
    for (int i = 0; i < n; i++) {
      if (i && p[i - 1] > p[i] + 1) {
        if (pos > 0)
          ans += (i + pos) % 2;
        else
          ans += 1 - (i + pos) % 2;
        pos = i;
      }
    }
    if (p.back() > 1) {
      if (pos > 0)
        ans += (n - pos) % 2;
      else
        ans += 1 - (n - pos) % 2;
    }
    cout << ans << '\n';
  }
  return 0;
}