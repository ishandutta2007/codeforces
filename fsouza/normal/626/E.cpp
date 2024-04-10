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
typedef long double ldouble;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> values(n);
  for (int &v : values) scanf("%d", &v);
  sort(values.begin(), values.end());
  vector<lint> acc(n+1);
  acc[0] = 0;
  for (int i = 0; i < n; ++i) acc[i+1] = acc[i] + values[i];

  ldouble bestv = -1;
  int bestmid = -1, bestsize = -1;
  bool besteven = false;

  for (int mid = 0; mid < n; ++mid) {
    int maxsize = min(mid, n-mid-1);
    int l = 0, r = maxsize;
    auto calc = [n, mid, &acc, &values](int size) {
      lint sum = (acc[mid] - acc[mid-size]) + values[mid] + (acc[n] - acc[n-size]);
      ldouble mean = (ldouble)sum / (2*size+1);
      return mean - values[mid];
    };
    while (l < r) {
      int m0 = l + (r-l)/3, m1 = r - (r-l)/3;
      ldouble v0 = calc(m0), v1 = calc(m1);
      if (v0 > v1) r = m1-1;
      else l = m0+1;
    }
    int size = l;
    ldouble v = calc(size);
    if (v > bestv) {
      bestv = v;
      bestmid = mid;
      bestsize = size;
      besteven = false;
    }
  }

  for (int mid = 0; mid+1 < n; ++mid) {
    int maxsize = min(mid, n-mid-2);
    int l = 0, r = maxsize;
    auto calc = [n, mid, &acc, &values](int size) {
      lint sum = (acc[mid] - acc[mid-size]) + values[mid] + values[mid+1] + (acc[n] - acc[n-size]);
      ldouble mean = (ldouble)sum / (2*size+2);
      return mean - (values[mid]+values[mid+1])/2.0;
    };
    while (l < r) {
      int m0 = l + (r-l)/3, m1 = r - (r-l)/3;
      ldouble v0 = calc(m0), v1 = calc(m1);
      if (v0 > v1) r = m1-1;
      else l = m0+1;
    }
    int size = l;
    ldouble v = calc(size);
    if (v > bestv) {
      bestv = v;
      bestmid = mid;
      bestsize = size;
      besteven = true;
    }
  }

  vector<int> result;
  for (int i = 0; i < bestsize; ++i) {
    result.push_back(values[n-1-i]);
    result.push_back(values[bestmid-1-i]);
  }
  result.push_back(values[bestmid]);
  if (besteven) result.push_back(values[bestmid+1]);
  sort(result.begin(), result.end());

  printf("%d\n", (int)result.size());
  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}