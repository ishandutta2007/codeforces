// September 6, 2020
// https://codeforces.com/contest/1404/problem/A

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1404A.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1404A.cpp -ggdb && gdb a
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
    string s;
    cin >> n >> k >> s;
    vector<int> a(k, -1);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        continue;
      }
      if (a[i % k] == -1 || a[i % k] == s[i] - '0') {
        a[i % k] = s[i] - '0';
      } else {
        ok = false;
      }
    }
    int sum = 0;
    for (int i = 0; i < k; i++) {
      if (a[i] != -1) {
        sum += a[i];
      }
    }
    for (int i = 0; i < k; i++) {
      if (a[i] == -1) {
        a[i] = (sum < k / 2 ? 1 : 0);
        sum += a[i];
      }
    }
    if (sum != k / 2) {
      ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  
  
  return 0;
}