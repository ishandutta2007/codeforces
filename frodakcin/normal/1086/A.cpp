#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3;

int x[N], y[N];

int m[2];

int f[2][10000], R;

void out(int x, int y) {
  f[0][R] = x, f[1][R] = y;
  R++;
}
void draw(int x1, int y1, int x2, int y2) {
  if(x1 < x2) for(int i = x1 + 1;i < x2;i++) out(i, y1);
  if(x1 > x2) for(int i = x2 + 1;i < x1;i++) out(i, y1);
  
  if(x1 != x2 and y1 != y2) out(x2, y1);
  
  if(y1 < y2) for(int i = y1 + 1;i < y2;i++) out(x2, i);
  if(y1 > y2) for(int i = y2 + 1;i < y1;i++) out(x2, i);
}

int main() {
  for(int i = 0;i < N;i++) scanf("%d%d", x + i, y + i);
  out(x[0], y[0]);
  out(x[1], y[1]);
  out(x[2], y[2]);
  
  bool O = false;
  
  m[0] = x[2];
  int L = min(x[0], x[1]);
  if(x[2] < L) m[0] = L, O = 1;
  int H = max(x[0], x[1]);
  if(x[2] > H) m[0] = H, O = 1;
  
  m[1] = y[2];
  L = min(y[0], y[1]);
  if(y[2] < L) m[1] = L, O = 1;
  H = max(y[0], y[1]);
  if(y[2] > H) m[1] = H, O = 1;
  
  if(O) {
    draw(x[0], y[0], m[0], m[1]);
    draw(x[1], y[1], m[0], m[1]);
    draw(m[0], m[1], x[2], y[2]);
    if((m[0] != x[0] or m[1] != y[0]) and (m[0] != x[1] or m[1] != y[1]) and (m[0] != x[2] or m[1] != y[2])) out(m[0], m[1]);
  } else {
    draw(x[0], y[0], x[2], y[2]);
    draw(x[2], y[2], x[1], y[1]);
  }
  
  printf("%d\n", R);
  for(int i = 0;i < R;i++) printf("%d %d\n", f[0][i], f[1][i]);
  
  return 0;
}