#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

inline void rph(int& a, const int& b) {if(a < b) a = b;}
int fail() {
  printf("No\n");
  return 0;
}

const int MAXN = 2e5 + 100;

int N;

struct BIT {    //I believe RMQ also works
  int s;
  int v[MAXN];
  void init(int z) {
    s = z;
    for(int i = 0;i <= s;i++) v[i] = 0;
  }
  int qry(int n) {
    int r = 0;
    for(n++;n > 0;n -= (-n)&n) r += v[n];
    return r;
  }
  int qry(int l, int r) {
    return qry(r) - qry(l);
  }
  void upd(int n, int q) {
    for(n++;n < s;n += (-n)&n) v[n] += q;
  }
} T;

int a[MAXN], o[MAXN], x;

int main() {
  scanf("%d", &N);
  
  x = 0;
  for(int i = 0;i < N;i++) scanf("%d", a + i), rph(x, a[i]), o[i] = i;
  
  T.init(N);
  sort(o, o + N, [](const int& y, const int& z) {return a[y] < a[z] or (not(a[z] < a[y]) and y < z);});
  
  for(int i = 0, j;i < N;i=j) {
    if(a[o[i]] == x) break;
    for(j = i + 1;j < N and a[o[i]] == a[o[j]];j++);
    if((j - i)&1) return fail();
    for(int k = i;k < j;k += 2)
      if(T.qry(o[k], o[k + 1] - 1) == o[k + 1] - o[k] - 1) T.upd(o[k], 1), T.upd(o[k + 1], 1); else return fail();
  }
  
  printf("Yes\n");
  
  return 0;
}