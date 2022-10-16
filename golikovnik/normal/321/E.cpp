#include <bits/stdc++.h>

using namespace std;

//  http://acm.math.spbu.ru/~sk1/algo/input-output/fread_write_export.cpp.html

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
  static char buf[buf_size];
  static int len = 0, pos = 0;
  if (pos == len)
    pos = 0, len = fread(buf, 1, buf_size, stdin);
  if (pos == len)
    return -1;
  return buf[pos++];
}

inline int readChar() {
  int c = getChar();
  while (c <= 32)
    c = getChar();
  return c;
}

template <class T>
inline T readInt() {
  int s = 1, c = readChar();
  T x = 0;
  if (c == '-')
    s = -1, c = getChar();
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getChar();
  return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n--)
    writeChar(s[n]);
  if (end)
    writeChar(end);
}

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

struct Flusher {
  ~Flusher() {
    if (write_pos)
      fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
  }
} flusher;

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = readInt();
  int k = readInt();
  vector<vector<int>> a(n, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= n; ++j) {
      a[i][j] = readInt();
      a[i][j] += a[i][j - 1];
    }
  }
  int const INF = numeric_limits<int>::max() / 3;
  vector<vector<int>> cost(n + 1, vector<int>(n + 1));
  for (int r = 0; r < n; ++r) {
    for (int l = r; l >= 0; --l) {
      cost[l][r] = a[l][r + 1] - a[l][l] + cost[l + 1][r];
    }
  }
  vector<int> dp(n + 1, INF), new_dp(n + 1, INF);
  function<void(int, int, int, int, int)> solve =
    [&](int l, int r, int opt_l, int opt_r, int level) {
      if (l > r) {
        return;
      }
      int m = (l + r) / 2;
      int val = INF;
      int id = -1;
      for (int j = opt_l; j <= opt_r; ++j) {
        auto cur = dp[j] + cost[j][m - 1];
        if (cur < val) {
          val = cur;
          id = j;
        }
      }
      new_dp[m] = val;
      solve(l, m - 1, opt_l, id, level + 1);
      solve(m + 1, r, max(0, id), opt_r, level + 1);
    };
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = cost[0][i];
  }
  for (int kk = 2; kk <= k; ++kk) {
    solve(1, n, 1, n, 0);
    dp.swap(new_dp);
  }
  writeInt(dp.back());
#ifdef GOLIKOV
  cerr << 1.0 * clock() / CLOCKS_PER_SEC << '\n';
#endif
}