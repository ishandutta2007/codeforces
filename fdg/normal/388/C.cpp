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
  int n, a = 0, b = 0;
  vector<int> v;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int s, x;
    scanf("%d", &s);
    for (int j = 1; j <= s; ++j) {
      scanf("%d", &x);
      if ((s & 1) && j == (s + 1) / 2) {
        v.push_back(x);
        continue;
      }
      if (j <= s / 2) {
        a += x;
      } else {
        b += x;
      }
    }
  }
  // cout << a << "  " << b << endl;
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < v.size(); ++i) {
    if (i & 1) b += v[i];
    else a += v[i];
  }
  cout << a << " " << b << endl;
  return 0;
}