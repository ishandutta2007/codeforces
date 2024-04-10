#include <cstdio>
#include <cstring>
#include <cctype>

#include <algorithm>
#include <queue>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct IO_Tp
{
  const static int _I_Buffer_Size = 20 << 20;
  char _I_Buffer[_I_Buffer_Size], *_I_pos;

  IO_Tp() : _I_pos(_I_Buffer) {
#ifdef LBT
    freopen("test.in", "r", stdin);
#endif
    fread(_I_Buffer, 1, _I_Buffer_Size, stdin);
  }

  IO_Tp &operator>>(int &res)
  {
    while (!isdigit(*_I_pos))
      ++_I_pos;
    res = *_I_pos++ & 15;
    while (isdigit(*_I_pos))
      (res *= 10) += *_I_pos++ & 15;
    return *this;
  }

  IO_Tp &operator>>(char *res)
  {
    while (isspace(*_I_pos))
      ++_I_pos;
    while (!isspace(*_I_pos))
      *res++ = *_I_pos++;
    *res = '\0';
    return *this;
  }
} IO;

const int N = 12, M = 100005;

int n, m;
int c[N][M];
int re[M], ce[M];
int deg[N][M];
bool cr[N][M], cd[N][M], tag[N][M][4];
int ans[M];
vector<pair<int, int>> modi[M];

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool& cango(int x, int y, int dir) {
  if (dir == 0)
    return cr[x][y];
  else if (dir == 1)
    return cd[x][y];
  else if (dir == 2)
    return cr[x][y - 1];
  else
    return cd[x - 1][y];
}

struct Que {
  int que[N * M * 2];
  int l, r;

  Que() : l(), r() {}

  void push(int x) { que[r++] = x; }
  void pop() { ++l; }
  int front() { return que[l]; }
  bool empty() { return l == r; }
} q;

void release() {
  while (!q.empty()) {
    int x, y;
    x = q.front(); q.pop();
    y = q.front(); q.pop();
    if (deg[x][y] < 1) continue;
    --deg[x][y];
    for (int dir = 0; dir < 4; ++dir)
      if (cango(x, y, dir)) {
        cango(x, y, dir) = false;

        if (--deg[x + dx[dir]][y + dy[dir]] == 1) {
          q.push(x + dx[dir]);
          q.push(y + dy[dir]);
        }
        break;
      }
  }
}

int fw[M];

int lowBit(int k) { return k & -k; }

void ch(int k) {
  for (; k <= m; k += lowBit(k))
    ++fw[k];
}

int qry(int k) {
  int ret = 0;
  for (; k; k -= lowBit(k))
    ret += fw[k];
  return ret;
}

int main() {
  int qr;
  IO >> n >> m >> qr;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      IO >> c[i][j];
  for (int j = 1; j <= m; ++j) {
    for (int i = 2; i <= n; ++i)
      if (c[i][j] == c[i - 1][j]) {
        ++ce[j];
        ++deg[i][j];
        ++deg[i - 1][j];
        cd[i - 1][j] = true;
      }
    if (j > 1) {
      for (int i = 1; i <= n; ++i)
        if (c[i][j] == c[i][j - 1]) {
          ++re[j];
          ++deg[i][j];
          ++deg[i][j - 1];
          cr[i][j - 1] = true;
        }
    }
    ce[j] += ce[j - 1];
    re[j] += re[j - 1];
  }
  for (int i = 1; i <= n; ++i)
    c[i][0] = c[i][m + 1] = -1;
  for (int j = 1; j <= m; ++j)
    c[0][j] = c[n + 1][j] = -1;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (deg[i][j] == 1) {
        q.push(i);
        q.push(j);
      }

  release();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      release();
      while (deg[i][j] > 1) {
        int dir = 0;
        while (!cango(i, j, dir)) ++dir;
        cango(i, j, dir) = false;
        if (--deg[i][j] == 1) {
          q.push(i); q.push(j);
        }
        int mn = j, mx = j;
        int x = i, y = j, gx = x + dx[dir], gy = y + dy[dir];
        if (--deg[gx][gy] == 1) {
          q.push(gx); q.push(gy);
        }
        while (x != gx || y != gy) {
          while (!cango(x, y, dir)) dir = (dir + 1) % 4;
          if (tag[x][y][dir]) break;
          tag[x][y][dir] = true;
          x += dx[dir]; y += dy[dir];
          mn = min(mn, y);
          mx = max(mx, y);
          dir = (dir + 3) % 4;
          if (x == i && y == j) break;
        }
        if (x == gx && y == gy) {
          modi[mn].emplace_back(mx, -1);
        }
        release();
      }
    }
  for (int i = 1; i <= qr; ++i) {
    int l, r;
    IO >> l >> r;
    int vertices = (r - l + 1) * n, edges = ce[r] - ce[l - 1] + re[r] - re[l];
    ans[i] = vertices - edges;
    modi[l].emplace_back(r, i);
  }
  for (int i = m; i; --i)
    for (const auto& pr : modi[i])
      if (pr.second == -1)
        ch(pr.first);
      else
        ans[pr.second] += qry(pr.first);
  for (int i = 1; i <= qr; ++i)
    printf("%d\n", ans[i]);
  return 0;
}