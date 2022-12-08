#include <iostream>
#include <cstdio>

#include <vector>
#include <bitset>
#include <array>
#include <queue>
#include <algorithm>

#include <cassert>

using namespace std;

const int MAXN = 1e3 + 100;

int N, M;

typedef bitset<MAXN> vb;
vb v;
typedef vector<int> vi;
#define pb push_back
vi a[MAXN];

typedef array<int, 2> ar2;
#define nd at(0)
#define di at(1)
;
typedef queue<int> qi;

int p[MAXN], d[MAXN];

qi x;
ar2 far(int n) {
  while(not x.empty()) x.pop();
  x.push(n);
  int r;
  p[n] = -1, d[n] = 0;
  while(not x.empty()) {
    r = x.front(); x.pop();
    v[r] = true;
    for(int u : a[r]) {
      if(p[r] == u) continue;
      p[u] = r, d[u] = d[r] + 1;
      x.push(u);
    }
  }
  return {r, d[r]};
}
ar2 center(int n) {
  ar2 s = far(far(n).nd);
  int r = s.nd;
  for(int i = 0;i<<1 < s.di;i++, r = p[r]);
  return {r, s.di};
}

typedef vector<ar2> va2;
va2 T;

int max(int a, int b, int c) {
  if(a < b) a = b;
  if(a < c) a = c;
  return a;
}

int main() {
  scanf("%d%d", &N, &M);
  
  for(int i = 0, u, w;i < M;i++) {
    scanf("%d%d", &u, &w);
    a[u].pb(w);
    a[w].pb(u);
  }
  
  if(M + 1 == N) {
    printf("%d\n", far(far(1).nd).di);
    return 0;
  }
  
  for(int i = 1;i <= N;i++) v[i] = false;
  for(int i = 1;i <= N;i++) if(not v[i]) T.pb(center(i));
  assert(T.size() > 1);
  
  sort(T.begin(), T.end(), [](const ar2& z, const ar2& y){return z.di > y.di;});
  
  if(T.size() == 2) {
    printf("%d\n%d %d\n", max(T[0].di, ((1 + T[0].di)>>1) + 1 + ((1 + T[1].di)>>1)), T[0].nd, T[1].nd);
  } else {
    printf("%d\n", max(T[0].di, ((1 + T[0].di)>>1) + 1 + ((1 + T[1].di)>>1), ((1 + T[1].di)>>1) + 2 + ((1 + T[2].di)>>1)));
    for(int i = 1;i < T.size();i++) printf("%d %d\n", T[0].nd, T[i].nd);
  }
  
  return 0;
}