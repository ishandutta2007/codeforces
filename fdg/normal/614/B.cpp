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
  ios::sync_with_stdio(false);
  int n, add = 0, was = 0;
  string tmp;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    bool ok = true;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != '0') ok = false;
    }
    if (ok && s[0] == '0') {
      cout << 0 << endl;
      return 0;
    }
    if (!ok || s[0] > '1') {
      tmp = s;
      was = true;
    } else add += s.size() - 1;
  }
  if (!was) cout << 1;
  else cout << tmp;
  cout << string(add, '0') << endl;
  return 0;
}