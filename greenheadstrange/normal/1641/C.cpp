// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>

#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector < int >
  #define pb push_back
#define mp make_pair
#define pi pair < int, int >
  #define fi first
#define se second

template < typename T >
  bool chkmax(T & x, T y) {
    return x < y ? x = y, true : false;
  }
template < typename T >
  bool chkmin(T & x, T y) {
    return x > y ? x = y, true : false;
  }

using namespace std;
mt19937 mrand(random_device {}());

ll ksm(ll a, ll b) {
  if (!b) return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1) ns = ns * a % mod;
  return ns;
}

int maxt[maxn * 4];
int n, q, sta[maxn], op[maxn], l[maxn], r[maxn], x[maxn], t[maxn];
set < int > pat;
void build(int p, int l, int r) {
  if (l == r) {
    maxt[p] = t[l];
  } else {
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    maxt[p] = max(maxt[p * 2], maxt[p * 2 + 1]);
  }
}
int query(int p, int l, int r, int x, int y) {
  if (x == l && y == r) return maxt[p];
  else {
    int mid = (l + r) >> 1;
    if (y <= mid) return query(p + p, l, mid, x, y);
    if (x > mid) return query(p + p + 1, mid + 1, r, x, y);
    return max(query(p + p, l, mid, x, mid), query(p + p + 1, mid + 1, r, mid + 1, y));
  }
}

int main() {
  scanf("%d%d", & n, & q);
  for (int i = 1; i <= n; i++) pat.insert(i), sta[i] = -1;
  for (int i = 1; i <= q; i++) {
    scanf("%d", & op[i]);
    if (op[i] == 0) {
      scanf("%d%d%d", & l[i], & r[i], & x[i]);
      if (x[i] == 0) {
        while (1) {
          auto a = pat.lower_bound(l[i]);
          if (a == pat.end() || * a > r[i]) break;
          sta[ * a] = 0;
          t[ * a] = i;
          pat.erase(a);
        }
      }
    } else {
      scanf("%d", & l[i]);
    }
  }
  build(1, 1, n);
  for (int i = 1; i <= q; i++)
    if (op[i] == 0 && x[i] == 1) {
      auto a = pat.lower_bound(l[i]);
      auto b = a;
      ++b;
      if (b != pat.end() && ( * b) <= r[i]) continue;
      if (sta[ * a] == -1) sta[ * a] = 1, t[ * a] = q + 1;
      t[ * a] = min(t[ * a], max(query(1, 1, n, l[i], r[i]), i));
    }
  for (int i = 1; i <= q; i++)
    if (op[i] == 1) {
      int a = l[i];
      if (sta[a] == -1 || t[a] > i) puts("N/A");
      else puts(sta[a] ? "YES" : "NO");
    }
}