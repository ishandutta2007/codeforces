// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 10005 /*rem*/
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

int n;
void solve() {
  scanf("%d", &n);
  vi s;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 1) {
      s.pb(x);
    } else {
      while (!s.empty() && s.back() != x - 1)
        s.pop_back();
      s.back() += 1;
      assert(!s.empty());
    }
    for (int j = 0; j < s.size(); j++) {
      printf("%d", s[j]);
      if (j != s.size() - 1)
        printf(".");
    }
    printf("\n");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}