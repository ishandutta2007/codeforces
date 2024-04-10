// May 1, 2020
// https://codeforces.com/contest/1348/problem/B

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if ((int) a.size() > k) {
      cout << "-1\n";
      continue;
    }
    while ((int) a.size() < k) {
      a.push_back(a.back());
    }
    cout << n * k << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        if (i > 0 || j > 0) {
          cout << ' ';
        }
        cout << a[j];
      }
    }
    cout << '\n';
  }


  return 0;
}