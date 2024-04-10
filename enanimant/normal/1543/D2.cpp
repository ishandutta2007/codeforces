/*
 * author:  ADMathNoob
 * created: 07/07/21 10:37:03
 * problem: https://codeforces.com/contest/1543/problem/D2
 */

/*
g++ 1543D2.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1543D2.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

bool Ask(int g) {
  cout << g << endl;
  int r;
  cin >> r;
  return r;
}

const int D = 20; // maximum number of digits in base k

int k;

int Xor(int x, int y) {
  int p = 1;
  int ret = 0;
  for (int j = 0; j < D; j++) {
    ret += ((x + y) % k) * p;
    p *= k;
    x /= k;
    y /= k;
    if (x == 0 && y == 0) {
      break;
    }
  }
  return ret;
}

int Negate(int x) {
  int p = 1;
  int ret = 0;
  for (int j = 0; j < D; j++) {
    int d = (k - x % k) % k;
    ret += d * p;
    p *= k;
    x /= k;
    if (x == 0) {
      break;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n >> k;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      int j = (i % 2 == 0 ? i : Negate(i));
      int a = Xor(cur, j);
      if (Ask(a)) {
        break;
      }
      cur = Xor(a, Negate(cur));
    }
  }
  return 0;
}