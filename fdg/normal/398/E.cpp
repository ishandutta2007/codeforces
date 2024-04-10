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

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    x >>= 1;
  }
  return ret;
}

int arr[100005], has[100005];
int used[100005];
vector<int> lines;
vector<int> dp[100005], rdp[100005];

int tmpAns = 1, gr3 = 0, answer = 0;
int cnt[100005];

vector<int> addSize, addCnt;

void updateAns(int ans) {
  int cur = tmpAns;
  for (int i = 0; i < addSize.size(); ++i) {
    cur = 1LL * cur * rdp[addSize[i]][cnt[addSize[i]]] % mod;
    ++cnt[addSize[i]];
    cur = 1LL * cur * dp[addSize[i]][cnt[addSize[i]]] % mod;
    if (addSize[i] > 2) ++gr3;
  }
  if (gr3)
    ans = 1LL * ans * cur % mod;
  for (int i = 0; i < addSize.size(); ++i) {
    --cnt[addSize[i]];
    if (addSize[i] > 2) --gr3;
  }
  answer = (answer + ans) % mod;
}

void dfs(int ind, int ans) {
  if (ind == lines.size()) {
    updateAns(ans);
    return;
  }
  addSize.push_back(lines[ind]);
  addCnt.push_back(1);
  dfs(ind + 1, ans);

  addSize.pop_back();
  addCnt.pop_back();
  for (int i = 0; i < addSize.size(); ++i) {
    addSize[i] += lines[ind];
    addCnt[i]++;
    dfs(ind + 1, 1LL * ans * (addCnt[i] - 1) % mod);
    addSize[i] -= lines[ind];
    addCnt[i]--;
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
    has[arr[i]] = true;
  }

  for (int i = 1; i <= n; ++i) {
    dp[i].push_back(1);
    rdp[i].push_back(1);
    for (int j = 1; j * i <= n; ++j) {
      int val = 1LL * i * dp[i][j - 1] % mod;
      if (j > 1) {
        val = (val + 1LL * i * (j - 1) * dp[i][j - 2]) % mod;
      }
      dp[i].push_back(val);
      rdp[i].push_back(mPow(val, mod - 2));
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!has[i]) {
      int v = i, len = 0;
      while (v) {
        used[v] = true;
        ++len;
        v = arr[v];
      }
      lines.push_back(len);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      int v = i, len = 0;
      while (!used[v]) {
        used[v] = true;
        ++len;
        v = arr[v];
      }
      cnt[len]++;
      if (len >= 3) gr3++;
    }
  }
  for (int len = 1; len <= n; ++len)
    tmpAns = 1LL * tmpAns * dp[len][cnt[len]] % mod;
  dfs(0, 1);
  printf("%d\n", answer);
  return 0;
}