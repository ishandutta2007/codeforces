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

string read_string() {
  char *str;
  scanf("%ms", &str);
  string result(str);
  free(str);
  return result;
}

int main() {
  string s = read_string();
  int n = s.size();

  vector<int> result(n);
  for (int i = 0; i < n; ++i) {
    bool block_end = (i == n - 1) || (s[i + 1] != s[i]);
    if (block_end && (i != n - 1 || s[i] != 'b'))
      result[i] = 1;
    else
      result[i] = 0;
  }

  for (int i = 0; i < n; ++i) {
    if (i > 0) printf(" ");
    printf("%d", result[i]);
  }
  printf("\n");

  return 0;
}