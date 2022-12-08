#include <iostream>
#include <cstdio>

#include <array>
#include <algorithm>

using namespace std;

using i2 = array<int, 2>;
bool operator < (const i2& a, const i2& b) {return a[0] < b[0] or (not(b[0] < a[0]) and a[1] < b[1]);}
bool operator > (const i2& a, const i2& b) {return a[0] > b[0] or (not(b[0] > a[0]) and a[1] > b[1]);}

template<class T> void rpl(T& a, const T& b) {if(b < a) a = b;}
template<class T> void rph(T& a, const T& b) {if(a < b) a = b;}

const int MN = 1e5 + 100;
const int MM = 300 + 10;
const int INF = 1e9;

int N, M;
int a[MN];

int v[MM<<1], c[MM<<1];
i2 m[MM];
int x[MM<<1], X;
i2 F;

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 0;i < N;i++) scanf("%d", a + i);
  for(int i = 0, u, v;i < M;i++) scanf("%d%d", &m[i][0], &m[i][1]), x[i<<1]=--m[i][0], x[i<<1|1]=m[i][1];
  
  x[M<<1] = 0, x[M<<1|1] = N;
  sort(x, x + (M<<1) + 2);
  X = unique(x, x + (M<<1) + 2) - x;
  for(int i = 0;i < M;i++) for(int j : {0, 1}) m[i][j] = lower_bound(x, x + X, m[i][j]) - x;
  X--;
  
  for(int i = 0, j = 0;i < N;i++) {
    if(j < X and i == x[j]) v[j++] = INF;
    rpl(v[j-1], a[i]);
  }
  
  F = {-INF, -1};
  for(int i = 0;i < N;i++) {
    for(int j = 0;j <= X;j++) c[j] = 0;
    for(int j = 0;j < M;j++) if(x[m[j][1]] <= i or i < x[m[j][0]]) c[m[j][0]]--, c[m[j][1]]++;
    int f = INF;
    for(int j = 0, p = 0;j < X;j++) rpl(f, v[j] + (p += c[j]));
    rph(F, {a[i] - f, i});
  }
  
  printf("%d\n", F[0]);
  int z[MN];
  z[0] = 0;
  for(int i = 0;i < M;i++) if(x[m[i][1]] <= F[1] or F[1] < x[m[i][0]]) z[++z[0]] = i;
  
  printf("%d\n", z[0]);
  for(int i = 1;i <= z[0];i++) printf("%d ", z[i] + 1);
  printf("\n");
  
  return 0;
}