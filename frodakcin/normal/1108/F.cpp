#include <iostream>
#include <cstdio>

#include <array>
#include <algorithm>

#include <cassert>

using namespace std;

const int MN = 2e5 + 1000;
const int MM = 2e5 + 1000;

template<int MS = MN> struct DSU {
public:
  int p[MS], r[MN];
  int s;
  void i(int s) {
    for(int j = 0;j <= s;j++) p[j] = j, r[j] = 0;
  }
  int f(int n) {
    if(n == p[n]) return n;
    return p[n] = f(p[n]);
  }
  bool c(int a, int b) {return f(a) == f(b);}
  bool m(int a, int b) {
    a = f(a), b = f(b);
    if(a == b) return false;
    if(r[b] > r[a]) swap(a, b);
    if(r[a] == r[b]) r[a]++;
    r[b] = -1, p[b] = a;
    return true;
  }
};
DSU<> dsu[2];

using i3 = array<int, 3>;
i3 e[MM];

int N, M, f;

int main() {
  scanf("%d%d", &N, &M);
  
  f = 0;
  for(DSU<>& x : dsu) x.i(N);
  
  for(int i = 0;i < M;i++) scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]);
  sort(e, e + M, [](i3 a, i3 b){return a[2]<b[2];});
  
  for(int i = 0, j;i < M;i=j) {
    for(j = i+1;j < M and e[i][2] == e[j][2];j++);
    for(int k = i;k < j;k++)
      if(not dsu[0].m(e[k][0], e[k][1]) and not dsu[1].c(e[k][0], e[k][1])) f++;
    for(int k = i;k < j;k++) dsu[1].m(e[k][0], e[k][1]);
  }
  
  printf("%d\n", f);
  
  return 0;
}