#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

#define MAXN 2005

int n, m, k;
int x[MAXN];
int y[MAXN];
char M[MAXN][MAXN];
int up[MAXN][MAXN];
int dn[MAXN][MAXN];
int h_up[MAXN];
int h_dn[MAXN];

struct monotonic_queue {
  deque< int > monotonic;
  deque< int > real;

  void push(int x) {
    real.push_back(x);
    while (!monotonic.empty() && monotonic.back() > x)
      monotonic.pop_back();
    monotonic.push_back(x);
  }

  void pop() {
    if (monotonic.front() == real.front())
      monotonic.pop_front();
    real.pop_front();
  }

  void clear() {
    while (!real.empty()) pop();
  }

  int min() { return monotonic.front(); }
};

monotonic_queue mq_up, mq_dn;
int sol[MAXN];

int main(void) {
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 1; i <= n; ++i)
    scanf("%s", M[i] + 1);

  REP(i, k) scanf("%d%d", x + i, y + i);

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      up[i][j] = (M[i][j] == 'X') ? 0 : up[i - 1][j] + 1;

  for (int i = n; i >= 1; --i)
    for (int j = 1; j <= m; ++j)
      dn[i][j] = (M[i][j] == 'X') ? 0 : dn[i + 1][j] + 1;

  auto get_best = [](int r, int t) {
    mq_up.clear();
    mq_dn.clear();
    int ret = 0;
    for (int i = 1; i <= m; ++i) h_up[i] = up[r][i], h_dn[i] = dn[r][i];
    REP(i, t) {
      if (x[i] <= r) h_up[y[i]] = min(h_up[y[i]], r - x[i]);
      if (x[i] >= r) h_dn[y[i]] = min(h_dn[y[i]], x[i] - r);
    }
    for (int i = 1, j = 1; i <= m; ++i) {
      mq_up.push(h_up[i]);
      mq_dn.push(h_dn[i]);
      while (j <= i && mq_up.min() + mq_dn.min() - 1 < i - j + 1) {
	mq_up.pop();
	mq_dn.pop();
	++j;
      }
      if (j <= i)
	ret =  max(ret, min(i - j + 1, mq_up.min() + mq_dn.min() - 1));
    }
    return ret;
  };

  int csol = 0;
  for (int r = 1; r <= n; ++r)
    csol = max(csol, get_best(r, k));

  for (int t = k - 1; t >= 0; --t) { 
    sol[t] = csol;
    csol = max(csol, get_best(x[t], t));
  }

  REP(i, k) printf("%d\n", sol[i]);

  return 0;
}