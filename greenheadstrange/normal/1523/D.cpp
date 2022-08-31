// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
mt19937 rnd(random_device{}());

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int n, m, p, bit[70], cnt[maxn], ansbit = -1;
char s[70];
ll id[maxn], ans;
int newid[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++)
      if (s[j] == '1')
        id[i] |= (1ll << j);
  }
  while (clock() <= 2.5 * CLOCKS_PER_SEC) {
    int maj = rnd() % n;
    int t = 0;
    for (int j = 0; j < m; j++)
      if (id[maj] & (1ll << j))
        bit[t++] = j;
    for (int i = 0; i < n; i++) {
      newid[i] = 0;
      for (int j = 0; j < t; j++)
        if (id[i] & (1ll << bit[j]))
          newid[i] |= 1 << j;
    }
    for (int i = 0; i < (1 << t); i++)
      cnt[i] = 0;
    for (int i = 0; i < n; i++)
      cnt[newid[i]] += 1;
    for (int j = 0; j < t; j++) {
      for (int i = 0; i < (1 << t); i++)
        if (i & (1 << j))
          cnt[i - (1 << j)] += cnt[i];
    }
    for (int i = 0; i < (1 << t); i++)
      if (cnt[i] >= (n + 1) / 2) {
        if (__builtin_popcount(i) > ansbit) {
          ansbit = __builtin_popcount(i);
          ans = 0;
          for (int j = 0; j < t; j++)
            if (i & (1 << j))
              ans |= (1ll << bit[j]);
        }
      }
  }
  for (int j = 0; j < m; j++)
    if (ans & (1ll << j))
      printf("%d", 1);
    else
      printf("%d", 0);
  printf("\n");
}