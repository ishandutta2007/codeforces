#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 500;

int N, K;

int a[MN];

void rph(int& s, const int& t) {if(s < t) s = t;}

int main() {
  scanf("%d%d", &N, &K);
  
  int E, S;
  E = S = 0;
  
  for(int i = 0;i < N;i++) scanf("%d", a + i), (a[i] == -1 ? E : S)++;
  
  int f = 0;
  for(int b = 0;b < K;b++) {
    int e = 0, s = 0;
    for(int j = b;j < N;j += K)
    if(a[j] == -1) e++; else s++;
    e = E - e, s = S - s;
    rph(f, abs(e - s));
  }
  
  printf("%d\n", f);
  
  return 0;
}