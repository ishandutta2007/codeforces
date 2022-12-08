#include <iostream>
#include <cstdio>

#include <algorithm>
#include <functional>

using namespace std;

void fail() {
  printf("-1\n");
  exit(0);
}

typedef long long ll;
#define tll(X) static_cast<ll>(X)

const int MAXN = 5e5 + 100;

int N;

int w[MAXN];
ll p[MAXN];
int theorem(int * a) {
  p[0] = 0LL;
  for(int i = 0;i <= N;i++) w[i] = N + 1;
  for(int i = 0, j = N;i <= N;i++) {
    p[i + 1] = p[i] + a[i];
    for(;j >= a[i];j--) w[j] = i;
  }
  
  //for(int i = 0;i <= N;i++) cerr << a[i] << " "; cerr << "\n";
  //for(int i = 0;i <= N + 1;i++) cerr << p[i] << " "; cerr << "\n";
  //for(int i = 0;i <= N;i++) cerr << w[i] << " "; cerr << "\n";
  
  for(int i = 0, d;i <= N;i++) {
    d = max(w[i + 1], i + 1);
    if(p[i + 1] > tll(i + 1)*i + p[N + 1] - p[d] + tll(i + 1) * (d - i - 1)) return i;
  }
  
  return -1;
}

int a[MAXN], b[MAXN];

ll s;

int bs1() {
  int l = -1, h = (N>>1);
  while(h > l + 1) {
    int m = l + ((h - l)>>1);
    int q = m<<1|s&1;
    
    int z = -1;
    for(int i = 0, j = 1;i <= N;i++) {
      if(z == -1 and (j > N or not(a[j] > q))) {
        z = i;
        b[i] = q;
      } else b[i] = a[j++];
    }
    
    int r = theorem(b);
    
    if(r == -1 or r >= z) h = m;
    else l = m;
  }
  return h<<1|s&1;
}
int bs2() {
  int l = 0, h = 1 + (N>>1);
  while(h > l + 1) {
    int m = l + ((h - l)>>1);
    int q = m<<1|s&1;
    
    int z = -1;
    for(int i = 0, j = 1;i <= N;i++) {
      if(z == -1 and (j > N or not(a[j] > q))) {
        z = i;
        b[i] = q;
      } else b[i] = a[j++];
    }
    
    int r = theorem(b);
    
    if(r == -1 or r < z) l = m;
    else h = m;
  }
  return l<<1|s&1;
}

int main() {
  scanf("%d", &N);
  
  s = 0LL;
  for(int i = 1;i <= N;i++) scanf("%d", a + i), s += a[i];
  
  sort(a + 1, a + N + 1, greater<int>());
  
  int L = bs1();
  int R = bs2();
  if(R < L) fail();
  for(int i = L;i <= R;i+=2) printf("%d ", i);
  printf("\n");
  
  return 0;
}