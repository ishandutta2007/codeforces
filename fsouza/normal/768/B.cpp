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

void get_sizes(lint n, vector<lint> &sizes) {
  if (n == 1)
    sizes.push_back(1);
  else {
    get_sizes(n / 2, sizes);
    sizes.push_back(sizes.back() * 2 + 1);
  }
}

int get_value(lint pos, lint n, int depth, vector<lint> &sizes) {
  if (sizes[depth] == 1) {
    return n % 2;
  } else {
    lint subsize = sizes[depth + 1];
    if (pos < subsize)
      return get_value(pos, n/2, depth+1, sizes);
    else if (pos == subsize)
      return n % 2;
    else
      return get_value(pos - subsize - 1, n/2, depth+1, sizes);
  }
}

int main() {
  lint n, l, r;
  cin >> n >> l >> r; --l, --r;

  lint result;
  if (n == 0) {
    result = 0;
  } else {
    vector<lint> sizes;
    get_sizes(n, sizes);
    reverse(sizes.begin(), sizes.end());
    result = 0;
    for (lint pos = l; pos <= r; ++pos)
      result += get_value(pos, n, 0, sizes);
  }

  cout << result << endl;

  return 0;
}