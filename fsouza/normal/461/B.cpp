#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define MAXN 100000

using namespace std;

typedef long long lint;

const lint mod = 1000000007;

vector<int> child[MAXN];
int black[MAXN];
int dp[MAXN][2];

int pref[MAXN+1][2], suf[MAXN+1][2];

void calc(int v) {
  const int nchild = (int)child[v].size();

  for (int i = 0; i < nchild; i++) {
    int v2 = child[v][i];
    calc(v2);
  }
  
  for (int j = 0; j < 2; j++) {
    pref[0][j] = 1;
    suf[0][j] = 1;
    for (int i = 0; i < nchild; i++) {
      pref[i+1][j] = (lint)dp[child[v][i]][j] * pref[i][j] % mod;
      suf[i+1][j] = (lint)dp[child[v][nchild-1-i]][j] * suf[i][j] % mod;
    }
  }

  {
    const int bexp = 0;
    int &ret = dp[v][bexp];

    ret = 0;
    if (black[v]) {
      ret = (ret + pref[nchild][1]) % mod;
    } else {
      for (int i = 0; i < nchild; i++)
	ret = (ret + (lint)dp[child[v][i]][0] * pref[i][1] % mod * suf[nchild-i-1][1] % mod) % mod;
    }
  }
  {
    const int bexp = 1;
    int &ret = dp[v][bexp];

    ret = dp[v][0];
    if (black[v]) {
    } else {
      ret = (ret + pref[nchild][1]) % mod;
    }
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    child[p].push_back(i);
  }

  for (int i = 0; i < n; i++) scanf("%d", &black[i]);

  calc(0);

  printf("%d\n", dp[0][0]);

  return 0;
}