// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 600005 /*rem*/
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

int n, k;
int cnt[maxn], a[maxn], minval[22][maxn];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int b = k;
  for (int i = k; i >= 0; i--) {
    for (int j = 0; j < (1 << k); j++) {
      cnt[j] = 0;
    }
    for (int j = 0; j < n; j++)
      cnt[a[j] >> i]++;
    if (*max_element(cnt, cnt + (1 << k)) <= 1) {
      b = i;
      break;
    }
  }
  for (int j = 0; j < (1 << k); j++)
    cnt[j] = -1;
  for (int j = 0; j < n; j++)
    cnt[a[j] >> b] = a[j];
  memset(minval, 0x20, sizeof(minval));
  for (int i = 0; i < n; i++) {
    int d = a[i] >> b;
    // assert(cnt[d] == a[i]);
    for (int j = b; j < k; j++) {
      int u = (1 << (j - b)) - 1, v = u + 1;
      for (int x = 0; x < (1 << b); x++) {
        int r = (((d & ((1 << (j - b + 1)) - 1)) ^ u) << b) + x;
        if (cnt[d ^ u ^ v] != -1) {
          minval[j][r] =
              min(minval[j][r], abs((a[i] ^ r) - (cnt[d ^ u ^ v] ^ r)));
        }
      }
    }
  }
  for (int i = 0; i < (1 << k); i++) {
    int ans = 1 << 30;
    for (int j = b; j < k; j++) {
      ans = min(ans, minval[j][i & ((1 << (j + 1)) - 1)]);
    }
    printf("%d ", ans);
  }
  puts("");
}