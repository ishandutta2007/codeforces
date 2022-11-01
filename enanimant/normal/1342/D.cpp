// April 26, 2020
// https://codeforces.com/contest/1342/problem/D

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


  int n, k;
  cin >> n >> k;
  vector<int> cnt(k + 1, 0);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    cnt[m]++;
  }
  vector<int> mx(k + 1, 0);
  for (int i = 1; i <= k; i++) {
    cin >> mx[i];
  }
  vector<vector<int>> ans;
  int ptr;
  for (int i = k; i >= 1; i--) {
    if (i == k || mx[i] > mx[i + 1]) {
      ptr = 0;
    }
    while (cnt[i] > 0) {
      if ((int) ans.size() == ptr) {
        ans.emplace_back();
      }
      while (cnt[i] > 0 && (int) ans[ptr].size() < mx[i]) {
        ans[ptr].push_back(i);
        cnt[i]--;
      }
      if ((int) ans[ptr].size() == mx[i]) {
        ptr++;
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i].size();
    for (int j = 0; j < (int) ans[i].size(); j++) {
      cout << ' ' << ans[i][j];
    }
    cout << '\n';
  }


  return 0;
}