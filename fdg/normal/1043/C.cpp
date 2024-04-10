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
  string s;
  int ans[1001] = {0};
  cin >> s;

  bool rev = false;
  for (int i = s.size() - 1; i >= 0; --i) {
    if ((s[i] == 'a') != rev) {
      ans[i] = 1;
      rev ^= 1;
    }
  }

  for (int i = 0; i < s.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}