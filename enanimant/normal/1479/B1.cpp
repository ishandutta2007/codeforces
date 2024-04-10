/*
 * author:  ADMathNoob
 * created: 02/07/21 08:39:23
 * problem: https://codeforces.com/contest/1479/problem/B1
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1479B1.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1479B1.cpp -ggdb && gdb a
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
  vector<int> a;
  vector<int> same;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i >= 2 && x == a.back() && x == a[a.size() - 2]) {
      continue;
    }
    if (!a.empty() && x == a.back()) {
      same.push_back((int) a.size() - 1);
    }
    a.push_back(x);
  }
  n = (int) a.size();
  vector<int> nex(n);
  int s = -1;
  for (int i = n - 1; i >= 0; i--) {
    nex[i] = (s == -1 ? -2 : a[s]);
    if (!same.empty() && i == same.back()) {
      s = same.back();
      same.pop_back();
    }
  }
  vector<int> c(1, -1), d(1, -1);
  for (int i = 0; i < n; i++) {
    if (a[i] == d.back() && a[i] != c.back()) {
      c.push_back(a[i]);
      continue;
    }
    if (a[i] == c.back() && a[i] != d.back()) {
      d.push_back(a[i]);
      continue;
    }
    if (c.back() == nex[i]) {
      c.push_back(a[i]);
    } else {
      d.push_back(a[i]);
    }
  }
  int ans = 0;
  for (int rot = 0; rot < 2; rot++) {
    for (int i = 0; i < (int) c.size() - 1; i++) {
      if (c[i] != c[i + 1]) {
        ans += 1;
      }
    }
    swap(c, d);
  }
  // for (int i : c) cerr << i << ' '; cerr << '\n';
  // for (int i : d) cerr << i << ' '; cerr << '\n';
  // int ans = 0;
  // for (int i = 0; i < n - 1; i++) {
  //   if (a[i] != a[i + 1]) {
  //     ans += 1;
  //   }
  // }
  // if (!same.empty()) {
  //   ans += 1;
  //   for (int i = 0; i < (int) same.size() - 1; i++) {
  //     int x = same[i];
  //     int y = same[i + 1];
  //     if (a[x] != a[y] || y - x >= 4) {
  //       ans += 1;
  //     }
  //   }
  // }
  cout << ans << '\n';


  return 0;
}