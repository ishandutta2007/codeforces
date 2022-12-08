#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 1000;

int N;
bool v[MAXN];
char I;

int p[MAXN];
int m[2][MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 1;i <= N;i++) scanf(" %c", &I), v[i] = I == '(';
  
  if(N&1) {
    printf("0\n");
    return 0;
  }
  
  p[0] = 0;
  for(int i = 1;i <= N;i++) p[i] = p[i - 1] + (v[i] ? 1 : -1);
  m[0][0] = 0;
  for(int i = 1;i <= N;i++) m[0][i] = min(m[0][i - 1], p[i]);
  m[1][N] = p[N];
  for(int i = N - 1;i >= 1;i--) m[1][i] = min(m[1][i + 1], p[i]);
  
  int f = 0;
  for(int i = 1;i <= N;i++) {
    if(v[i]) f += (p[N] == 2 and m[0][i-1] >= 0 and p[i] >= 2 and m[1][i] >= 2);
    else f += (p[N] == -2 and m[0][i-1] >= 0 and p[i] >= -2 and m[1][i] >= -2);
  }
  
  printf("%d\n", f);
  
  return 0;
}