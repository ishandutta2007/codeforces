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

// #ifdef DEBUG

const int N = 200005;

struct dot {
  int x, y, id;
} a[N], b[N];

int sq[N];
double ans = 1e9;
int special, n, m, S, SS;

dot operator + (dot a, dot b) {
  return {a.x + b.x, a.y + b.y};
}
dot operator - (dot a, dot b) {
  return {a.x - b.x, a.y - b.y};
}
bool operator == (dot a, dot b) {
  return 1ll * a.x * b.y == 1ll * a.y * b.x;
}
bool operator != (dot a, dot b) {
  return 1ll * a.x * b.y != 1ll * a.y * b.x;
}

inline double sqr(double x) {
  return x * x;
}
inline double dist(int x, int y) {
  return sqrt(sqr(a[x].x - a[y].x) + sqr(a[x].y - a[y].y));
}

int main() {
  scanf("%d%d", &m, &SS);
  rep(i, 1, m) {
    scanf("%d%d", &b[i].x, &b[i].y);
    b[i].id = i;
  }
  sort(b + 1, b + m + 1, [&](dot a, dot b) {
    return make_pair(a.x, a.y) <= make_pair(b.x, b.y);
  });
  rep(i, 1, m) {
    if (i == 1 || make_pair(b[i - 1].x, b[i - 1].y) != make_pair(b[i].x, b[i].y))
      a[++n] = b[i];
    if (b[i].id == SS) S = n;
  }
  if (n == 1) {
    puts("0.000000");
    return 0;
  }
  if (n == 2) {
    printf("%.10f\n", dist(1, 2));
    return 0;
  }
  if (n == 3) {
    double ans = 1e9;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (i != S && j != S && i != j) {
          ckmin(ans, dist(S, i) + dist(i, j));
        }
      }
    }
    printf("%.10f\n", ans);
    return 0;
  }
  dot a1 = a[2] - a[1], a2 = a[3] - a[1], a3 = a[3] - a[2], v;
  if (a1 == a2) v = a1;
  else if (a1 == a2) v = a2;
  else v = a3, special = 1;
  if (!special) {
    for (int i = 2; i <= n; i++)
      if ((a[i] - a[1]) != v)
        special = i;
  }
  if (!special) special = 1; // !!!

  // static int id[N];
  // iota(id + 1, id + n + 1, 1);
  // sort(id + 1, id + n + 1, [&](int p, int q) {
  //   return make_pair(a[p].x, a[p].y) < make_pair(a[q].x, a[q].y);
  // });
  // rep(i, 1, n) printf("id[%d] = %d\n", i, id[i]);
  
  // printf("special = %d\n", special);

  for (int i = 1; i <= n; i++) {
    if (i == S) {
      int t = 0;
      double sum = 0;
      if (i == special) {
        for (int j = 1; j <= n; j++) {
          if (j != special)
            sq[++t] = j;
        }
      } else {
        for (int j = i; j >= 1; j--)
          if (j != special)
            sq[++t] = j;
        for (int j = i + 1; j <= n; j++)
          if (j != special)
            sq[++t] = j;
      }
      // printf("sq = ");
      // for (int j = 1; j <= n - 1; j++)
      //   printf("%d ", j);
      // puts("");
      for (int j = 1; j < n - 1; j++)
        sum += dist(sq[j], sq[j + 1]);
      if (i != special) {
        ckmin(ans, sum + dist(special, sq[n - 1]));
        for (int j = n - 2; j >= 1; j--)
          ckmin(ans, sum - dist(sq[j], sq[j + 1]) + dist(sq[j], special) + dist(sq[j + 1], special));
      } else {
        ckmin(ans, sum + dist(special, sq[1]));
      }

      t = 0;
      if (i == special) {
        for (int j = n; j >= 1; j--)
          if (j != special)
            sq[++t] = j;
      } else {
        for (int j = i; j <= n; j++)
          if (j != special)
            sq[++t] = j;
        for (int j = i - 1; j >= 1; j--)
          if (j != special)
            sq[++t] = j;
      }
      sum = 0;
      for (int j = 1; j < n - 1; j++)
        sum += dist(sq[j], sq[j + 1]);
      if (i != special) {
        ckmin(ans, sum + dist(special, sq[n - 1]));
        for (int j = n - 2; j >= 1; j--)
          ckmin(ans, sum - dist(sq[j], sq[j + 1]) + dist(sq[j], special) + dist(sq[j + 1], special));
      } else {
        ckmin(ans, sum + dist(special, sq[1]));
      }
    }
  }
// #ifdef DEBUG
//   printf("final answer = ");
// #endif
  printf("%.10f\n", ans);
  return 0;
}