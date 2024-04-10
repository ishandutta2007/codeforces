// November 13, 2020
// https://codeforces.com/contest/1438/problem/A

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1438A.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1438A.cpp -ggdb && gdb a
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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    int x = 0;
    for (int i = 0; i < n; i++) {
      x ^= a[i];
    }
    if (x != 0) {
      cout << "NO\n";
      return 0;
    }
    --n;
  }
  cout << "YES\n";
  cout << n - 1 << '\n';
  for (int i = 1; i < n; i += 2) {
    cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
  }
  for (int i = 1; i < n; i += 2) {
    cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
  }


  return 0;
}