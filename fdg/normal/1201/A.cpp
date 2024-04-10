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
  string s[1002];
  for (int i = 0; i < n; ++i)
    cin >> s[i];
  int ans = 0;
  for (int j = 0; j < m; ++j) {
    int a = 0, cnt = 0;
    cin >> a;
    map<char, int> f;
    for (int i = 0; i < n; ++i) {
      f[s[i][j]]++;
      cnt = max(cnt, f[s[i][j]]);
    }
    ans += a * cnt;
  }
  cout << ans << endl;
  return 0;
}