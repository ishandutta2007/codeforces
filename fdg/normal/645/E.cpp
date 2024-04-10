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

char s[2000006];
int dp[2000006], sum[2000006];

void add(int &r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int get(int l, int r) {
  int ret = sum[r] - (l > 0 ? sum[l - 1] : 0);
  if (ret < 0) ret += mod;
  return ret;
}

int main() {
  int n, k;
  scanf("%d%d\n", &n, &k);
  s[0] = '$';
  gets(s + 1);
  int m = strlen(s) - 1;
  
  dp[0] = sum[0] = 1;
  int lastp[256] = {0};
  for (int i = 1; i <= m; ++i) {
    dp[i] = get(lastp[s[i]], i - 1);
    sum[i] = sum[i - 1];
    add(sum[i], dp[i]);
    // cout << sum[i] << endl;
    lastp[s[i]] = i;
  }
  for (int i = m + 1; i <= m + n; ++i) {
    char c = 'a';
    for (int j = 'a'; j < 'a' + k; ++j) {
      if (lastp[j] < lastp[c]) c = j;
    }
    s[i] = c;

    dp[i] = get(lastp[s[i]], i - 1);
    sum[i] = sum[i - 1];
    add(sum[i], dp[i]);
    // cout << sum[i] << endl;
    lastp[s[i]] = i;
  }
  cout << sum[n + m] << endl;
  return 0;
}