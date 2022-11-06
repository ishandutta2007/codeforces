#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>

typedef long long lint;

using namespace std;

int main() {
  vector <string> s(4);

  for (int y = 0; y < 4; y++)
    cin >> s[y];

  bool ret = false;
  for (int y = 0; y+1 < 4; y++)
    for (int x = 0; x+1 < 4; x++) {
      int m = (s[y][x] == '.') + (s[y+1][x] == '.') + (s[y][x+1] == '.') + (s[y+1][x+1] == '.');
      ret |= (m != 2);
    }

  cout << (ret ? "YES" : "NO") << endl;

  return 0;
}