#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int ans = 0;
char to[256][256];
string s;

void go(int left) {
  if (left == 0) {
    // cout << s << endl;
    string tmp = s;
    while (tmp.size() > 1) {
      char c = to[tmp[0]][tmp[1]];
      if (c != 0) {
        tmp = tmp.substr(2);
        tmp = string(1, c) + tmp;
      } else {
        break;
      }
    }
    if (tmp == "a") ++ans;
    return;
  }

  for (char c = 'a'; c <= 'f'; ++c) {
    s += c;
    go(left - 1);
    s.pop_back();
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    string a, b;
    cin >> a >> b;
    to[a[0]][a[1]] = b[0];
  }

  go(n);
  cout << ans << endl;

  return 0;
}