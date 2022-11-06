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
  vector<int> h(n), a(n);

  map <int, int> manya;

  for (int i = 0; i < n; i++) {
    cin >> h[i] >> a[i];
    manya[a[i]]++;
  }

  int ret = 0;

  for (int i = 0; i < n; i++) {
    int m = manya[h[i]];
    ret += m;
  }

  cout << ret << endl;

  return 0;
}