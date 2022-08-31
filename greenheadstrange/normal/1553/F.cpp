// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
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

int M = 300000;
int B = 600, R = M / B;
int m, p;
struct summer {
  ll s1[maxn], s2[maxn];
  void modify(int x, int s) {
    int t = x / B;
    for (int t = x / B + 1; t <= R; t++)
      s2[t] += s;
    int r = (x / B + 1) * B;
    for (int t = x; t < r; t++)
      s1[t] += s;
  }
  ll query(int x) {
    x = max(min(x, M), 0);
    return s2[x / B] + s1[x];
  }
} s2, s1;
ll ans = 0;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    for (int x = 0; x <= M; x += p) {
      ans += (s1.query(x + p - 1) - s1.query(x - 1)) -
             (s2.query(x + p - 1) - s2.query(x - 1)) * x;
    }
    for (int l = 1; l <= p; l++) {
      int d = p / l;
      int r = p / d;
      ans += p * (s2.query(r) - s2.query(l - 1)) -
             d * (s1.query(r) - s1.query(l - 1));
      l = r;
    }
    ans += p * (i - 1 - s2.query(p));
    s1.modify(p, p);
    s2.modify(p, 1);
    printf("%lld ", ans);
  }
  printf("\n");
}