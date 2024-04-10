/*
 * author:  ADMathNoob
 * created: 05/05/21 16:27:11
 * problem: https://codeforces.com/contest/1520/problem/F2
 */

/*
g++ 1520F2.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1520F2.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3


*/

#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int res[2 * N];

int Ask(int L, int R) {
  cout << "? " << L + 1 << " " << R + 1 << endl;
  int r;
  cin >> r;
  return r;
}

void Answer(int i) {
  cout << "! " << i + 1 << endl;
}

int Solve(int x, int l, int r, int k) {
  // want k-th zero (0-indexed) in [l, r]
  if (l == r) {
    assert(k == 0);
    return l;
  }
  int y = (l + r) >> 1;
  int z = x + ((y - l + 1) << 1);
  if (res[x + 1] == -1) {
    res[x + 1] = Ask(l, y);
  }
  int zeros_on_left = (y - l + 1) - res[x + 1];
  if (k < zeros_on_left) {
    return Solve(x + 1, l, y, k);
  }
  return Solve(z, y + 1, r, k - zeros_on_left);
}

void Update(int x, int l, int r, int p) {
  res[x] += 1;
  if (l == r) {
    return;
  }
  int y = (l + r) >> 1;
  int z = x + ((y - l + 1) << 1);
  if (p <= y) {
    Update(x + 1, l, y, p);
  } else {
    Update(z, y + 1, r, p);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, tt;
  cin >> n >> tt;
  fill(res, res + 2 * N, -1);
  while (tt--) {
    int k;
    cin >> k;
    --k;
    int ans = Solve(0, 0, n - 1, k);
    Answer(ans);
    Update(0, 0, n - 1, ans);
  }
  return 0;
}