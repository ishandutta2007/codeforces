// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
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

int n, m, mark;
int p[maxn], c[maxn], cov[maxn], x[maxn], y[maxn];
ll fac[maxn], rfac[maxn];

int query(int x) {
  int pos = 0;
  for (int j = 18; j >= 0; j--)
    if (pos + (1 << j) <= n && c[pos + (1 << j)] < x) {
      pos += (1 << j);
      x -= c[pos];
    }
  return pos + 1;
}
void modify(int x, int s) {
  for (; x <= n; x += x & -x)
    c[x] += s;
}

void solve() {
  scanf("%d%d", &n, &m);
  int inq = 0;
  mark++;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", x + i, y + i);
  }
  for (int i = m - 1; i >= 0; i--) {
    int p = query(y[i]), q = -1;
    if (y[i] != 1)
      q = query(y[i] - 1);
    x[i] = p;
    if (cov[p] != mark)
      inq++;
    modify(p, -1);
    if (q != -1)
      cov[q] = mark;
  }
  for (int i = 0; i < m; i++)
    modify(x[i], 1);
  printf("%lld\n",
         fac[n - inq + n - 1] * rfac[n] % mod * rfac[n - 1 - inq] % mod);
}

int main() {
  fac[0] = 1;
  rfac[0] = 1;
  for (int i = 1; i <= 400000; i++) {
    fac[i] = fac[i - 1] * i % mod;
    rfac[i] = ksm(fac[i], mod - 2);
  }
  for (int i = 1; i <= 200000; i++) {
    for (int j = i; j <= 200000; j += j & -j)
      c[j]++;
  }
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
    solve();
}