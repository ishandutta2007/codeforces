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
  int n, m;
  cin >> n >> m;
  int left = m, ans = 1, a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a <= left) {
      left -= a;
    } else {
      left = m - a;
      ++ans;
    }
  } 
  cout << ans << endl;
  return 0;
}