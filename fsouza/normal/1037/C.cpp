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
  int n;
  scanf("%d", &n);

  string a = read_string();
  string b = read_string();

  int result = 0;

  for (int i = 0; i + 1 < n; ++i)
    if (a[i] != a[i + 1] && (a[i] == b[i + 1] && a[i + 1] == b[i])) {
      swap(a[i], a[i + 1]);
      result += 1;
    }

  for (int i = 0; i < n; ++i)
    if (a[i] != b[i])
      result += 1;

  printf("%d\n", result);

  return 0;
}