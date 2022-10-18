#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  int cntA = 0;
  for (char c : s) {
    cntA += (c == 'a');
  }
  cout << min((int) s.size(), 2 * cntA - 1) << endl;
  return 0;
}