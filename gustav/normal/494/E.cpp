#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>
#include <map>
#include <unordered_set>
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

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MAXM = 50005;

int N, M, K;
int a[MAXM], b[MAXM];
int c[MAXM], d[MAXM];

const int off = 1 << 17;

#define L(n) ((n) << 1)
#define R(n) (L(n) | 1)

struct Node {
  int len, cnt;
  int covered;
};

Node T[off << 1];

void merge(int n) {
  if (T[n].covered) 
    T[n].cnt = T[n].len;
  else if (n < off)
    T[n].cnt = T[L(n)].cnt + T[R(n)].cnt;
  else
    T[n].cnt = 0;
}

void update(int lo, int hi, int v, int l = 0, int r = off, int n = 1) {
  if (l >= hi || r <= lo) return;
  if (l >= lo && r <= hi) {
    T[n].covered += v;
    merge(n);
    return;
  }

  update(lo, hi, v, l, (l + r) / 2, L(n));
  update(lo, hi, v, (l + r) / 2, r, R(n));
  merge(n);
}

vector< int > v;

struct Event {
  int x, lo, hi;
  int type;
};

bool operator<(const Event &a, const Event &b) {
  return a.x < b.x;
}

llint get_area() {
  v.clear();

  REP(i, M) {
    v.push_back(b[i] + 1);
    v.push_back(d[i] + 1);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  memset(T, 0, sizeof T);

  REP(i, (int)v.size() - 1) 
    T[i + off].len = v[i + 1] - v[i];

  for (int i = off - 1; i >= 1; --i)
    T[i].len = T[L(i)].len + T[R(i)].len;

  vector< Event > E;

  REP(i, M) {
    int lo = lower_bound(v.begin(), v.end(), b[i] + 1) - v.begin();
    int hi = lower_bound(v.begin(), v.end(), d[i] + 1) - v.begin();
    E.push_back({ a[i] + 1, lo, hi, +1 });
    E.push_back({ c[i] + 1, lo, hi, -1 });
  }

  sort(E.begin(), E.end());
  int last = E[0].x;
  llint ret = 0;
  
  for (int i = 0, j; i < (int)E.size(); i = j) {
    for (j = i + 1; j < (int)E.size() && E[j].x == E[i].x; ++j);
    ret += (llint)(E[i].x - last) * T[1].cnt;
   
    FOR(k, i, j) 
      update(E[k].lo, E[k].hi, E[k].type);

    last = E[i].x;
  }

  return ret;
}

int area[33];

int main(void)
{
  scanf("%d%d%d", &N, &M, &K);

  REP(i, M) {
    scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
    --a[i]; --b[i];
  }

  int pwr = 0;
  while (K) {
    area[pwr] = get_area() % 2;
    REP(i, M) a[i] /= 2, b[i] /= 2, c[i] /= 2, d[i] /= 2;
    K /= 2;
    ++pwr;
  }

  for (int i = 0; i < pwr - 1; ++i)
    area[i] ^= area[i + 1];

  int ret = 0;
  for (int i = pwr - 1; i >= 0; --i)
    ret = ret * 2 + area[i];

  if (ret)
    puts("Hamed");
  else
    puts("Malek");

  return 0;
}