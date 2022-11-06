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

const int maxn = 2e5;
int dp[maxn + 1][2][2][3 + 1];

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &values[i]);

    for (bool changed : {false, true})
      for (bool same : {false, true}) {
        dp[n][changed][same][3] = INT_MAX/2;
        for (int score = 0; score <= 2; ++score) {
          dp[n][changed][same][score] = (score <= 1 ? 0 : INT_MAX/2);
        }
      }

    for (int pos = n - 1; pos >= 0; --pos)
      for (bool changed : {false, true})
        for (bool same : {false, true}) {
          dp[pos][changed][same][3] = INT_MAX/2;
          for (int score = 0; score <= 2; ++score) {
            bool next_same =
              pos + 1 < n && !changed && values[pos + 1] == values[pos];
            int result = dp[pos + 1][false][next_same][score + (int)next_same];

            if (pos + 1 < n) {
              int new_score = score;
              if (same) --new_score;
              ++new_score;
              result = min(result, 1 + dp[pos + 1][true][true][new_score]);
            }

            dp[pos][changed][same][score] = result;
          }
        }

    printf("%d\n", dp[0][0][0][0]);
  }
  return 0;
}