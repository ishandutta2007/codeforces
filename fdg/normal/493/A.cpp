#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

map<int, int> f[2];

int main() {
  string s[2];
  int n;
  cin >> s[0] >> s[1] >> n;
  while (n--) {
    int t, num;
    char team, col;
    cin >> t >> team >> num >> col;
    int tn = 0;
    if (team == 'h') tn = 0;
    else tn = 1;
    int val = 0;
    if (col == 'y') val = 1;
    else val = 2;
    if (f[tn][num] < 2 && f[tn][num] + val >= 2) {
      cout << s[tn] << " " << num << " " << t << endl;
    }
    f[tn][num] += val;
  }
  return 0;
}