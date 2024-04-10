// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
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

int n, k;
int a[maxn], b[maxn], bit[50], p[maxn];
int x[maxn];
int query(int o, int a, int b) {
  if (o == 0) {
    printf("or %d %d\n", a, b);
    // return x[a] | x[b];
  } else {
    printf("and %d %d\n", a, b);
    // return x[a] & x[b];
  }
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < 30; i++)
    bit[i] = -1;
  for (int i = 2; i <= n; i++) {
    a[i] = query(0, 1, i);
    b[i] = query(1, 1, i);
    for (int j = 0; j < 30; j++) {
      if ((a[i] & (1 << j)) == 0) {
        bit[j] = 0;
      }
      if ((b[i] & (1 << j))) {
        bit[j] = 1;
      }
    }
  }
  int y = query(0, 2, 3);
  for (int j = 0; j < 30; j++) {
    if (bit[j] == -1) {
      bit[j] = 1 - ((y >> j) & 1);
    }
    p[1] |= bit[j] << j;
  }
  for (int j = 2; j <= n; j++)
    p[j] = a[j] + b[j] - p[1];
  sort(p + 1, p + n + 1);
  printf("finish %d\n", p[k]);
  fflush(stdout);
}