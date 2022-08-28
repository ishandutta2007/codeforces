#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 2010, P = 998244353;

int n;
int fw[N], fw2[N];
bool vis[N];
int a[N][N], dp[N][N];

int lowBit(int k) { return k & -k; }

void ch(int* fw, int k, int x) {
  for (; k <= n; k += lowBit(k))
    fw[k] += x;
}

int qry(int* fw, int k) {
  int ret = 0;
  for (; k; k -= lowBit(k))
    ret += fw[k];
  return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      scanf("%d", &a[i][j]);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] * (ll)i % P;
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = (dp[i - 1][j - 1] * (ll)(i - j) + (j > 1 ? dp[i - 1][j - 2] * (ll)(j - 1) : 0)) % P;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ch(fw, a[1][i], 1);
    ans = (ans + dp[n - i][0] * (ll)(a[1][i] - qry(fw, a[1][i]))) % P;
  }
  for (int i = 2; i <= n; ++i) {
    memset(fw, 0, sizeof(fw));
    memset(fw2, 0, sizeof(fw2));
    memset(vis, 0, sizeof(vis));
    int con = n;
    ans = ans * (ll)dp[n][n] % P;
    for (int j = 1; j < n; ++j) {
      bool flag = a[i - 1][j] < a[i][j] && !vis[a[i - 1][j]]; // can not write a specific
      ch(fw, a[i][j], 1);
      if (vis[a[i - 1][j]] ^= true) {
        ch(fw2, a[i - 1][j], 1);
        --con;
      }
      int chose = a[i][j] - 1 - qry(fw, a[i][j] - 1), par = qry(fw2, a[i][j] - 1);
    //  LOG("%d %d %d: ", chose, par, con);
      int tmp = ans;
      if (flag) {
      //  LOG("A"); 
        ans = (ans + (par - 1) * (ll)dp[n - j][con] + (chose - par) * (ll)dp[n - j][con - 1]) % P;
      } else {
        //LOG("B");
        ans = (ans + par * (ll)dp[n - j][con] + (chose - par) * (ll)dp[n - j][con - 1]) % P;
      }
//      LOG("%d\n", ans - tmp);
      if (vis[a[i][j]] ^= true)
        --con;
      else {
        ch(fw2, a[i][j], -1);
      }
    }
  }
  printf("%d\n", ans);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}