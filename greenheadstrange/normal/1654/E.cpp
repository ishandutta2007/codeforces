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

template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b) return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1) ns = ns * a % mod;
  return ns;
}

int MAGIC = 100, M = 100000;
int n, a[maxn], ans;
int t[21000000], val[21000000], T;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int d = -MAGIC; d <= MAGIC; d++) {
    T++;
    for (int i = 1; i <= n; i++) {
      int v = a[i] - i * d + MAGIC * n;
      if (t[v] != T) t[v] = T, val[v] = 0;
      val[v]++;
      ans = max(ans, val[v]);
    }
  }
  for (int i = 1; i <= n; i++) {
    T++;
    for (int j = i - 1; j >= 1; j--) {
      if ((i - j) * MAGIC > M) break;
      if ((a[i] - a[j]) % (i - j) != 0) continue;
      int v = (a[i] - a[j]) / (i - j) + M;
      if (t[v] != T) t[v] = T, val[v] = 0;
      val[v]++;
      ans = max(ans, val[v] + 1);
    }
  }
  printf("%d\n", n - ans);
}