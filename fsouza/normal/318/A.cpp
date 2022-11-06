#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  lint n, k;

  cin >> n >> k; k--;

  lint nodd = (n+1)/2;

  if (k < nodd) cout << 1 + k*2 << endl;
  else cout << 2 + (k-nodd) * 2 << endl;

  return 0;
}