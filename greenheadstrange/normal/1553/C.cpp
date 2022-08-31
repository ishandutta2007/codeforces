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

char s[20];
int p[20];
void solve() {
  int ans = 10;
  scanf("%s", s);
  for (int S = 0; S < (1 << 10); S++) {
    for (int j = 0; j < 10; j++)
      p[j] = (S >> j) & 1;
    bool match = true;
    for (int j = 0; j < 10; j++)
      if (s[j] != '?' && s[j] - '0' != p[j]) {
        match = false;
        break;
      }
    if (!match)
      continue;
    int sco0 = 0;
    int sco1 = 0;
    int rem0 = 5;
    int rem1 = 5;
    for (int j = 0; j < 10; j++) {
      if (j % 2 == 0) {
        sco0 += p[j];
        rem0--;
      } else {
        sco1 += p[j];
        rem1--;
      }
      if (sco0 + rem0 < sco1 || sco1 + rem1 < sco0) {
        ans = min(ans, j + 1);
        break;
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}