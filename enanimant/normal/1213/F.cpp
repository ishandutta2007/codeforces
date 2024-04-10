// August 30, 2019
// https://codeforces.com/contest/1213/problem/F
 
/*
 
*/
 
 
#include <bits/stdc++.h>
 
using namespace std;
 
 
const int N = 200005;
 
 
int n, k;
int p[2][N];
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
 
 
  cin >> n >> k;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
      p[i][j]--;
    }
  }
  set<int> s;
  vector<int> perm;
  int cnt = 0;
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    perm.push_back(p[0][i]);
    for (int j = 0; j < 2; j++) {
      if (s.count(p[j][i])) {
        s.erase(p[j][i]);
      } else {
        s.insert(p[j][i]);
      }
    }
    if (s.empty()) {
      for (int j : perm) {
        ans[j] = cnt;
      }
      cnt++;
      perm.clear();
    }
  }
  if (cnt < k) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << (char) ('a' + min(ans[i], 25));
  }
  cout << '\n';
 
 
  return 0;
}