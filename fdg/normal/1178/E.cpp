#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

string s, s1, s2;

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  int l = 0, r = s.size() - 1;
  while (l <= r) {
    // cout << l << "  " << r << " " << s1 << "  " << s2 << endl;
    if (l < r && s[l] == s[r]) {
      s1 += s[l];
      s2 += s[r];
      ++l; --r;
      continue;
    }
    if (l + 1 < r && s[l + 1] == s[r]) {
      s1 += s[l + 1];
      s2 += s[r];
      l += 2; --r;
      continue;
    }
    if (l < r - 1 && s[l] == s[r - 1]) {
      s1 += s[l];
      s2 += s[r - 1];
      ++l; r -= 2;
      continue;
    }
    if (l + 1 < r - 1 && s[l + 1] == s[r - 1]) {
      s1 += s[l + 1];
      s2 += s[r - 1];
      l += 2; r -= 2;
      continue;
    }
    s1 += s[l];
    break;
  }

  reverse(s2.begin(), s2.end());
  if (s1.size() + s2.size() < s.size() / 2)
     cout << "IMPOSSIBLE" << endl;
  else cout << s1 << s2 << endl;
  return 0;
}