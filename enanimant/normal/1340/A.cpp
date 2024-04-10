// April 23, 2020
// https://codeforces.com/contest/1340/problem/A

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
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      a--;
      pos[a] = i;
    }
    vector<bool> taken(n, false);
    int l = n;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      ok &= (((i > 0) && pos[i] == pos[i - 1] + 1) || i + l == n);
      l = min(l, pos[i]);
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }


  return 0;
}