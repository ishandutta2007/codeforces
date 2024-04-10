#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define se second

using namespace std;

typedef pair <int, int> pii;

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
    vector <pii> pre(n), suf(n);
    pre[0] = {a[0], 0};
    for (int i = 1; i < n; i++)
      pre[i] = min(pre[i - 1], {a[i], i});
    suf[n - 1] = {a[n - 1], n - 1};
    for (int i = n - 2; i >= 0; i--)
      suf[i] = min(suf[i + 1], {a[i], i});
    bool flag = false;
    for (int i = 1; i + 1 < n; i++) {
      if (flag)
        break;
      if (a[i] > pre[i - 1].fi && a[i] > suf[i + 1].fi) {
        flag = true;
        cout << "YES\n";
        cout << pre[i - 1].se + 1 << ' ' << i + 1 << ' ' << suf[i + 1].se + 1 << '\n';
      }
    }
    if (!flag)
      cout << "NO\n";
  }
  return 0;
}