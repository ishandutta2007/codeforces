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

string unique_for(int i) {
  string result(8 + 1, 'C');
  for (int l = 0; l < 8; ++l)
    if (i & (1<<l)) result[l+1] = 'a';
    else result[l+1] = 'b';
  return result;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  vector<string> result(n);
  for (int i = 0; i < k-1; ++i)
    result[i] = unique_for(i);
  for (int i = k-1; i < n; ++i) {
    char kind[3 + 1];
    scanf("%s", kind);
    if (!strcmp(kind, "YES")) {
      result[i] = unique_for(i);
    } else {
      result[i] = result[i - k + 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%s", result[i].c_str());
  }
  printf("\n");

  return 0;
}