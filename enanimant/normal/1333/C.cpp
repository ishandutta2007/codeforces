// April 8, 2020
// https://codeforces.com/contest/1333/problem/C

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


  int n;
  cin >> n;
  vector<int> a(n);
  vector<long long> psa(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    psa[i + 1] = psa[i] + a[i];
  }
  vector<long long> v = psa;
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  vector<int> id(n + 1);
  vector<vector<int>> pos(n + 1);
  for (int i = 0; i <= n; i++) {
    id[i] = lower_bound(v.begin(), v.end(), psa[i]) - v.begin();
    pos[id[i]].push_back(i);
  }
  for (int i = 0; i <= n; i++) {
    pos[i].push_back(n + 1);
  }
  long long ans = 0;
  int mn = n + 1;
  for (int i = n - 1; i >= 0; i--) {
    int x = *upper_bound(pos[id[i]].begin(), pos[id[i]].end(), i);
    mn = min(mn, x);
    ans += mn - i - 1;
  }
  cout << ans << '\n';


  return 0;
}