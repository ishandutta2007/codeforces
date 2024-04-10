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
  vector<int> count(26, 0);
  for (int i = 0; i < n; ++i) {
    char c;
    scanf(" %c", &c);
    count[c - 'a'] += 1;
  }
  int nc1 = 0, nc2 = 0;
  for (int j = 0; j < 26; ++j)
    if (count[j] == 1)
      ++nc1;
    else if (count[j] >= 2)
      ++nc2;

  bool result;
  if (nc2 >= 1) result = true;
  else result = (nc1 == 1);

  if (result) printf("Yes\n");
  else printf("No\n");

  return 0;
}