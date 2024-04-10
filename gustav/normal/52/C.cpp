#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long llint;
const int off = 1 << 18;
const llint inf = 1000000000000000000LL;

int N, M;
llint t[off << 1];
llint p[off << 1];
int lo, hi, l, r, v;

void push(int n) {
  t[2 * n] += p[n];
  p[2 * n] += p[n];
  t[2 * n + 1] += p[n];
  p[2 * n + 1] += p[n];
  p[n] = 0;
}

void update(int n, int x, int y) {
  if (x >= hi || y <= lo) return;
  if (x >= lo && y <= hi) {
    p[n] += v;
    t[n] += v;
    return;
  }
  push(n);
  update(2 * n, x, (x + y) / 2);
  update(2 * n + 1, (x + y) / 2, y);
  t[n] = min(t[2 * n], t[2 * n + 1]);
}

llint query(int n, int x, int y) {
  if (x >= hi || y <= lo) return inf;
  if (x >= lo && y <= hi) return t[n];
  push(n);
  llint ret = inf;
  ret = min(ret, query(2 * n, x, (x + y) / 2));
  ret = min(ret, query(2 * n + 1, (x + y) / 2, y));
  return ret;
}

void cupdate() {
  if (l > r) {
    lo = 0, hi = r + 1; 
    update(1, 0, off);
    lo = l, hi = N; 
    update(1, 0, off);
  } else {
    lo = l, hi = r + 1;
    update(1, 0, off);
  }
}

llint cquery() {
  llint ret = inf;
  if (l > r) {
    lo = 0, hi = r + 1; 
    ret = min(ret, query(1, 0, off));
    lo = l, hi = N; 
    ret = min(ret, query(1, 0, off));
  } else {
    lo = l, hi = r + 1;
    ret = min(ret, query(1, 0, off));
  }
  return ret;
}

int main(void)
{
  memset(t, 0x3f, sizeof t);

  scanf("%d\n", &N);

  for (int i = 0; i < N; ++i) {
    cin >> t[i + off];
    for (int j = (i + off) / 2; j; j /= 2)
      t[j] = min(t[2 * j], t[2 * j + 1]);
  }

  scanf("%d\n", &M);

  char buf[128];

  for (int i = 0; i < M; ++i) {
    fgets(buf, 100, stdin);
    if (sscanf(buf, "%d%d%d", &l, &r, &v) == 3) {
      cupdate();
    } else {
      cout << cquery() << endl;
    }
  }

  return 0;
}