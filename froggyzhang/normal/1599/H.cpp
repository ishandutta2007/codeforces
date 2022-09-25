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

int main() {
  printf("? 1 1\n"), fflush(stdout);
  int a00; scanf("%d", &a00);
  printf("? 1 1000000000\n"), fflush(stdout);
  int a01; scanf("%d", &a01);
  printf("? 1000000000 1\n"), fflush(stdout);
  int a10; scanf("%d", &a10);
  int l = 2, r = a00 + 1;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    printf("? 1 %d\n", mid), fflush(stdout);
    int dist; scanf("%d", &dist);
    if (dist + mid - 1 == a00) l = mid;
    else r = mid - 1;
  }
  // printf("qwq %d\n", l);
  int x0 = a00 + 2 - l, y0 = l;
  int y1 = 1e9 - (a01 - x0);
  int x1 = 1e9 - (a10 - y0);
  printf("! %d %d %d %d\n", x0, y0, x1 - 1, y1 - 1), fflush(stdout);
  return 0;
}