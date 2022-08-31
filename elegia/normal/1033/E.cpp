#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef vector<int> VI;

void errln(const VI& v) {
  LOG("[");
  for (int x : v)
    LOG("%d ", x);
  LOG("]\n");
}

int ask(const VI& s) {
  int k = s.size();
  if (k <= 1)
    return 0;
  static map<VI, int> mem;
  map<VI, int>::iterator it = mem.find(s);
  if (it != mem.end())
    return it->second;
  printf("? %d\n%d", k, s[0]);
  for (int i = 1; i < k; ++i)
    printf(" %d", s[i]);
  putchar('\n');
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  if (ret == -1)
    exit(0);
  mem.insert(make_pair(s, ret));
  return ret;
}

VI uni(const VI& s, const VI& t) {
  VI u(s);
  u.insert(u.end(), t.begin(), t.end());
  return u;
}

int cross(const VI& s, const VI& t) {
  //errln(t);
  return ask(uni(s, t)) - ask(s) - ask(t);
}

pair<int, int> fc(const VI& s, const VI& t) {
  //errln(t);
  int n = s.size(), m = t.size();
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (cross(VI(s.begin(), s.begin() + mid + 1), t))
      r = mid;
    else
      l = mid + 1;
  }
  int u = s[r];
  l = 0;
  r = m - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (cross({u}, VI(t.begin(), t.begin() + mid + 1)))
      r = mid;
    else
      l = mid + 1;
  }
  return {u, t[r]};
}

const int N = 610;

int prt[N], dep[N];
bool f[N];

void gg(VI s) {
  int u, v;
  while (true) {
    u = s.back();
    s.pop_back();
    if (cross({u}, s)) {
      tie(u, v) = fc({u}, s);
      break;
    }
  }
  VI c1 = {u}, c2 = {v};
  while (u != v) {
    if (dep[u] > dep[v]) {
      u = prt[u];
      c1.push_back(u);
    } else 
      c2.push_back(v = prt[v]);
  }
  int n = c1.size(), m = c2.size();
  printf("N %d\n", n + m - 1);
  for (int i = 0; i < n; ++i)
    printf("%d ", c1[i]);
  for (int i = m - 2; i >= 0; --i)
    printf("%d ", c2[i]);
  putchar('\n');
}

int main() {
  int n;
  scanf("%d", &n);
  VI vis(1, 1), nvis;
  for (int i = 2; i <= n; ++i)
    nvis.push_back(i);
  //errln(nvis);
  for (int rep = 1; rep < n; ++rep) {
    pair<int, int> ed = fc(vis, nvis);
    int u, v;
    tie(u, v) = ed;
//    LOG("%d %d\n", u, v);
    prt[v] = u;
    dep[v] = dep[u] + 1;
    f[v] = !f[u];
    for (VI::iterator it = nvis.begin(); ; ++it)
      if (*it == v) {
        nvis.erase(it);
        break;
      }
    vis.push_back(v);
  }
  VI black, white;
  for (int i = 1; i <= n; ++i)
    if (f[i])
      black.push_back(i);
    else
      white.push_back(i);
  if (ask(black))
    gg(black);
  else if (ask(white))
    gg(white);
  else {
    int k = black.size();
    printf("Y %d\n", k);
    for (int i = 0; i < k; ++i)
      printf("%d ", black[i]);
    putchar('\n');
  }
  return 0;
}