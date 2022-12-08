#include <iostream>
#include <cstdio>

#include <array>
#include <algorithm>

using namespace std;

const int MN = 23;

int N, P;

bool rp(int& a, int b) {return a == -1 or b < a ? a = b, true : false;}

using i4 = array<int, 4>;   //s, l, t, i
i4 a[MN];
int d[1<<MN], o[MN], b[1<<MN];
using i2 = array<int, 2>;
i2 f[MN];
bool F;

void dodp() {
  d[0] = 1;
  for(int i = 0, k, l, m;i < (1<<N);i++) {
    //cerr << i << " " << d[i] << "\n";
    if(d[i] == -1) continue;
    for(k = 0;k < N and a[k][0] <= d[i];k++);
    if(k == N) continue;
    m = max(d[i], k ? a[k-1][0] + a[k-1][1] : -1), l = a[k][0] - m - 1;
    for(int j = 0;j < N;j++) {
      if(i&1<<o[j]) continue;
      for(;k <= o[j] and l < a[o[j]][2];k++) if(i&1<<k or m == a[k][0]) m = a[k][0]+a[k][1], l = a[k+1][0]-m-1; else l += a[k+1][0]-a[k][0];
      if(k > o[j]) continue;
      if(rp(d[i|1<<o[j]], a[o[j]][2] + m)) b[i|1<<o[j]] = o[j];
    }
  }
}
void fin(int p, int m) {
  for(;m;) {
    f[a[b[m]][3]] = {p, d[m]-a[b[m]][2]};
    m^=1<<b[m];
  }
}
int solve1() {
  if(d[(1<<N)-1] == -1) return F = false, 0;
  fin(1, (1<<N)-1);
  return F = true, 0;
}
int solve2() {
  for(int i = 0, q = (1<<N)-1;i < 1<<N;i++) if(d[i] != -1 and d[i^q] != -1) return F = true, fin(1, i), fin(2, i^q), 0;
  return F = false, 0;
}

int main() {
  scanf("%d%d", &N, &P);
  for(int i = 0;i < N;i++) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]), a[i][3] = i;
  sort(a, a + N, [](i4 x, i4 y){return x[0] < y[0];});
  for(int i = 0;i < N;i++) o[i] = i;
  sort(o, o + N, [](int x, int y){return a[x][2] < a[y][2];});
  
  for(int i = 0;i < 1<<N;i++) d[i] = -1;
  
  a[N] = {-1, -1, -1, -1};
  dodp();
  F = true;
  if(P == 1) solve1();
  if(P == 2) solve2();
  
  if(F) {
    printf("YES\n");
    for(int i = 0;i < N;i++) printf("%d %d\n", f[i][0], f[i][1]);
  } else printf("NO\n");
  
  return 0;
}