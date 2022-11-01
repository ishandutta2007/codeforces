// December 6, 2020
// https://codeforces.com/contest/1450/problem/D

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1450D.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1450D.cpp -ggdb && gdb a
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
    vector<deque<int>> p(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
      p[a[i]].push_back(i);
    }
    auto b = a;
    sort(b.begin(), b.end());
    bool is_perm = true;
    for (int i = 0; i < n; i++) {
      if (b[i] != i) {
        is_perm = false;
      }
    }
    cout << (is_perm ? 1 : 0);
    int res = 2;
    int l = 0, r = n - 1;
    for (int x = 0; x < n; x++) {
      while (!p[x].empty() && p[x][0] < l) {
        p[x].pop_front();
      }
      while (!p[x].empty() && p[x].back() > r) {
        p[x].pop_back();
      }
      if (p[x].empty()) {
        res = r - l + 2;
        break;
      }
      if (p[x][0] != p[x].back()) {
        res = r - l + 1;
        break;
      }
      if (p[x][0] == l) {
        ++l;
        continue;
      }
      if (p[x][0] == r) {
        --r;
        continue;
      }
      res = r - l + 1;
      break;
    }
    for (int i = 2; i <= n; i++) {
      if (i >= res) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << '\n';
  }


  return 0;
}