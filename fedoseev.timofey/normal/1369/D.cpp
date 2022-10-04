#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 2e6 + 7;
const int md = 1e9 + 7;

int dp[N][2];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  for (int i = 3; i < N; ++i) {
    dp[i][0] = (dp[i - 1][1] + 2LL * dp[i - 2][1]) % md;
    dp[i][1] = dp[i][0];
    if (i % 3 == 0) {
      dp[i][1] = (dp[i][1] + 4) % md;
    }
  } 
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << dp[x][1] << '\n';
  }
}