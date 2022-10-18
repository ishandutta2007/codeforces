#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <stack>
#include <queue>
#include <vector>

#include <bitset>

#include <string>

#include <algorithm>
#include <functional>

#include <iostream>
#include <sstream>

using namespace std;
typedef long long llint;

#define pb push_back
#define MAXN 100005

const int off = 1 << 17;
const llint inf = 1000000000000000000LL;

struct line {
  llint a, b;
  line(llint a, llint b) : a(a), b(b) {}
  llint operator()(llint x) { return a * x + b; }
};

llint ccw(line p, line q, line r) {
  return p.a * (q.b - r.b) + q.a * (r.b - p.b) + r.a * (p.b - q.b);
}

bool operator<=(line p, line q) {
  if (p.a == q.a) return p.b >= q.b;
  return p.a <= q.a;
}

deque< line > h;
vector< line > T[off << 1];

void build_hull(int n) {
  h.clear();

  if (T[n].size() < 2)
    return;

  h.push_front(T[n][0]);
  h.push_front(T[n][1]);

  for (int i = 2; i < T[n].size(); ++i) {
    while (h.size() >= 2 && ccw(h[1], h[0], T[n][i]) <= 0) 
      h.pop_front();
    h.push_front(T[n][i]);
  }

  T[n].clear();
  for (int i = h.size() - 1; i >= 0; --i)
    T[n].pb(h[i]);
}

void merge(int n) {
  int l = 2 * n;
  int r = 2 * n + 1;
  int lp = 0;
  int rp = 0;

  while (lp < T[l].size() && rp < T[r].size()) {
    if (T[l][lp] <= T[r][rp]) 
      T[n].pb(T[l][lp++]);
    else
      T[n].pb(T[r][rp++]);
  }

  while (lp < T[l].size()) T[n].pb(T[l][lp++]);
  while (rp < T[r].size()) T[n].pb(T[r][rp++]);

  build_hull(n);
}

void build(int n) {
  if (n >= off) return;
  build(2 * n);
  build(2 * n + 1);
  merge(n);
}

llint node_query(int n, llint x) {
  int lo = 0, hi = T[n].size() - 1, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (T[n][mid](x) < T[n][mid + 1](x))
      hi = mid;
    else
      lo = mid + 1;
  }
  return T[n][lo](x);
}

llint query(int lo, int hi, int x, int l = 0, int r = off, int n = 1) {
  if (l >= hi + 1 || r <= lo) return inf;
  if (l >= lo && r <= hi + 1) return node_query(n, x);
  int m = (l + r) / 2;
  return min(query(lo, hi, x, l, m, 2 * n),
             query(lo, hi, x, m, r, 2 * n + 1));
}

int N, M;
int x, y;
int a[MAXN];
llint s[MAXN];

int main(void)
{
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", a + i);
    s[i] = s[i - 1] + a[i];
  }

  for (int i = 1; i <= N; ++i) 
    T[off + i].pb(line(a[i], (llint)(i - 1) * a[i] - s[i - 1]));

  build(1);

  scanf("%d", &M);

  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &x, &y);
    cout << query(y - x + 1, y, x - y) + s[y] << endl;
  }

  return 0;
}