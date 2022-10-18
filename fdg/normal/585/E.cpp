#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

int arr[500005];

const int N = 10000000;
int dv[N + 7], to[N + 7];

int dp[N + 7], dp2[N + 7], cnt[N + 7];
vector<pair<int, int>> fact;

void go(int i, int val = 1) {
  if (i == fact.size()) {
    // cout << val << endl;
    dp[val] += dp[val];
    if (dp[val] >= mod) dp[val] -= mod;
    return;
  }

  for (int j = 0; j <= fact[i].second; ++j) {
    go(i + 1, val);
    val *= fact[i].first;
  }
}

void go2(int i, int val = 1) {
  if (i == fact.size()) {
    // cout << val << endl;
    cnt[val]++;
    return;
  }

  go2(i + 1, val);
  go2(i + 1, val * fact[i].first);
}

int curV;

void go3(int i, int val = 1, int sg = 1) {
  if (i == fact.size()) {
    // cout << val << endl;
    curV += sg * cnt[val];
    return;
  }

  go3(i + 1, val, sg);
  go3(i + 1, val * fact[i].first, -sg);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  for (int i = 2; i <= N; ++i) {
    if (dv[i] == 0) {
      for (int k = 1; k * i <= N; ++k) {
        if (dv[i * k] == 0) {
          dv[i * k] = i;
          to[i * k] = k;
        }
      }
    }
  }

  for (int i = 0; i <= N; ++i)
    dp[i] = 1, dp2[i] = n;

  for (int i = 0; i < n; ++i) {
    fact.clear();
    int cur = arr[i];
    while (cur > 1) {
      int d = dv[cur], pw = 0;
      while (d == dv[cur]) {
        cur = to[cur];
        ++pw;
      }
      fact.push_back({d, pw});
    }
    go(0);
    go2(0);
  }
  for (int i = N; i >= 1; --i) {
    dp[i]--;
    if (dp[i] < 0) dp[i] += mod;

    for (int j = i + i; j <= N; j += i) {
      dp[i] -= dp[j];
      if (dp[i] < 0)
        dp[i] += mod;
    }
  }

  // for (int i = 1; i <= 20; ++i)
  //   cout << dp[i] << "  ";
  // cout << endl;

  int ans = 0;
  for (int i = 2; i <= N; ++i) {
    if (!dp[i]) continue;
    
    fact.clear();
    int cur = i;
    while (cur > 1) {
      int d = dv[cur], pw = 0;
      while (d == dv[cur]) {
        cur = to[cur];
        ++pw;
      }
      fact.push_back({d, pw});
    }

    curV = 0;
    go3(0);

    // if (dp[i] && curV)
    //   cout << i << "  " << dp[i] << " " << curV << endl;

    ans = (ans + 1LL * dp[i] * curV) % mod;
  }
  cout << ans << endl;

  return 0;
}