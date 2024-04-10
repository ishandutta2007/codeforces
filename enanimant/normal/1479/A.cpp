/*
 * author:  ADMathNoob
 * created: 02/07/21 08:39:23
 * problem: https://codeforces.com/contest/1479/problem/A
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1479A.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1479A.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


const int INF = (int) 1e9;

int n;
map<int, int> mp;

int Ask(int i, char c = '?') {
  if (c == '?' && mp.count(i)) {
    return mp[i];
  }
  if (c == '?' && (i == -1 || i == n)) {
    return INF;
  }
  cout << c << " " << i + 1 << endl;
  if (c == '!') {
    exit(0);
  }
  cin >> mp[i];
  return mp[i];
}

int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

// #ifdef _DEBUG
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
//   freopen("debug_output.txt", "w", stderr);
// #endif


  cin >> n;
  int l = -1, r = n;
  int m = (l + r) / 2;
  while (r - l >= 4) {
    int x = (l + m) / 2;
    int y = (m + r) / 2;
    if (Ask(x) < Ask(m)) {
      r = m;
      m = x;
      continue;
    }
    if (Ask(y) < Ask(m)) {
      l = m;
      m = y;
      continue;
    }
    l = x;
    r = y;
  }
  for (int i = l + 1; i <= r - 1; i++) {
    if (Ask(i) < min(Ask(i - 1), Ask(i + 1))) {
      Ask(i, '!');
    }
  }


  return 0;
}