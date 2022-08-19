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
  multiset < ll > num;
  scanf("%d%d", & n, & x);
  for (int i = 1; i <= n; i++) {
    int y;
    scanf("%d", & y);
    num.insert(y);
  }
  int cnt = 0;
  while (!num.empty()) {
    ll y = * num.begin();
    num.erase(num.begin());
    auto it = num.find(y * x);
    if (it == num.end()) cnt++;
    else num.erase(it);
  }
  printf("%d\n", cnt);
}

int main() {
  int T;
  scanf("%d", & T);
  for (int i = 0; i < T; i++) solve();
}