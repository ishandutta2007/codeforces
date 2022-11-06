#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> result;
  for (int i = 0; i < n; ++i) {
    result.push_back(1);
    while (result.size() >= 2 && result.end()[-2] == result.end()[-1]) {
      result.pop_back();
      ++result.back();
    }
  }

  for (int i = 0; i < (int)result.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");
  
  return 0;
}