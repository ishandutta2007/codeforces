// July 21, 2020
// https://codeforces.com/contest/1381/problem/C

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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> b(n);
    vector<vector<int>> pos(n + 1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      b[i]--;
      pos[b[i]].push_back(i);
      if (pos[b[i]].size() > pos[mx].size()) {
        mx = b[i];
      }
    }
    int f = 0;
    while (!pos[f].empty()) {
      f++;
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i <= n; i++) {
      q.emplace((int) pos[i].size(), i);
    }
    vector<int> a(n, f);
    int k = x;
    while (k > 0) {
      k--;
      int sz, c;
      tie(sz, c) = q.top();
      q.pop();
      a[pos[c].back()] = c;
      pos[c].pop_back();
      sz--;
      q.emplace(sz, c);
    }
    
    // for (int i = 0; i < n; i++) {
    //   if (i > 0) {
    //     cerr << ' ';
    //   }
    //   cerr << a[i] + 1;
    // }
    // cerr << '\n';
    
    vector<int> v;
    vector<int> color;
    for (int i = 0; i <= n; i++) {
      int s = (int) pos[i].size();
      int add = min(s, n - x - s);
      v.insert(v.end(), pos[i].begin(), pos[i].begin() + add);
      color.insert(color.end(), add, i);
    }
    if (y - x > (int) v.size()) {
      cout << "NO\n";
      continue;
    }
    int rot = (int) v.size() / 2;
    
    if (x != n) {
      for (int i = 0; i < y - x; i++) {
        a[v[i]] = color[(i + rot) % v.size()];
      }
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << a[i] + 1;
    }
    cout << '\n';
    
    // cerr << "check:\n";
    // for (int i = 0; i < n; i++) {
    //   if (i > 0) {
    //     cerr << ' ';
    //   }
    //   cerr << a[i] + 1;
    // }
    // cerr << '\n';
    // for (int i = 0; i < n; i++) {
    //   if (i > 0) {
    //     cerr << ' ';
    //   }
    //   cerr << b[i] + 1;
    // }
    // cerr << '\n';
  }
  
  
  return 0;
}