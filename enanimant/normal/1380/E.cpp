// July 12, 2020
// https://codeforces.com/contest/1380/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n, m;
  cin >> n >> m;
  vector<set<int>> v(m);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    t--;
    v[t].insert(i);
  }
  vector<int> delta(m - 1, 0);
  for (int i = m - 2; i >= 0; i--) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (v[a].size() < v[b].size()) {
      swap(v[a], v[b]);
    }
    for (int x : v[b]) {
      auto it = v[a].lower_bound(x);
      if (it != v[a].end() && *it == x + 1) {
        delta[i]++;
      }
      if (it != v[a].begin() && *(--it) == x - 1) {
        delta[i]++;
      }
    }
    for (int x : v[b]) {
      v[a].insert(x);
    }
  }
  vector<int> ans(m, 0);
  for (int i = 0; i < m - 1; i++) {
    ans[i + 1] = ans[i] + delta[i];
  }
  for (int i = m - 1; i >= 0; i--) {
    cout << ans[i] << '\n';
  }
  
  
  return 0;
}