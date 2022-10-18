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
  cin >> s;
  string ns;
  for (char c : s) {
    if (c != 'a')
      ns += c;
  }

  int len = ns.size();
  if (len % 2 != 0 || ns.substr(0, len / 2) != ns.substr(len / 2, len / 2)
    || s.substr(s.size() - len / 2, len / 2) != ns.substr(len / 2, len / 2)) {
    cout << ":(" << endl;
    return 0;
  }

  cout << s.substr(0, s.size() - len / 2) << endl;

  return 0;
}