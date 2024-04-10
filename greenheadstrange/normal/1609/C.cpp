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

const int maxm = 1000005, M = 1000000;
int n, e, f[maxn], pr[maxm], cnt[maxn], a[maxn], p[maxn];

void solve() {
  scanf("%d%d", &n, &e);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  ll ans = 0;
  for (int d = 0; d < e; d++) {
    int k = 0;
    for (int i = d; i <= n; i += e) {
      if (i == 0) continue;
      cnt[++k] = (a[i] == 1 ? 0 : (pr[a[i]] ? 1 : 2));
      //printf("%d ", cnt[k]);
    }
    //puts("");
    for (int i = 1; i <= k; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i <= cnt[k]; i++) p[i] = 0;
    for (int i = 0; i <= k; i++) p[cnt[i]]++;
    for (int i = 1; i <= k; i++) {
      ans += p[cnt[i] - 1];
      if (cnt[i - 1] == cnt[i] - 1) --ans;
    }
  }
  printf("%lld\n", ans);
}

int main() {
  for (int i = 2; i <= M; i++) pr[i] = 1;
  for (int i = 2; i <= M; i++)
    if (pr[i])
      for (int j = i + i; j <= M; j += i) pr[j] = 0;
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) solve();
}