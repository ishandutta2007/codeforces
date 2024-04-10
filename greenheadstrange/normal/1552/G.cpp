// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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

mt19937 mrand(random_device{}());

int n, k, p[50], tmp[20][50];
vi a[20];

void dfs(int x) {
  if (x == k) {
    for (int j = 0; j < n; j++)
      if (tmp[k][j] == -1) {
        puts("REJECTED");
        exit(0);
      }
    for (int j = 0; j < n - 1; j++)
      if (tmp[k][j] > tmp[k][j + 1]) {
        puts("REJECTED");
        exit(0);
      }
  } else {
    for (int j = 0; j < n; j++)
      tmp[x + 1][j] = tmp[x][j];
    int c0 = 0, c1 = 0, co = 0;
    for (auto y : a[x])
      if (tmp[x][y] == 0)
        c0++;
      else if (tmp[x][y] == 1)
        c1++;
      else
        co++;
    for (int y = 0; y < a[x].size(); y++)
      if (y < c0)
        tmp[x + 1][a[x][y]] = 0;
      else
        tmp[x + 1][a[x][y]] = 1;
    for (int d = c0; d <= c0 + co; d++) {
      dfs(x + 1);
      if (d != c0 + co)
        tmp[x + 1][a[x][d]] = 0;
    }
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      int y;
      scanf("%d", &y);
      --y;
      a[i].pb(y);
    }
  }
  for (int i = 0; i < n; i++)
    tmp[0][i] = -1;
  if (n == 1) {
    puts("ACCEPTED");
    return 0;
  }
  dfs(0);
  puts("ACCEPTED");
}