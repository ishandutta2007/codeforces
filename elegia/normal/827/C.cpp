#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 101000, L = 11;

int lowBit(int k) {
  return k & -k;
}

void ch(int* fw, int n, int k, int x) {
  for (; k <= n; k += lowBit(k))
    fw[k] += x;
}

int qry(int* fw, int k) {
  int ret = 0;
  for (; k; k -= lowBit(k))
    ret += fw[k];
  return ret;
}

char* key = "ATGC";

int n;
char s[N], tmp[L];
int mp[256];
int fw[L][4][N];

void apply(int k, int v, int x) {
  for (int mod = 1; mod < L; ++mod) {
    ch(fw[mod][v] + (k % mod) * (n / mod + 3), n / mod + 1, (k - 1) / mod + 1, x);
    //LOG("CH %d %d %d %d %d\n", mod, v, k % mod, (k - 1) / mod + 1, x);
  }
}

int qry(int mod, int v, int res, int r) {
  if (res == 0)
    res = mod;
  int p = (r - res + mod) / mod;
  res %= mod;
  // p * mod + res <= r
  return qry(fw[mod][v] + res * (n / mod + 3), p);
}

int main() {
	ios::sync_with_stdio(false);
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
#endif

  for (int i = 0; i < 4; ++i)
    mp[key[i]] = i;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i)
    apply(i, mp[s[i]], 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int opt, x, y;
    scanf("%d%d", &opt, &x);
    if (opt == 1) {
      char c;
      scanf(" %c", &c);
      apply(x, mp[s[x]], -1);
      apply(x, mp[s[x] = c], 1);
    } else {
      scanf("%d%s", &y, tmp);
      int m = strlen(tmp);
      int ans = 0;
      for (int i = 0; i < m; ++i) {
        int r = (x + i) % m;
        ans += qry(m, mp[tmp[i]], r, y) - qry(m, mp[tmp[i]], r, x - 1);
      }
      printf("%d\n", ans);
    }
  }

}