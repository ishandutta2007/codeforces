#include <iostream>
#include <cstdio>

#include <algorithm>
#include <functional>

#include <cassert>

using namespace std;

const int MAXN = 3e5 + 100;

char a[MAXN], b[MAXN];
int as, bs, ae, be;
char f[MAXN];
int l, r;

int N;

int main() {
  scanf(" %s %s", a, b);
  for(N = 0;a[N] != '\0';N++);
  
  sort(a, a + N);
  sort(b, b + N, greater<char>());
  
  as = bs = 0;
  ae = (N + 1)>>1;
  be = N>>1;
  
  l = 0, r = N;
  for(int i = 2;i <= N;i+=2) {
    if(a[as] < b[bs]) f[l++] = a[as++];
    else f[--r] = a[--ae];
    
    if(ae == as or a[as] < b[bs]) f[l++] = b[bs++];
    else f[--r] = b[--be];
  }
  if(N&1)
    f[l++] = a[as++];
  assert(l == r);
  
  printf("%s\n", f);
  
  return 0;
}