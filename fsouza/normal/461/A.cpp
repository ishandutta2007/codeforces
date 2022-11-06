#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  sort(a.begin(), a.end());

  lint ret = 0;

  for (int i = 0; i < n; i++) {
    ret += a[i];
    if (i+1 < n) ret += (lint)a[i] * (i+1);
    else ret += (lint)a[i] * i;
  }

  cout << ret << endl;

  return 0;
}