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

char ss[1555], tt[1555];

bool solve() {
  scanf("%s%s", ss, tt);
  int n = strlen(ss);
  int m = strlen(tt);
  string s = ss;
  string t = tt;
  for (int i = 0; i < n; i++) {
    string p1;
    p1.pb(s[i]);
    for (int j = i; j < n; j++) {
      if (j != i)
        p1.pb(s[j]);
      string p2 = p1;
      for (int k = j; k >= 0; k--) {
        if (k != j)
          p2.pb(s[k]);
        if (p2.length() == m && p2 == t)
          return true;
      }
    }
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    puts(solve() ? "YES" : "NO");
  }
}