// July 24, 2020
// https://codeforces.com/contest/1383/problem/A

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
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      a[i] = c - 'a';
    }
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      b[i] = c - 'a';
    }
    bool ok = true;
    vector<set<int>> v(20);
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        ok = false;
        break;
      }
      if (a[i] < b[i]) {
        v[a[i]].insert(b[i]);
      }
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    int ans = 0;
    for (int j = 0; j < 20; j++) {
      if (!v[j].empty() && *v[j].begin() == j) {
        v[j].erase(j);
      }
      if (v[j].empty()) {
        continue;
      }
      ans++;
      int to = *v[j].begin();
      for (int k : v[j]) {
        v[to].insert(k);
      }
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}