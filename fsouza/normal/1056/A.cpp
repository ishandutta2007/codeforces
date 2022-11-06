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
  int n;
  scanf("%d", &n);
  set<int> result;

  {
    int len;
    scanf("%d", &len);
    for (int j = 0; j < len; ++j) {
      int v;
      scanf("%d", &v);
      result.insert(v);
    }
  }

  set<int> result2;
  for (int i = 1; i < n; ++i) {
    int len;
    scanf("%d", &len);

    result2.clear();
    for (int j = 0; j < len; ++j) {
      int v;
      scanf("%d", &v);
      if (result.find(v) != result.end())
        result2.insert(v);
    }
    swap(result, result2);
  }

  vector<int> result3(result.begin(), result.end());
  for (int i = 0; i < (int)result3.size(); ++i) {
    if (i > 0) printf(" ");
    printf("%d", result3[i]);
  }
  printf("\n");

  return 0;
}