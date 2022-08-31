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

int n;
bool solve() {
  scanf("%d", &n);
  multiset<ll> c1, c2;
  ll s = 0; 
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    s += a;
    c1.insert(a);
  }
  auto add = [&](ll x) {
    auto t = c1.lower_bound(x);
    if (t != c1.end() && *t == x) {
      c1.erase(t);
    } else c2.insert(x);
  };
  add(s);
  for (int i = 1; i < n; i++) {
    if (c2.empty()) return false;
    ll w = *c2.begin(); c2.erase(c2.begin());
    add(w / 2);
    add(w - w / 2);
  }
  return c2.empty();
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    puts(solve()?"YES":"NO");
  }
}