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
  int many[2][2] = {0};
  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    many[0][l]++;
    many[1][r]++;
  }

  int ret = 0;

  for (int s = 0; s < 2; s++)
    ret += min(many[s][0], many[s][1]);
  
  cout << ret << endl;

  return 0;
}