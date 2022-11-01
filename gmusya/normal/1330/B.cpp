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
    vector <int> cnt(n);
    vector <int> pre(n), suf(n);
    int ma = 0;
    for (int i = 0; i < n; i++) {
      cnt[a[i]]++;
      ma = max(a[i], ma);
      if (cnt[a[i]] == 2)
        break;
      if (ma == i + 1)
        pre[i] = 1;
    }
    cnt.assign(n, 0);
    ma = 0;
    for (int i = n - 1; i >= 0; i--) {
      cnt[a[i]]++;
      ma = max(a[i], ma);
      if (cnt[a[i]] == 2)
        break;
      if (ma == n - i)
        suf[i] = 1;
    }
    vector <int> ans;
    for (int i = 0; i + 1 < n; i++)
      if (pre[i] && suf[i + 1])
        ans.push_back(i + 1);
    cout << ans.size() << '\n';
    for (auto &now : ans)
      cout << now << ' ' << n - now << '\n';
  }
  return 0;
}