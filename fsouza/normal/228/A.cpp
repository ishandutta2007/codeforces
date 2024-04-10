#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
  int s[4];

  for (int i = 0; i < 4; i++) cin >> s[i];
  sort(s, s+4);
  int diff = unique(s,s+4) - s;

  cout << 4 - diff << endl;

  return 0;
}