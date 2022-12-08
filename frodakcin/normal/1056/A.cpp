#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 120;

int N;
bool c[MAXN];
bool a[MAXN];

int main() {
  scanf("%d", &N);
  for(int i = 0;i < MAXN;i++) c[i] = 1;
  while(N--) {
    int r;
    scanf("%d", &r);
    for(int i = 0;i <= 100;i++) a[i] = false;
    for(int i = 0, v;i < r;i++) scanf("%d", &v), a[v] = true;
    for(int i = 1;i <= 100;i++) if(!a[i]) c[i] = false;
  }
  
  for(int i = 1;i <= 100;i++) if(c[i]) printf("%d ", i);
  printf("\n");
  
  return 0;
}