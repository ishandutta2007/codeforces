// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 205 /*rem*/
#define mod 1000000007
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

int n, c[maxn], b[maxn], q, x;
ll d[maxn], s[maxn];
int dp[110][10100], pre[10100], sc[110], answer[200010];
int M = 100000;
int main() {
  scanf("%d", &n);

  ll ss = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
    ss = ss * (c[i] + 1) % mod;
    sc[i] = sc[i - 1] + c[i];
  }
  for (int i = 1; i < n; i++)
    scanf("%d", b + i);
  scanf("%d", &q);

  for (int x = -M; x <= M; x++) {
    s[1] = x;
    d[1] = x;
    bool val = true;
    for (int i = 2; i <= n; i++) {
      d[i] = d[i - 1] + b[i - 1];
      s[i] = s[i - 1] + d[i];
      if (s[i] > sc[i]) {
        val = false;
      }
    }
    if (val == false) {
      answer[x + M] = 0;
      continue;
    }
    if (*max_element(s + 1, s + n + 1) <= 0) {
      answer[x + M] = ss;
      continue;
    }
    dp[0][0] = 1;
    int sc = 0;
    for (int i = 0; i < n; i++) {
      sc += c[i + 1];
      for (int j = 0; j <= sc; j++)
        pre[j] = 0, dp[i + 1][j] = 0;
      pre[0] = dp[i][0];
      for (int j = 1; j <= sc; j++)
        pre[j] = (pre[j - 1] + dp[i][j]) % mod;
      for (int j = max(s[i + 1], 0ll); j <= sc; j++) {
        dp[i + 1][j] =
            (pre[j] - (j <= c[i + 1] ? 0 : pre[j - c[i + 1] - 1])) % mod;
        if (dp[i + 1][j] < 0)
          dp[i + 1][j] += mod;
      }
    }
    int ans = 0;
    for (int j = 0; j <= sc; j++)
      ans = (ans + dp[n][j]) % mod;
    //printf("%d %lld\n", x, ans);
    answer[x + M] = ans;
  }
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    printf("%d\n", answer[x + M]);
  }
}