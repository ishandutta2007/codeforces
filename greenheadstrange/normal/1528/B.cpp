// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
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

int f[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
      f[j] += 1;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = (f[i] + sum) % mod;
    sum = (sum + f[i]) % mod;
  }
  printf("%d\n", f[n]);

  return 0;
}