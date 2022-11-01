/*
 * author:  ADMathNoob
 * created: 02/07/21 08:39:23
 * problem: https://codeforces.com/contest/1479/problem/C
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1479C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1479C.cpp -ggdb && gdb a
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


  int L, R;
  cin >> L >> R;

  vector<tuple<int, int, long long>> edges;
  auto Add = [&](int u, int v, long long w) {
    assert(w >= 1);
    // if (true) {
    if (w <= R) {
      edges.emplace_back(u, v, w);
    }
  };

  int n = 32;
  for (int i = 2; i <= n - 1; i++) {
    // paths from i to n have lengths [1, 2^{n - 1 - i}]
    long long x = 1;
    for (int j = n; j > i; j--) {
      if (j == n) {
        Add(i, j, 1);
        x += 1;
      } else {
        Add(i, j, x - 1);
        x += (1LL << (n - 1 - j));
      }
    }
  }
  if (L == 1) {
    Add(1, n, 1);
    L += 1;
  }
  while (L <= R) {
    int sz = R - L + 1;
    int h = n - 1;
    while ((1 << (n - 1 - (h - 1))) <= sz) {
      h -= 1;
    }
    Add(1, h, L - 1);
    L += (1 << (n - 1 - h));
  }
  
  cout << "YES\n";
  cout << n << ' ' << edges.size() << '\n';
  for (const auto& t : edges) {
    int u, v, w;
    tie(u, v, w) = t;
    cout << u << ' ' << v << ' ' << w << '\n';
  }


  return 0;
}