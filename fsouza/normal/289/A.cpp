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
  cin >> n >> k;
  int val = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    val += r-l+1;
  }
  int ret = (k-val%k)%k;
  cout << ret << endl;
  return 0;
}