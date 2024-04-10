// August 30, 2020
// https://codeforces.com/contest/1396/problem/A

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1396A.cpp -o a.out && a.out
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
  if (n <= 3) {
    for (int i = 0; i < n; i++) {
      cout << i + 1 << ' ' << i + 1 << '\n';
      cout << -a[i] << '\n';
    }
    for (int i = n; i < 3; i++) {
      cout << "1 1\n0\n";
    }
    return 0;
  }
  cout << "1 " << n << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << ' ';
    }
    if (i < n - 1) {
      cout << (long long) -a[i] * n;
    } else {
      cout << 0;
    }
  }
  cout << '\n';
  cout << "1 " << n - 1 << '\n';
  for (int i = 0; i < n - 1; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << (long long) a[i] * (n - 1);
  }
  cout << '\n';
  cout << n << ' ' << n << '\n';
  cout << -a[n - 1] << '\n';
  
  
  return 0;
}