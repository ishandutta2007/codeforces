// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
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

stack<array<ll, 3>> st;
int n;
ll a[maxn];
vector<array<int, 4>> evt1[66], evt2[66];

struct myquery {
  array<ll, 3> item[maxn * 2];
  int t, tot;
  void init() {
    t = 0;
    tot = 0;
  }

  void add(int l, int r) {
    item[t] = {l, -1, tot + 1};
    item[t + 1] = {r, 1, tot + r - l + 1};
    tot += r - l + 1;
    t += 2;
  }
  void del(int l, int r) {
    assert(item[t - 2][0] == l);
    assert(item[t - 1][0] == r);
    t -= 2;
    tot -= r - l + 1;
  }
  int query(int l) {
    int v = lower_bound(item, item + t, array<ll, 3>{l, 0, 0}) - item;
    if (v == t) return tot;
    if (item[v][1] == -1) {
      return item[v][2] - 1;
    } else {
      return item[v - 1][2] + l - item[v - 1][0];
    }
  }
  int query(int l, int r) { return query(r) - query(l - 1); }
} f1, f2;

mt19937_64 rnd(1);
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  st.push({0, 0, 1ll << 60});
  for (int i = 1; i <= n; i++) {
    int L = i;
    while (st.top()[2] < a[i]) {
      evt1[__builtin_popcountll(st.top()[2])].push_back(
          {-1, (int)st.top()[0], (int)st.top()[1], i});
      L = st.top()[0];
      st.pop();
    }

    st.push({L, i, a[i]});
    evt1[__builtin_popcountll(a[i])].push_back({1, L, i, i});
  }
  a[0] = -1;
  st = stack<array<ll, 3>>();
  st.push({0, 0, -1ll});
  for (int i = 1; i <= n; i++) {
    int L = i;
    while (st.top()[2] > a[i]) {
      evt2[__builtin_popcountll(st.top()[2])].push_back(
          {-1, (int)st.top()[0], (int)st.top()[1], i});
      L = st.top()[0];
      st.pop();
    }

    st.push({L, i, a[i]});
    evt2[__builtin_popcountll(a[i])].push_back({1, L, i, i});
  }
  ll ans = 0;
  for (int w = 0; w < 60; w++) {
    f1.init();
    f2.init();
    int inter = 0;
    int r1 = 0, r2 = 0;
    for (int i = 1; i <= n; i++) {
      while (r1 < evt1[w].size() && evt1[w][r1][3] == i) {
        auto p = evt1[w][r1];
        if (p[0] == 1)
          inter += f2.query(p[1], p[2]), f1.add(p[1], p[2]);
        else
          inter -= f2.query(p[1], p[2]), f1.del(p[1], p[2]);
        ++r1;
      }
      while (r2 < evt2[w].size() && evt2[w][r2][3] == i) {
        auto p = evt2[w][r2];
        if (p[0] == 1)
          inter += f1.query(p[1], p[2]), f2.add(p[1], p[2]);
        else
          inter -= f1.query(p[1], p[2]), f2.del(p[1], p[2]);
        ++r2;
      }
      ans += inter;
    }
  }
  printf("%lld\n", ans);
}