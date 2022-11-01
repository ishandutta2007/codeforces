/*
 * author:  ADMathNoob
 * created: 04/23/22 10:05:28
 * problem: https://codeforces.com/contest/1672/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

int Ask(int w) {
  // print query; don't forget to flush the output
  cout << "? " << w << endl;
  int res;
  cin >> res;
  return res;
}

void Answer(int ans) {
  // print the answer; don't forget to flush the output
  cout << "! " << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int low = 1, high = 2000 * n;
  while (low < high) {
    int mid = (low + high) / 2;
    int h = Ask(mid + (n - 1));
    if (h == 1) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  int s = low;
  int ans = s + n - 1;
  for (int r = 1; r <= n; r++) {
    // use r rows
    // best possible is: s + (n - 1) - (r - 1), since we eliminate up to r-1 spaces
    // since the response must be a multiple of r, we only care about exactly one of
    // s + (n - 1) - (r - 1) + k for k = 0, 1, ..., r-1.
    // this would use ceil((s + (n - 1) - (r - 1)) / r) rows
    int w = (s + (n - 1) - (r - 1) + (r - 1)) / r;
    assert(w > 0);
    int h = Ask(w);
    if (h > 0) {
      ans = min(ans, h * w);
    }
  }
  Answer(ans);
  return 0;
}