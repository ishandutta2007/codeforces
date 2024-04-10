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
  int n, height;
  scanf("%d %d", &n, &height);

  double total_area = height / 2.0;
  double each_area = total_area / n;

  double last_cut = 0.0;

  for (int i = 0; i < n-1; ++i) {
    double l = last_cut, r = height;
    for (int rep = 0; rep < 300; ++rep) {
      double m = l + (r-l)/2;

      double area = (m + last_cut) * (m - last_cut) / (2.0 * height);
      if (area < each_area) l = m;
      else r = m;
    }
    double cut = l;
    if (i > 0) printf(" ");
    printf("%.12f", cut);

    last_cut = cut;
  }
  printf("\n");


  return 0;
}