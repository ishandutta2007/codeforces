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

int n, m;
char s[55][55];
bool check(int d) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int x = "RW"[(i + j + d) % 2];
      if (s[i][j] != '.' && s[i][j] != x)
        return false;
    }
  puts("YES");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      putchar("RW"[(i + j + d) % 2]);
    }
    puts("");
  }
  return true;
}

void solve() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  if (check(0)) {
    return;
  }
  if (check(1)) {
    return;
  }
  puts("NO");
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}