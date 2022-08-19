// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 800005 /*rem*/
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

int n;
pi p[maxn];

bool check(int M) {
  int s = 0;
  int L = 0;
  int R = 0;
  for (int i = 0; i < n; i++) {
    int x = p[i].fi, y = p[i].se;
    int t = x + y;
    R += t - s;
    L = max(L, x - M);
    R = min(R, x + M);
    if (L > R)
      return false;
    s = t;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = mp(x, y);
  }
  sort(p, p + n, [&](pi a, pi b) { return a.fi + a.se < b.fi + b.se; });
  multiset<ll> pL, pR;
  ll offR = 0, ans = 0;
  pL.insert(p[0].fi);
  pR.insert(p[0].fi);
  for (int i = 1; i < n; i++) {
    int d = (p[i].fi + p[i].se) - (p[i - 1].fi + p[i - 1].se);
    offR += d;
    int x = p[i].fi;
    ll fL = *pL.rbegin(), fR = *pR.begin() + offR;
    if (fL <= x && fR >= x) {
      pL.insert(x);
      pR.insert(x - offR);
    } else if (x < fL) {
      pL.insert(x);
      pL.insert(x);
      ll y = *pL.rbegin();
      pL.erase(--pL.end());
      pR.insert(y - offR);
      ans += abs(y - x);
    } else {
      pR.insert(x - offR);
      pR.insert(x - offR);
      ll y = *pR.begin() + offR;
      pR.erase(pR.begin());
      pL.insert(y);
      ans += abs(y - x);
    }
  }
  printf("%lld\n", ans);
}