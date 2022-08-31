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

int val[4 * maxn], add[4 * maxn];
void clear(int p, int l, int r) {
  val[p] = 1 << 30;
  add[p] = 0;
  if (l == r) {
  } else {
    int mid = (l + r) >> 1;
    clear(p * 2, l, mid);
    clear(p * 2 + 1, mid + 1, r);
  }
}
int query(int p, int l, int r, int L, int R) {
  if (L == l && R == r)
    return val[p];
  add[p * 2] += add[p];
  val[p * 2] += add[p];
  add[p * 2 + 1] += add[p];
  val[p * 2 + 1] += add[p];
  add[p] = 0;
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(p * 2, l, mid, L, R);
  if (L > mid)
    return query(p * 2 + 1, mid + 1, r, L, R);
  return min(query(p * 2, l, mid, L, mid),
             query(p * 2 + 1, mid + 1, r, mid + 1, R));
}
void modify(int p, int l, int r, int L, int R, int v) {
  if (L == l && R == r) {
    add[p] += v, val[p] += v;
    return;
  }
  add[p * 2] += add[p];
  val[p * 2] += add[p];
  add[p * 2 + 1] += add[p];
  val[p * 2 + 1] += add[p];
  add[p] = 0;
  int mid = (l + r) >> 1;
  if (R <= mid)
    modify(p * 2, l, mid, L, R, v);
  else if (L > mid)
    modify(p * 2 + 1, mid + 1, r, L, R, v);
  else
    modify(p * 2, l, mid, L, mid, v),
        modify(p * 2 + 1, mid + 1, r, mid + 1, R, v);
  val[p] = min(val[p * 2], val[p * 2 + 1]);
}

void setval(int p, int l, int r, int x, int v) {
  if (l == r) {
    add[p] = 0, val[p] = v;
    return;
  }
  add[p * 2] += add[p];
  val[p * 2] += add[p];
  add[p * 2 + 1] += add[p];
  val[p * 2 + 1] += add[p];
  add[p] = 0;
  int mid = (l + r) >> 1;
  if (x <= mid)
    setval(p * 2, l, mid, x, v);
  else
    setval(p * 2 + 1, mid + 1, r, x, v);
  val[p] = min(val[p * 2], val[p * 2 + 1]);
}

int n, p[maxn], a[maxn], c[maxn];
int query(int x) {
  int s = 0;
  for (; x; x -= x & -x)
    s += c[x];
  return s;
}
void modify(int x, int s) {
  for (; x <= n; x += x & -x)
    c[x] += s;
}

void solve() {
  set<int> lst;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i), p[a[i]] = i;
    lst.insert(i);
  }
  clear(1, 0, n - 1);
  for (int i = 1; i <= n; i++)
    c[i] = 0;
  int ans = 0;
  for (int i = n; i > 1; i--) {
    int pos = p[i];
    lst.erase(pos);
    int pos0 = *(--lst.end());
    modify(pos + 1, 1);
    int rk = query(pos);
    setval(1, 0, n - 1, pos, pos / 2 * 2 - 2 * rk + 2);
    modify(1, 0, n - 1, pos, n - 1, -2);
    int mov = query(1, 0, n - 1, 0, pos0);
    ans = max(ans, i - 1 - mov);
    // printf("%d %d %d\n", i, mov, i - mov);
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