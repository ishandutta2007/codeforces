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

int n, mark[maxn];
char s[maxn];
void solve() {
  scanf("%s", s);
  int n = strlen(s);
  set<char> ch;
  string ans;
  for (int i = n - 1; i >= 0; i--) {
    if (!ch.count(s[i])) mark[i] = 1;
    else mark[i] = 0;
    ch.insert(s[i]);
  }
  for (int i = 0; i < n; i++) if (mark[i]) {
    puts(s + i);
    break;
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) solve();
}