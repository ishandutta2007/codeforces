// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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

int n, b[maxn], blk_size[maxn], rem[maxn];
int B, T, m;
int mark[maxn], f[maxn];

int query(int x) {
  int pos = 0;
  for (int c = 18; c >= 0; c--) {
    if (pos + (1 << c) > m)
      continue;
    if (mark[pos + (1 << c)] != T) {
      mark[pos + (1 << c)] = T;
      f[pos + (1 << c)] = 0;
    }
    if ((1 << c) - f[pos + (1 << c)] <= x) {
      x -= (1 << c) - f[pos + (1 << c)];
      pos += (1 << c);
    }
  }
  return pos + 1;
}

struct block {
  int num[1010];
  int pre[1010];
  int cnt = 0;
  void init() { cnt = 0; }
  void build() {
    sort(num + 1, num + cnt + 1);
    for (int i = 1; i <= cnt; i++) {
      pre[i] = pre[i - 1] + num[i] - num[i - 1] - 1;
    }
  }
  int query(int x) {
    int v = lower_bound(pre, pre + cnt + 1, x) - pre - 1;
    return num[v] + x - pre[v];
  }
  void add(int x) {
    num[++cnt] = x;
    for (; x <= m; x += x & -x) {
      if (mark[x] != T)
        mark[x] = T, f[x] = 0;
      f[x]++;
    }
  }
} c[1010];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    b[i] = i - b[i];
  }
  B = max(int(sqrt(n) / 2.2), 1);
  T = 1;
  int TB = (n - 1) / B;
  m = n;
  for (int i = n - 1; i >= 0; i--) {
    blk_size[i] = m;
    rem[i] = query(b[i]);
    c[i / B].add(rem[i]);
    if (i % B == 0) {
      c[i / B].build();
      m = i;
      T++;
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int pos, num;
      scanf("%d%d", &pos, &num);
      --pos;
      b[pos] = pos - num;
      m = blk_size[pos];
      int t = pos / B;
      T++;
      c[t].init();
      for (int j = m - 1; j >= t * B; j--) {
        rem[j] = query(b[j]);
        c[t].add(rem[j]);
      }
      c[t].build();

    } else {
      int x;
      scanf("%d", &x);
      --x;
      int y = rem[x];
      for (int j = x / B + 1; j <= TB; j++) {
        y = c[j].query(y);
      }
      printf("%d\n", y);
    }
  }
}