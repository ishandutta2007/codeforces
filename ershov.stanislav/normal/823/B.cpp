#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld pi = acos((ld) -1);
const int inf = (int) 1.01e9;

#define sz(a) (int) (a).size()

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

mt19937 mrand(random_device{} ());

int rnd(int x) {
  return mrand() % x;
}

const int maxn = (int) 1e5 + 5;
int n;
char tmp[maxn];
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

const int maxlen = 11, sigma = 4;
vector<int> fen[maxlen][maxlen][sigma];

int tonum(char c) {
  return (c == 'A' ? 0 : (c == 'T' ? 1 : (c == 'G' ? 2 : 3)));
}

void update(vector<int> &fen, int x, int toadd) {
  for (; x < sz(fen); x |= (x + 1)) {
    fen[x] += toadd;
  }
}

int get1(vector<int> &fen, int x) {
  int res = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    res += fen[x];
  }
  return res;
}

int get(vector<int> &fen, int l, int r) {
  return get1(fen, r - 1) - get1(fen, l - 1);
}

void solve() {
  for (int len = 1; len < maxlen; len++) {
    for (int r = 0; r < len; r++) {
      for (int c = 0; c < sigma; c++) {
        fen[len][r][c].clear();
        fen[len][r][c].resize((n + len - 1) / len + 5);
        for (int i = 0; r + i * len < n; i++) {
          if (tonum(s[r + i * len]) == c) {
            update(fen[len][r][c], i, 1);
          }
        }
      }
    }
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d%s", &x, tmp);
      x--;
      int nc = tonum(tmp[0]);
      for (int len = 1; len < maxlen; len++) {
        int r = x % len;
        int pos = x / len;
        update(fen[len][r][tonum(s[x])], pos, -1);
        update(fen[len][r][nc], pos, 1);
      }
      s[x] = tmp[0];
    } else {
      int l, r;
      scanf("%d%d%s", &l, &r, tmp);
      l--;
      string e = tmp;
      int len = sz(e);
      int res = 0;
      for (int pos = 0; pos < len; pos++) {
        int k = (l + pos) % len;
        int l0 = (l + pos) / len, r0 = (r - k + len - 1) / len;
        if (r0 <= l0) {
          continue;
        }
        res += get(fen[len][k][tonum(e[pos])], l0, r0);
      }
      printf("%d\n", res);
    }
  }
}

int main() {
#ifdef DEBUG
  freopen("text.out", "w", stdout);
  assert(freopen("text.in", "r", stdin));
#endif

  while (read()) {
    solve();
    eprintf("Time: %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
  }

  return 0;
}