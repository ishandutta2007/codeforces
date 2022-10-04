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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

const int K = 350;
const int N = 1e5 + 7;

int dp[K][2 * N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  // b + i * k = a[i], (a[i] - i * k)
  int mx = 0;
  vector<int> have;
  for (int k = -K; k <= K; ++k) {
    have.clear();
    for (int i = 0; i < n; ++i) {
      have.push_back(a[i] - i * k);
    }
    sort(have.begin(), have.end());
    int lst = -1, cnt = 0;
    for (auto x : have) {
      if (x == lst) {
        ++cnt;
      } else {
        mx = max(mx, cnt);
        lst = x;
        cnt = 1;
      }
    }
    mx = max(mx, cnt);
  }
  for (int i = 0; i < n; ++i) {
    int ii = i % K;
    if (i >= K) {
      int pr_i = i - K;
      for (int j = pr_i - 1; j >= max(0, pr_i - K + 1); --j) {
        int step = a[pr_i] - a[j];
        if (step % (pr_i - j)) continue;
        step /= pr_i - j;
        if (abs(step) > K) {
          mx = max(mx, dp[ii][step + N]);
          dp[ii][step + N] = 0;
        }
      }
    }
    int jj = ii;
    for (int j = i - 1; j >= max(0, i - K + 1); --j) {
      --jj;
      if (jj < 0) jj = K - 1;
      int step = a[i] - a[j];
      if (step % (i - j)) continue;
      step /= i - j;
      if (abs(step) > K) {
        dp[ii][step + N] = max(dp[ii][step + N], max(2, dp[jj][step + N] + 1));
      } 
    }
  }
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < 2 * N; ++j) {
      mx = max(mx, dp[i][j]);
    }
  }
  cout << n - mx << '\n';
}