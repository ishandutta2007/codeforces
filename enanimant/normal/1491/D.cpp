/*
 * author:  ADMathNoob
 * created: 02/28/21 08:33:49
 * problem: https://codeforces.com/contest/1491/problem/D
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491D.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491D.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1491D.cpp && a


*/

#include <bits/stdc++.h>

using namespace std;

const int B = 30;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif

  // {
  //   auto PrintBinary = [&](int x) {
  //     bool first = true;
  //     for (int i = B - 1; i >= 0; i--) {
  //       if (x & (1 << i)) {
  //         cerr << 1;
  //         first = false;
  //       } else {
  //         if (!first) {
  //           cerr << 0;
  //         }
  //       }
  //     }
  //     // cerr << '\n';
  //   };
  //   const int M = 50;
  //   for (int u = 1; u <= M; u++) {
  //     for (int v = 1; v <= M; v++) {
  //       if ((u & v) == v) {
  //         int x = u;
  //         int y = u + v;
  //         PrintBinary(x);
  //         cerr << ' ';
  //         PrintBinary(y);
  //         cerr << '\n';
  //         vector<int> bx, by;
  //         for (int i = B - 1; i >= 0; i--) {
  //           if (x & (1 << i)) {
  //             bx.push_back(i);
  //           }
  //           if (y & (1 << i)) {
  //             by.push_back(i);
  //           }
  //         }
  //         assert(bx.size() >= by.size());
  //         int p = 0;
  //         bool ok = true;
  //         for (int i = 0; i < (int) by.size(); i++) {
  //           while (p < (int) bx.size() && by[i] < bx[p]) {
  //             p += 1;
  //           }
  //           if (p == (int) bx.size()) {
  //             ok = false;
  //             break;
  //           }
  //           p += 1;
  //         }
  //         assert(ok);
  //       }
  //     }
  //   }
  // }

  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    vector<int> bx, by;
    for (int i = B - 1; i >= 0; i--) {
      if (x & (1 << i)) {
        bx.push_back(i);
      }
      if (y & (1 << i)) {
        by.push_back(i);
      }
    }
    bool ok = true;
    if (by.size() > bx.size() || x > y) {
      ok = false;
    }
    int p = 0;
    for (int i = 0; i < (int) by.size(); i++) {
      while (p < (int) bx.size() && by[i] < bx[p]) {
        p += 1;
      }
      if (p == (int) bx.size()) {
        ok = false;
        break;
      }
      p += 1;
    }
    cout << (ok ? "yes" : "no") << '\n';
  }

  return 0;
}