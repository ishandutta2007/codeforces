#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);

  int s, b; cin >> s >> b;
  vector<int> a(s); for (int i = 0; i < s; ++i) cin >> a[i];
  vector<pair<int, long long> > gd(b);
  for (int i = 0; i < b; ++i) cin >> gd[i].first >> gd[i].second;
  sort(gd.begin(), gd.end());
  for (int i = 1; i < b; ++i) gd[i].second += gd[i - 1].second;
  gd.insert(gd.begin(), {0, 0});
  for (int i = 0; i < s; ++i) {
    cout << (*prev(upper_bound(gd.begin(), gd.end(), make_pair(a[i], INT_FAST64_MAX)))).second << (i == s - 1 ? '\n' : ' ');
  }
  return 0;
}