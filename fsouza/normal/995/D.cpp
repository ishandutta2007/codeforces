#include <algorithm>
#include <array>
#include <bitset>
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
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int k, nq;
  scanf("%d %d", &k, &nq);
  int n = (1<<k);
  lint sum = 0LL;
  vector<int> values(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &values[i]);
    sum += values[i];
  }
  printf("%.12f\n", (double)((long double)sum / n));
  for (int q = 0; q < nq; ++q) {
    int id, new_value;
    scanf("%d %d", &id, &new_value);
    sum += new_value - values[id];
    values[id] = new_value;
    printf("%.12f\n", (double)((long double)sum / n));
  }
  return 0;
}