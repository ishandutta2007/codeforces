// August 30, 2020
// https://codeforces.com/contest/1396/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1396B.cpp -o a.out && a.out
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
    vector<int> a(n);
    int tot = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      tot += a[i];
      mx = max(mx, a[i]);
    }
    if (2 * mx > tot) {
      cout << "T\n";
      continue;
    }
    cout << (tot % 2 == 1 ? "T" : "HL") << '\n';
  }
  
  
  return 0;
}