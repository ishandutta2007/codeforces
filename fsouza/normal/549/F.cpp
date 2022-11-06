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

struct RMQ {
  vector<vector<pair<int, int>>> table;
  RMQ(vector<int> &values) {
    int n = values.size();
    int logn = 0;
    while ((1 << logn+1) <= n) ++logn;
    table.resize(logn+1, vector<pair<int, int>>(n));
    for (int i = 0; i < n; ++i)
      table[0][i] = make_pair(values[i], i);
    for (int l = 1; l <= logn; ++l)
      for (int i = 0; i + (1<<l) <= n; ++i)
	table[l][i] = max(table[l-1][i], table[l-1][i + (1<<l-1)]);
  }
  pair<int, int> query(int a, int b) {
    int size = b-a+1, l = __builtin_clz(1) - __builtin_clz(size);
    return max(table[l][a], table[l][b-(1<<l)+1]);
  }
};

lint solve(int a, int b, int div, vector<int> &values, RMQ &rmq, vector<vector<int>> &accs, vector<int> &acc) {
  int size = b-a+1;
  if (size == 0) return 0;
  if (size == 1) return 1;

  lint result = 0;
  int mid = rmq.query(a, b).second;

  if (mid-a < b-mid) {
    for (int i = a; i <= mid; ++i) {
      int left = (acc[mid] - acc[i] + div) % div;
      int right = (div - left) % div;
      int want = (right + acc[mid+1]) % div;
      vector<int> &pos = accs[want];
      result += upper_bound(pos.begin(), pos.end(), b+1) - lower_bound(pos.begin(), pos.end(), mid+1);
    }
  } else {
    for (int j = mid; j <= b; ++j) {
      int right = (acc[j+1] - acc[mid+1] + div) % div;
      int left = (div - right) % div;
      int want = (acc[mid] - left + div) % div;
      vector<int> &pos = accs[want];
      result += upper_bound(pos.begin(), pos.end(), mid) - lower_bound(pos.begin(), pos.end(), a);
    }
  }

  result += solve(a, mid-1, div, values, rmq, accs, acc) + solve(mid+1, b, div, values, rmq, accs, acc);

  return result;
}

int main() {
  int n, div;
  scanf("%d %d", &n, &div);
  vector<int> values(n);
  for (int &v : values) scanf("%d", &v);

  vector<vector<int>> accs(div);
  vector<int> acclist = {0};
  int acc = 0;
  accs[acc].push_back(0);
  for (int i = 1; i <= n; ++i) {
    acc = (acc + values[i-1]) % div;
    acclist.push_back(acc);
    accs[acc].push_back(i);
  }

  RMQ rmq(values);
  lint result = solve(0, n-1, div, values, rmq, accs, acclist) - n;

  printf("%lld\n", result);

  return 0;
}