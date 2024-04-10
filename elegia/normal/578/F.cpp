#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int N = 110, K = 210;

int P;
char s[N][N];
int mat[K][K];

int norm(int x) { return x >= P ? x - P : x; }

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  return norm(x + P);
}

void add(int& x, int y) {
  if ((x += y) >= P)
    x -= P;
}

void sub(int& x, int y) {
  if ((x -= y) < 0)
    x += P;
}

int det(int n) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      mat[i][j] = norm(P + mat[i][j] % P);
  int ret = 1;
  for (int i = 1; i <= n; ++i) {
    int p = i;
    while (p <= n && !mat[p][i]) ++p;
    if (p > n)
      return 0;
    if (p != i) {
      for (int j = i; j <= n; ++j)
        swap(mat[p][j], mat[i][j]);
      ret = norm(P - ret);
    }
    ret = ret * (ll)mat[i][i] % P;
    int nv = inv(mat[i][i]);
    for (int j = i; j <= n; ++j)
      mat[i][j] = mat[i][j] * (ll)nv % P;
    for (int j = p + 1; j <= n; ++j)
      for (int k = n; k >= i; --k)
        mat[j][k] = (P + mat[j][k] - mat[j][i] * (ll)mat[i][k] % P) % P;
  }
  return ret;
}

int n, m;

int f[N * N], lab[N * N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int ind(int x, int y) { return x * (m + 1) + y; }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> P;
  for (int i = 1; i <= n; ++i)
    cin >> (s[i] + 1);
  int k = 0;
  for (int i = 1; i <= n; ++i)
    k += count(s[i] + 1, s[i] + m + 1, '*');

  int ans = 0;
  for (int b = 0; b < 2; ++b) {
    iota(f, f + (n + 1) * (m + 1), 0);
    memset(mat, 0, sizeof(mat));
    memset(lab, -1, sizeof(lab));
    int cn = 0;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        cn += ((i + j) & 1) == b;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (s[i][j] != '*' && (s[i][j] == '/' ? ((i + j - 1) & 1) : ((i + j) & 1)) == b) {
          int x = (s[i][j] == '/') ? ind(i, j - 1) : ind(i - 1, j - 1), y = (s[i][j] == '/') ? ind(i - 1, j) : ind(i, j);
          x = find(x); y = find(y);
          if (x != y) {
            f[x] = y;
            --cn;
          } else
            goto TAG;
        }
    if (k < cn - 1)
      continue;
    {
      int cnt = 0;
      for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
          if (((i + j) & 1) == b)
            if (lab[find(ind(i, j))] == -1)
              lab[find(ind(i, j))] = cnt++;
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          if (s[i][j] == '*') {
            int x = ((i + j) & 1) == b ? ind(i, j) : ind(i - 1, j),
                y = ((i + j) & 1) == b ? ind(i - 1, j - 1) : ind(i, j - 1);
            x = lab[find(x)]; y = lab[find(y)];
            ++mat[x][x]; ++mat[y][y];
            --mat[x][y]; --mat[y][x];
          }
      add(ans, det(cnt - 1));
    }
    TAG:;
  }
  cout << ans;

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}