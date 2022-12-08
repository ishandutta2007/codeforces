#include <iostream>
#include <cstdio>

#include <bitset>

using namespace std;

const int MAXN = 2e5 + 100;

int N;

int fail() {
  printf("No\n");
  return 0;
}

int p[2];
bool f[2];

int main() {
  scanf("%d", &N);
  
  p[0] = p[1] = 0;
  f[0] = f[1] = false;
  for(int i = 0, w;i < N;i++) {
    scanf("%d", &w);
    if(not(w&1)) continue;
    p[i&1]++;
    if(not(i&1) and not((N-i-1)&1)) f[i&1] = true;
  }
  
  if(p[0] < p[1] and p[1] - p[0] > f[1]) return fail();
  if(p[1] < p[0] and p[0] - p[1] > f[0]) return fail();
  
  printf("Yes\n");
  
  return 0;
}