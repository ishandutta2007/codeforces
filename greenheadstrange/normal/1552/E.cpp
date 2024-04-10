// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1005 /*rem*/
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
bool used[maxn];
array<int, 2> ans[maxn];
vi p[maxn];
void solve(int l, int r) {
  int pos = -1;
  for (int j = l; j <= r; j++) {
    int val = -1, L = 1 << 30, R = 1 << 30;
    for (int i = l; i <= r; i++)
      if (!used[i]) {
        int x = upper_bound(p[i].begin(), p[i].end(), pos) - p[i].begin();
        if (x <= k - 2) {
          if (p[i][x + 1] < R) {
            L = p[i][x], R = p[i][x + 1];
            val = i;
          }
        }
      }
    used[val] = true;
    ans[val] = {L + 1, R + 1};
    pos = R;
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n * k; i++) {
    int x;
    scanf("%d", &x);
    p[x].pb(i);
  }
  for (int i = 1; i <= n; i += k - 1) {
    solve(i, min(i + k - 2, n));
  }
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", ans[i][0], ans[i][1]);
}