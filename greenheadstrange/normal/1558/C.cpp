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

int n;
int p[maxn];
void solve() {
  scanf("%d", &n);
  vi ans;
  bool sol = true;
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
    if (p[i] % 2 != (i + 1) % 2)
      sol = false;
  }
  if (!sol) {
    puts("-1");
    return;
  }
  auto findpos = [&](int x) {
    for (int i = 0; i < n; i++)
      if (p[i] == x)
        return i;
    return -1;
  };
  auto addop = [&](int x) {
    if (x == 0)
      return;
    ans.pb(x + 1);
    reverse(p, p + x + 1);
  };
  for (int i = n; i > 1; i -= 2) {
    int x = findpos(i);
    addop(x);
    int y = findpos(i - 1);
    addop(y - 1);
    addop(y + 1);
    addop(2);
    addop(i - 1);
  }
  printf("%d\n", (int)ans.size());
  for (auto x : ans)
    printf("%d ", x);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++)
    solve();
}