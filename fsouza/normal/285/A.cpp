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
  int n, k;
  vector<int> ret;

  cin >> n >> k;

  for (int v = k+1; v >= 1; v--) ret.push_back(v);
  for (int v = k+2; v <= n; v++) ret.push_back(v);

  for (int i = 0; i < n; i++) {
    if (i-1 >= 0) cout << " ";
    cout << ret[i];
  }
  cout << endl;

  return 0;
}