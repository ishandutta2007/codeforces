// October 6, 2019
// http://codeforces.com/contest/1240/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      v[i] = a[i];
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }
    int m = (int) v.size();
    vector<pair<int, int>> pos(m, make_pair(n, -1));
    for (int i = 0; i < n; i++) {
      pos[a[i]].first = min(pos[a[i]].first, i);
      pos[a[i]].second = max(pos[a[i]].second, i);
    }
    vector<int> best(m);
    iota(best.begin(), best.end(), 0);
    for (int i = m - 2; i >= 0; i--) {
      if (pos[i].second < pos[i + 1].first) {
        best[i] = best[i + 1];
      }
    }
    int ans = m;
    for (int i = 0; i < m; i++) {
      // move i - 1, i - 2, ..., 0 to start
      ans = min(ans, i + (m - 1 - best[i]));
    }
    cout << ans << '\n';
  }


  return 0;
}