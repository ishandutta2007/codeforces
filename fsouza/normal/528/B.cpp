#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <cassert>
#include <cmath>

#define MAXN 200000
#define INF 1000000000

using namespace std;

int a[MAXN], b[MAXN];
int bit[MAXN+1];

int bit_get(int x) {
  int res = 0;
  while (x > 0) {
    res = max(res, bit[x]);
    x -= x&-x;
  }
  return res;
}

void bit_add(int x, int val, int n) {
  while (x <= n) {
    bit[x] = max(bit[x], val);
    x += x&-x;
  }
}

int main() {
  int n;

  scanf("%d", &n);

  vector<pair<int, int> > xw;
  vector<int> bs;
  
  for (int i = 0; i < n; i++) {
    int x, w;
    scanf("%d %d", &x, &w);
    xw.push_back(make_pair(x, w));
  }

  sort(xw.begin(), xw.end());

  for (int i = 0; i < n; i++) {
    a[i] = xw[i].first - xw[i].second;
    b[i] = xw[i].first + xw[i].second;
    bs.push_back(b[i]);
  }
  sort(bs.begin(), bs.end());
  bs.resize(unique(bs.begin(), bs.end())-bs.begin());

  for (int i = 0; i < n; i++)
    b[i] = lower_bound(bs.begin(), bs.end(), b[i])-bs.begin();

  for (int i = 1; i <= n; i++)
    bit[i] = 0;
  
  int result = 0;

  for (int i = 0; i < n; i++) {
    int bid = upper_bound(bs.begin(), bs.end(), a[i]) - bs.begin() - 1;
    int res = bit_get(bid+1) + 1;
    bit_add(b[i]+1, res, n);
    result = max(result, res);
  }

  printf("%d\n", result);
  
  return 0;
}