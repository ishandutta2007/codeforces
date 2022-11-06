#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

typedef long long lint;

using namespace std;

int main() {
  bool ok = true;

  for (int y = 0; y < 8; y++) {
    char last = '\0';
    for (int x = 0; x < 8; x++) {
      char c;
      cin >> c;
      if (c == last) ok = false;
      last = c;
    }
  }

  cout << (ok ? "YES" : "NO") << endl;

  return 0;
}