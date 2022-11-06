#include <algorithm>
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

const int maxk = 86;

int main() {
  lint n;
  cin >> n;

  vector<lint> dp(maxk);
  dp[0] = 1;
  dp[1] = 2;
  for (int i = 2; i < maxk; ++i)
    dp[i] = dp[i-1] + dp[i-2];

  int result = 0;
  for (int i = 0; i < maxk; ++i)
    if (n >= dp[i])
      result = i;

  cout << result << endl;

  return 0;
}