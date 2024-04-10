#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> cnt(n), cnt0(n), cnt1(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      int c;
      cin >> c;
      cnt[x]++;
      if (c == 0)
        cnt0[x]++;
      else
        cnt1[x]++;
    }
    set<pair<pair<int, int>, int>> s;
    for (int i = 0; i < n; i++)
      s.insert({{cnt[i], cnt1[i]}, i});
    int ans = 0, ans1 = 0;
    while (!s.empty()) {
      int v = s.rbegin()->second;
      if (cnt[v] == 0)
        break;
      s.erase({{cnt[v], cnt1[v]}, v});
      ans += cnt[v];
      ans1 += cnt1[v];
      vector<int> ids;
      while (!s.empty()) {
        if (s.rbegin()->first.first != cnt[v])
          break;
        int u = s.rbegin()->second;
        ids.push_back(u);
        s.erase({{cnt[u], cnt1[u]}, u});
      }
      for (int u : ids) {
        cnt[u]--;
        if (cnt1[u] > cnt[u])
          cnt1[u]--;
        s.insert({{cnt[u], cnt1[u]}, u});
      }
    }
    cout << ans << ' ' << ans1 << '\n';
  }
  return 0;
}