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

ll ksm(ll a, ll b) {
  if (!b) return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1) ns = ns * a % mod;
  return ns;
}

int n, x;
void solve() {
  scanf("%d", & n);
  map < int, int > cnt;
  vi v, t;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", & x);
    v.pb(x);
    t.pb(x);
    cnt[x]++;
  }
  for (auto p: cnt)
    if (p.se % 2 != 0) {
      puts("-1");
      return;
    }
  int off = 0;
  vi ans;
  vector < pi > op;
  while (!v.empty()) {
    int x = v[0], y = -1;
    for (int i = 1; i < v.size(); i++)
      if (v[i] == x) {
        y = i;
        break;
      }
    for (int j = 1; j < y; j++) {
      op.pb({
        off + j + y,
        v[j]
      });
    }
    off += 2 * y;
    ans.pb(2 * y);
    v.erase(v.begin() + y);
    v.erase(v.begin());
    if (y >= 2) reverse(v.begin(), v.begin() + y - 1);
  }
  printf("%d\n", (int) op.size());
  for (auto p: op) {
    printf("%d %d\n", p.fi, p.se);
  }
  printf("%d\n", (int) ans.size());
  for (auto p: ans) printf("%d ", p);
  puts("");
}

int main() {
  int T;
  scanf("%d", & T);
  for (int i = 0; i < T; i++) solve();
}