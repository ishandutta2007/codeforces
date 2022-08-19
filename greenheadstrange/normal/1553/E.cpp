// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
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

int n, m;
int cnt[maxn], q[maxn], p[maxn];
bool vis[maxn];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    cnt[i] = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", q + i);
    --q[i];
    cnt[(i - q[i] + n) % n]++;
  }
  vi ans;
  auto check = [&](int del) {
    for (int i = 0; i < n; i++) {
      p[i] = (q[i] + del) % n;
      vis[p[i]] = 0;
    }
    int cyc = n;
    for (int i = 0; i < n; i++)
      if (!vis[i]) {
        cyc--;
        int x = i;
        while (!vis[x]) {
          vis[x] = true;
          x = p[x];
        }
      }
    return cyc <= m;
  };
  for (int i = 0; i < n; i++)
    if (cnt[i] >= n - 2 * m) {
      if (check(i))
        ans.pb(i);
    }
  printf("%d", (int)ans.size());
  for (auto i : ans)
    printf(" %d", i);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}