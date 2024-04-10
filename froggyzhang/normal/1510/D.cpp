// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;
double g[N][15];
int f[N][15], from[N][15], my[N][15];
int n, d;

int zz[N];

vector<int> ans;
void dfs(int x, int y) {
  if (x == 0) return ;
  if (my[x][y]) ans.pb(x);
  dfs(x - 1, from[x][y]);
}

int main() {
  n = read(), d = read();
  for (int i = 1; i <= n; i++) {
    int a = read();
    zz[i] = a;
  }
  sort(zz + 1, zz + n + 1);
  f[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      if (!f[i - 1][j]) continue;
      int t = j * zz[i] % 10;
      if (!f[i][t] || g[i - 1][j] + log(zz[i]) > g[i][t]) {
        f[i][t] = 1;
        g[i][t] = g[i - 1][j] + log(zz[i]);
        my[i][t] = 1;
        from[i][t] = j;
      }
      if (!f[i][j] || g[i - 1][j] > g[i][j]) {
        f[i][j] = 1;
        g[i][j] = g[i - 1][j];
        my[i][j] = 0;
        from[i][j] = j;
      }
    }
  }
  if (!f[n][d]) return puts("-1") & 0;
  dfs(n, d);
  if (!ans.size()) return puts("-1") & 0;
  printf("%d\n", ans.size());
  for (auto v: ans) printf("%d ", zz[v]);
  puts(""); 
  return 0;
}