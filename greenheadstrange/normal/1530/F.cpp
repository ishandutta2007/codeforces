// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 31607
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int inv = ksm(10000, mod - 2);
int b[30][30], a[30][30], n, totc[30], ans = 1;
int cmul[30][30], curmul[30];
void dfs(int dep, int sgn) {
  if (dep == n) {
    int mul = 1;
    for (int j = 0; j < n; j++)
      mul = mul * (curmul[j] - totc[j]) % mod;
    if (sgn)
      ans = (ans + mul) % mod;
    else
      ans = (ans - mul) % mod;
  } else {
    for (int j = 0; j < n; j++)
      cmul[dep][j] = curmul[j];
    dfs(dep + 1, sgn);
    for (int j = 0; j < n; j++) {
      b[dep][j]++;
      if (b[dep][j] == 1)
        curmul[j] = curmul[j] * a[dep][j] % mod;
    }
    dfs(dep + 1, sgn ^ 1);
    for (int j = 0; j < n; j++) {
      b[dep][j]--;
      curmul[j] = cmul[dep][j];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    totc[i] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      a[i][j] = x * inv % mod;
      totc[j] = totc[j] * a[i][j] % mod;
    }
  for (int diag1 = 0; diag1 <= 1; diag1++) {
    for (int diag2 = 0; diag2 <= 1; diag2++) {
      memset(b, 0, sizeof(b));
      if (diag1) {
        for (int i = 0; i < n; i++)
          b[i][i] += 1;
      }
      if (diag2) {
        for (int i = 0; i < n; i++)
          b[i][n - i - 1] += 1;
      }
      for (int i = 0; i < n; i++)
        curmul[i] = 1;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if (b[i][j])
            curmul[j] = curmul[j] * a[i][j] % mod;
      dfs(0, diag1 ^ diag2);
    }
  }
  if (ans < 0)
    ans += mod;
  printf("%d\n", ans);
}