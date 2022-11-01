// October 10, 2020
// https://codeforces.com/contest/1427/problem/A

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427A.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427A.cpp -ggdb && gdb a
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
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > 0) {
        pos += a[i];
      } else {
        neg += a[i];
      }
    }
    if (pos + neg == 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      sort(a.begin(), a.end());
      if (pos + neg > 0) {
        reverse(a.begin(), a.end());
      }
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << a[i];
      }
      cout << '\n';
    }
  }


  return 0;
}