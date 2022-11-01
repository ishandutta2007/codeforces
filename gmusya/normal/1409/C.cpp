#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> ans(n, INF);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if ((y - x) % (j - i)) continue;
        int d = (y - x) / (j - i);
        vector <int> a(n);
        a[i] = x, a[j] = y;
        for (int id = i - 1; id >= 0; id--)
          a[id] = a[id + 1] - d;
        for (int id = 1; id < n; id++)
          a[id] = a[id - 1] + d;
        if (a[0] <= 0) continue;
        if (a[n - 1] >= ans[n - 1]) continue;
        ans = a;
      }
    for (auto &now : ans)
      cout << now << ' ';
    cout << '\n';
  }
  return 0;
}