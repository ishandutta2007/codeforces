#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

template<typename T, typename Cmp=less<pair<T, int>>>
struct RMQ {
  Cmp cmp;
  vector<vector<pair<T, int>>> table;
  RMQ(const vector<T> &values) {
    int n = values.size();
    table.resize(__lg(n)+1);
    table[0].resize(n);
    for (int i = 0; i < n; ++i) table[0][i] = make_pair(values[i], i);
    for (int l = 1; l < (int)table.size(); ++l) {
      table[l].resize(n - (1<<l) + 1);
      for (int i = 0; i + (1<<l) <= n; ++i)
	table[l][i] = min(table[l-1][i], table[l-1][i+(1<<(l-1))], cmp);
    }
  }
  pair<T, int> query(int a, int b) {
    int l = __lg(b-a+1);
    return min(table[l][a], table[l][b-(1<<l)+1], cmp);
  }
};


int main() {
  int n;
  scanf("%d", &n);
  vector<int> lim(n);
  for (int i = 0; i < n-1; ++i) scanf("%d", &lim[i]), --lim[i];
  lim[n-1] = n-1;

  RMQ<int, greater<pair<int, int>>> rmq(lim);
  vector<lint> result(n);

  for (int i = n-1; i >= 0; --i) {
    if (lim[i] == n-1) result[i] = n-1-i;
    else {
      int j = rmq.query(i+1, lim[i]).second;
      result[i] = result[j] + (j-i) + (n-1-lim[i]);
    }
  }

  lint answer = 0;
  for (lint v : result) answer += v;
  printf("%lld\n", answer);

  return 0;
}