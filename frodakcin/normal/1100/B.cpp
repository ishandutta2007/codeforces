#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e5 + 1000;

int c[MN], t;
bool f[MN];

int N, M;

int main() {
  t = 0;
  for(int i = 0;i < MN;i++) c[i] = 0, f[i] = false;
  
  scanf("%d%d", &N, &M);
  
  for(int i = 0, d;i < M;i++) {
    scanf("%d", &d);
    if(c[d] == 0) t++;
    c[d]++;
    if(t == N) {
      f[i] = true;
      for(int i = 1;i <= N;i++) if(--c[i] == 0) t--;
    }
  }
  
  for(int i = 0;i < M;i++) printf("%d", f[i]);
  printf("\n");
  
  return 0;
}