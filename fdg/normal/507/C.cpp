#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  long long h, n, ans = 0;
  cin >> h >> n;
  long long cur = 1, dr = 0, add = 1LL << h;
  long long l = 1, r = (1LL << h);
  while (l != r) {
    long long m = (l + r) >> 1;
    bool in_l = n <= m;
    if (dr == 0) {
      if (in_l) r = m, dr ^= 1;
      else {
        l = m + 1;
        ans += add - 1;
      }
    } else {
      if (!in_l) l = m + 1, dr ^= 1;
      else {
        r = m;
        ans += add - 1;
      } 
    }
    add /= 2; ++ans;
    // cout << ans << "  " << l << " " << r << endl;
  }
  cout << ans << endl;
  return 0;
}