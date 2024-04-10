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

int n, a[maxn], b[maxn];

void solve() {
  scanf("%d", &n);
  if (n == 2) {
    puts("-1");
    return;
  }
  ll mult = 1;
  multiset<int> od, ev;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 1)
      od.insert(i);
    else
      ev.insert(i);
  }
  vector<pair<int, int>> ans;
  auto add = [&](int x, int y) { ans.push_back({x * mult, y * mult}); };
  while (true) {
    while (!od.empty()) {
      auto it = --od.end();
      if (*it == 1) {
        if (od.size() == 1) {
          if (ev.count(0)) {
            add(1, 0);
            add(1, 1);
            ev.insert(2);
          } else {
            assert(ev.count(2));
            add(1, 2);
            add(1, 3);
            od.erase(od.lower_bound(1));
            ev.insert(4);
          }
        } else {
          if (od.size() % 2 == 0) {
            for (int i = 0; i < od.size() / 2; i++) {
              add(1, 1);
              ev.insert(2);
              ev.insert(0);
            }
          } else {
            for (int i = 0; i < od.size() / 2; i++) {
              add(1, 1);
              ev.insert(2);
              ev.insert(0);
            }
            add(1, 0);
            add(1, 1);
            ev.insert(2);
          }
        }
        od.clear();
      } else {
        int x = 1;
        while (x < *it) x *= 2;
        int y = x - (*it);
        x = *it;
        assert(od.find(y) != od.end());
        add(x, y);
        od.erase(od.lower_bound(x));
        od.erase(od.lower_bound(y));
        ev.insert(x + y);
        ev.insert(abs(x - y));
      }
    }
    mult *= 2;
    multiset<int> pev = ev;
    ev.clear();
    int maxv = 0;
    for (auto x : pev) {
      x /= 2;
      maxv = max(maxv, x);
      if (x % 2 == 1)
        od.insert(x);
      else
        ev.insert(x);
    }
    if (maxv == 1) break;
  }
  for (int i = 0; i < ev.size(); i++) add(1, 0);
  printf("%d\n", ans.size());
  for (auto p : ans) {
    printf("%d %d\n", p.fi, p.se);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) solve();
}