#include <iostream>
#include <cstdio>

#include <array>
#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

int fail() {
  printf("-1\n");
  return 0;
}

const int MN = 2e5 + 100;
const int MS = MN;

int N, S, a[MN], v[MN], g[MN], V, f;
using i2 = array<int, 2>;
i2 b[MN];
using vi2 = vector<i2>;
#define pb push_back
vi2 w[MN];
bool u[MN];
using vi = vector<int>;

vi c[MN];
int C;

void dfs(int n, int p = -1) {
  u[n] = true;
  for(;not w[n].empty();) {
    i2 x = w[n].back();
    w[n].pop_back();
    dfs(x[1], x[0]);
  }
  if(p != -1) c[C].pb(p);
}
void solve(int n) {
  c[C].clear();
  dfs(n);
  assert(not c[C].empty());
  C++;
}

void cmb(vi * s, vi * e) {
  int z = 0;
  for(vi * t = s;t != e;t++) z += t->size();
  printf("%d\n", z);
  for(vi * t = s;t != e;t++) for(int i = t->size() - 1;i >= 0;i--) printf("%d ", t->at(i) + 1);
  printf("\n%ld\n", e - s);
  for(vi * t = e;;) {
    if(t == s) break;
    t--;
    printf("%d ", t->back() + 1);
  }
  printf("\n");
}

int main() {
  scanf("%d%d", &N, &S);
  
  for(int i = 0;i < N;i++) scanf("%d", a + i), v[i] = a[i];
  sort(v, v + N);
  
  V = -1;
  for(int i = 0;i < N;i++) {
    if(not i or v[i] != v[i-1]) b[++V][0] = i;
    v[V] = v[i], g[i] = V;
    b[V][1] = i+1;
  }
  V++;
  
  f = 0;
  for(int i = 0;i < N;i++) f += i < b[a[i] = lower_bound(v, v + V, a[i]) - v][0] or b[a[i]][1] <= i;
  if(f > S) return fail();
  for(int i = 0;i < N;i++) if(a[i] != g[i]) w[g[i]].pb({i, a[i]});
  
  for(int i = 0;i < V;i++) u[i] = false;
  C = 0;
  for(int i = 0;i < V;i++) if(not u[i] and not w[i].empty()) solve(i);
  
  int x = min(S - f, C);
  if(x < 2) x = 0;
  printf("%d\n", C + (x ? 2-x : 0));
  if(x) cmb(c, c + x);
  for(int i = x;i < C;i++) {
    printf("%lu\n", c[i].size());
    for(int j = c[i].size() - 1;j >= 0;j--) printf("%d ", c[i][j] + 1);
    printf("\n");
  }
  
  return 0;
}