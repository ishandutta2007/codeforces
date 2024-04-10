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

int n;
int a[maxn];
bool ans;
void dfs(int x, int sum, int flag) {
  if (x == n) {
    if (sum == 0 && flag)
      ans = true;
  } else {
    for (int i = -1; i <= 1; i++)
      dfs(x + 1, sum + i * a[x], flag | (i != 0));
  }
}
bool solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  ans = false;
  dfs(0, 0, 0);
  return ans;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    puts(solve() ? "YES" : "NO");
  }
}