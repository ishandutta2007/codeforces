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

vi magic;
map<int, vector<pi>> C;
pi way;
int D;
int dfs(int u, vector<pi> d) {
  set<int> p;
  for (auto x : d)
    p.insert(x.fi + x.se);
  if (p.size() <= 1) {
    if (u == 0) {
      way = {-1, 0};
    }
    return 1;
  }
  if (u == D) {
    return 2;
  } else {
    int ans = 100000;
    for (int z : magic) {
      map<int, vector<pi>> cc;
      for (auto x : d) {
        if (x.fi % z == 0)
          cc[x.fi / z * x.se].pb(x);
        else {
          cc[(x.fi / z) * x.se].pb(x);
          cc[(x.fi / z + 1) * x.se].pb(x);
        }
      }
      int w = 0;
      for (auto x : cc) {
        w = max(w, dfs(u + 1, x.se));
        if (w >= 2)
          break;
      }
      ans = min(ans, w);
      if (w == 1 && u == 0) {
        way = {0, z};
        C = cc;
        return 1;
      }
      if (ans == 1)
        break;
    }
    for (int z : magic) {
      map<int, vector<pi>> cc;
      for (auto x : d) {
        if (x.se % z == 0)
          cc[x.fi * (x.se / z)].pb(x);
        else {
          cc[(x.se / z) * x.fi].pb(x);
          cc[(x.se / z + 1) * x.fi].pb(x);
        }
      }
      int w = 0;
      for (auto x : cc) {
        w = max(w, dfs(u + 1, x.se));
        if (w >= 2)
          break;
      }
      if (w == 1 && u == 0) {
        way = {1, z};
        C = cc;
        return 1;
      }
      ans = min(ans, w);
      if (ans == 1)
        break;
    }
    return ans;
  }
}
int maxv = 0;

int query(vector<pi> d) {
  printf("? %d\n", (int)d.size());
  for (auto x : d)
    printf("%d %d ", x.fi, x.se);
  puts("");
  fflush(stdout);
  int c = 0;
  scanf("%d", &c);
  return c;
}
int main() {
  vector<pi> d, dd;
  for (int i = 1; i <= 200; i++)
    for (int j = 1; j <= 200; j++)
      d.pb({i, j});
  int w = query(d);
  for (int i = 2; i <= 200; i++)
    for (int j = 2; j <= 200; j++)
      if (i * j == w)
        dd.pb({i, j});
  magic.clear();
  for (int j = 2; j <= 200; j++)
    if (j <= 10 || w % j == 0)
      magic.pb(j);
  for (int i = 0; i < 3; i++) {
    D = 3 - i;
    way = {-2, 0};
    int f = dfs(0, dd);
    assert(f == 1);
    d.clear();
    if (way.fi == 0) {
      for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
          if (i % way.se == 0)
            d.pb({i, j});
    } else if (way.fi == 1) {
      for (int i = 1; i <= 200; i++)
        for (int j = 1; j <= 200; j++)
          if (j % way.se == 0)
            d.pb({i, j});
    } else {
      assert(way.fi == -1);
      break;
    }
    w = query(d);
    dd = C[w];
    assert(!dd.empty());
  }
  printf("! %d\n", 2 * (dd[0].fi + dd[0].se - 2));
  fflush(stdout);
}