// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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
#define poly vector<int>
#define SZ(x) (int(x.size()))
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

const int N = 200005;
int ans[N], a[N];
char opt[N];
int n;

void fuck(int l, int r, int n) {
  if (n == 1) {
    ans[n] = a[l];
    return ;
  }
  if (opt[n - 1] == opt[n]) {
    ans[n] = a[l];
    fuck(l + 1, r, n - 1);
  } else {
    ans[n] = a[r];
    fuck(l, r - 1, n - 1);
  }
}
int main() {
  n = read();
  rep(i, 1, n) a[i] = read();
  scanf("%s", opt + 1);
  sort(a + 1, a + n + 1);
  if (opt[n] == 'L') {
    for (int i = n; i >= 1; i -= 2)
      a[i] = -a[i];
  } else {
    for (int i = n - 1; i >= 1; i -= 2)
      a[i] = -a[i];
  }
  fuck(1, n, n);
  rep(i, 1, n) {
    if (ans[i] > 0) printf("%d R\n", ans[i]);
    else printf("%d L\n", -ans[i]); 
  }
  return 0;
}