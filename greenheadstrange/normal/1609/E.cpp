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

int cost[maxn][4][4], n, q;
char s[maxn], val[10];

void update(int p) {
  for (int i = 0; i <= 3; i++)
    for (int j = i; j <= 3; j++) {
      cost[p][i][j] = 1 << 29;
      for (int k = i; k <= j; k++)
        cost[p][i][j] =
            min(cost[p][i][j], cost[p * 2][i][k] + cost[p * 2 + 1][k][j]);
    }
}

void init(int p, int l) {
  for (int i = 0; i <= 3; i++)
    for (int j = i; j <= 3; j++) {
      cost[p][i][j] = 1 << 29;
      if (i == j) cost[p][i][j] = 0;
      if (i + 1 == j) cost[p][i][j] = 1;
    }
  cost[p][s[l] - 'a'][s[l] - 'a'] = 1;
  cost[p][s[l] - 'a'][s[l] - 'a' + 1] = 0;
}
void build(int p, int l, int r) {
  if (l == r) {
    init(p, l);
  } else {
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    update(p);
  }
}

void change(int p, int l, int r, int x, char t) {
  if (l == r) {
    s[x] = t;
    init(p, l);
  } else {
    int mid = (l + r) / 2;
    if (x <= mid)
      change(p * 2, l, mid, x, t);
    else
      change(p * 2 + 1, mid + 1, r, x, t);
    update(p);
  }
}

int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  build(1, 1, n);
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d%s", &x, val);
    change(1, 1, n, x, val[0]);
	int ans=1<<29;
	for (int k=0;k<3;k++) ans=min(ans,cost[1][0][k]);
	printf("%d\n",ans);
  }
}