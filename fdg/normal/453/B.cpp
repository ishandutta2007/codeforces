#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[102], arr2[102], used[102];
vector<int> primes;

#define prev dgrgsdg

int dp[105][605][1<<9];
int prev[105][605][1<<9];
bool can[605][1<<9];
int nmask[605];

void update(int& r, int a) {
  if (r == -1 || r > a) r = a;
}

int main() {
  // cout << sizeof(dp) << endl;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    arr2[i] = arr[i];
  }
  sort(arr, arr + n);
  for (int i = 2; ; ++i) {
    bool pr = true;
    for (int j = 2; j < i; ++j)
      if (i % j == 0) pr = false;
    if (pr) {
      primes.push_back(i);
      if (primes.size() == 110) break;
    }
  }

  for (int i = 1; i <= 602; ++i) {
    for (int mask = 0; mask < (1<<9); ++mask) {
      bool ok = true;
      for (int j = 0; j < 9; ++j) {
        if (mask & (1<<j))
          if (i % primes[j] == 0) ok = false;
      }
      can[i][mask] = ok;
    }
    int mask = 0;
    for (int j = 0; j < 9; ++j)
      if (i % primes[j] == 0) mask |= 1<<j;
    nmask[i] = mask;
  }

  // cout << primes[100] << endl;
  // cout << primes.back() << endl;

  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1<<9); ++mask) {
      for (int last = 0; last <= 601; ++last) {
        if (dp[i][last][mask] == -1) continue;
        for (int nx = last + 1 - (last == 1); nx <= 30; ++nx) {
          if (can[nx][mask]) {
            if (dp[i + 1][nx][mask | nmask[nx]] == -1 || dp[i + 1][nx][mask | nmask[nx]] > dp[i][last][mask] + abs(arr[i] - nx)) {
              dp[i + 1][nx][mask | nmask[nx]] = dp[i][last][mask] + abs(arr[i] - nx);
              prev[i + 1][nx][mask | nmask[nx]] = ((mask<<10) | last);
            }
            // update(dp[i + 1][pr][mask | nmask[nx]], dp[i][pr][mask] + abs(arr[i] - nx));
          }
        }
        for (int nx = max(last + 1 - (last == 1), 31); ; ++nx) {
          if (can[nx][mask]) {
            if (dp[i + 1][nx][mask | nmask[nx]] == -1 || dp[i + 1][nx][mask | nmask[nx]] > dp[i][last][mask] + abs(arr[i] - nx)) {
              dp[i + 1][nx][mask | nmask[nx]] = dp[i][last][mask] + abs(arr[i] - nx);
              prev[i + 1][nx][mask | nmask[nx]] = ((mask<<10) | last);
            }
            break;
            // update(dp[i + 1][pr][mask | nmask[nx]], dp[i][pr][mask] + abs(arr[i] - nx));
          }
        }
        // if (dp[i + 1][pr + 1][mask] == -1 || dp[i + 1][pr + 1][mask] > dp[i][pr][mask] + abs(arr[i] - primes[pr])) {
        //   dp[i + 1][pr + 1][mask] = dp[i][pr][mask] + abs(arr[i] - primes[pr]);
        //   prev[i + 1][pr + 1][mask] = pr;
        // }
        // update(dp[i + 1][pr + 1][mask], dp[i][pr][mask] + abs(arr[i] - primes[pr]));
      }
    }
  } 
  int ans = -1;
  for (int mask = 0; mask < (1<<9); ++mask)
    for (int pr = 0; pr <= 601; ++pr)
      if (dp[n][pr][mask] != -1)
        update(ans, dp[n][pr][mask]);
  // cout << ans << endl;
  int seq[102] = {0};
  for (int mask = 0; mask < (1<<9); ++mask)
    for (int last = 0; last <= 601; ++last)
      if (dp[n][last][mask] == ans) {
        int i = n;
        while (i > 0) {
          int val = prev[i][last][mask];
          seq[i - 1] = last;
          last = (val) & 1023;
          mask = (val) >> 10;
          --i;
        }
        for (int i = 0; i < n; ++i) {
          if (i)
            cout << " ";
          for (int j = 0; j < n; ++j) {
            if (!used[j] && arr2[i] == arr[j]) {
              cout << seq[j];
              used[j] = true;
              break;
            }
          }
        }
        cout << endl;
        return 0;
      }
  return 0;
}