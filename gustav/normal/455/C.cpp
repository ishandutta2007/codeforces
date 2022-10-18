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

#define MAXN 300005

int N, M, Q;
int type, a, b;

int uf[MAXN];
int len[MAXN];

int find(int n) { return n == uf[n] ? n : uf[n] = find(uf[n]); }

void link(int a, int b) {
  int fa = find(a);
  int fb = find(b);

  if (fa == fb) return;

  if (len[fa] < len[fb])
    swap(fa, fb);

  len[fa] = max(len[fa] / 2 + len[fa] % 2 + 1 + len[fb] / 2 + len[fb] % 2,
            len[fa]);

  uf[fb] = fa;
}


vector< int > T[MAXN];
int bio[MAXN];
int dad[MAXN];
int d[MAXN];
vector< int > visited;

queue< int > q;

int bfs(int n) {
  visited.clear();
  q.push(n);
  d[n] = 1;

  while (!q.empty()) {
    int c = q.front(); q.pop();
    visited.pb(c);
    for (auto m : T[c]) {
      if (d[m]) continue;
      d[m] = d[c] + 1;
      dad[m] = c;
      q.push(m);
    }
  }

  int best = n;
  for (auto v : visited)
    if (d[v] > d[best])
      best = v;

  for (auto v : visited) 
    d[v] = 0, bio[v] = 1;

  return best;
}

vector< int > path;

void get_center(int n) {
  int a = bfs(n);
  int b = bfs(a);

  path.clear();

  path.pb(b);
  while (b != a) {
    b = dad[b];
    path.pb(b);
  }

  int center = path[path.size() / 2];

  for (auto v : visited) 
    uf[v] = center;

  len[center] = path.size() - 1;
}

int main(void)
{
  scanf("%d%d%d", &N, &M, &Q); 

  for (int i = 1; i <= N; ++i)
    uf[i] = i;

  for (int i = 0; i < M; ++i) {
    scanf("%d%d", &a, &b);
    T[a].pb(b);
    T[b].pb(a);
  }

  for (int i = 1; i <= N; ++i) {
    if (bio[i]) continue;
    get_center(i);
  }

  for (int i = 0; i < Q; ++i) {
    scanf("%d", &type);

    if (type == 1) {
      scanf("%d", &a);
      printf("%d\n", len[find(a)]);
    } else {
      scanf("%d%d", &a, &b);
      link(a, b);
    }
  }

  return 0;
}