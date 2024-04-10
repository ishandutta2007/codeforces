// July 26, 2019
// https://codeforces.com/contest/1197/problem/D

/*
1LL * k * (i + m - 1) / m != 1LL * (i + m - 1) / m * k.

Also, how's this convention: when the variables in the problem statement are
capitals (e.g. N), use MAXN. But when they're lowercase, just use the uppercase
letter to denote the max value, such as in this code.
*/


#include <bits/stdc++.h>

using namespace std;


const long long INF = 1e18;
const int N = 300001;
const int M = 10;


int n, m, k;
int a[N];
long long psa[N];
long long mn[M];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psa[i] = psa[i - 1] + a[i];
  }
  long long ans = 0;
  fill(mn + 1, mn + m, INF);
  for (int i = 1; i <= n; i++) {
    long long x = psa[i] - 1LL * (i + m - 1) / m * k;
    for (int j = 0; j < m; j++) {
      long long y = x - mn[j];
      int rhs = i % m;
      if (rhs == 0) {
        rhs = m;
      }
      int lhs = j;
      if (j == 0) {
        lhs = m;
      }
      if (lhs < rhs) {
        y -= k;
      }
      ans = max(ans, y);
    }
    mn[i % m] = min(mn[i % m], x);
  }
  cout << ans << '\n';


  return 0;
}