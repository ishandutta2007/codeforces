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
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) cin >> d[i];
  int s, t;
  cin >> s >> t; s--, t--;

  int ret0 = 0, ret1 = 0;

  for (int x = s; x != t; x = (x+1)%n)
    ret0 += d[x];
  for (int x = t; x != s; x = (x+1)%n)
    ret1 += d[x];

  cout << min(ret0, ret1) << endl;

  return 0;
}