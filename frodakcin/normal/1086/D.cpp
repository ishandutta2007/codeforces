#include <iostream>
#include <cstdio>

#include <set>

using namespace std;

//R = 0, P = 1, S = 2 <-- x > x - 1, 0 > 2

const int L[3] = {1, 2, 0};
const int W[3] = {2, 0, 1};

int g(char c) {
  if(c == 'R') return 0;
  if(c == 'P') return 1;
  if(c == 'S') return 2;
  return -1;
}

const int MAXN = 2e5 + 1000;
int N, Q;

typedef set<int> si;
typedef si::iterator sit;
si p[3];
struct BIT {
  int c[MAXN];
  int s;
  void init(const int& z) {
    s = z;
    for(int i = 0;i <= s;i++) c[i] = 0;
  }
  void upd(int x, int q) {
    for(;x <= s;x += (-x)&x) c[x] += q;
  }
  int qry(int x) {
    int r = 0;
    for(;x > 0;x -= (-x)&x) r += c[x];
    return r;
  }
  int qry(int l, int r) {
    if(l >= r) return 0;
    return qry(r) - qry(l - 1);
  }
} c[3];
int r[MAXN], a[3];

void ans() {
  int q = N;
  
  for(int i = 0, x, y;i < 3;i++) {
    int f = 0;
    
    if(p[L[i]].empty()) continue;
    if(p[W[i]].empty()) {q -= a[i]; continue;}
    sit it;
    
    f += c[i].qry(*p[L[i]].begin(), *p[W[i]].begin());
    f += c[i].qry(*prev(p[W[i]].end()), *prev(p[L[i]].end()));
    
    if(a[i] < f) f = a[i];
    q -= f;
  }
  
  printf("%d\n", q);
}

int main() {
  scanf("%d%d", &N, &Q);
  
  for(int i = 0;i < 3;i++) c[i].init(N + 10), a[i] = 0;
  
  char t;
  for(int i = 1, z;i <= N;i++) {
    scanf(" %c", &t);
    z = g(t);
    c[z].upd(i, 1);
    p[z].insert(i);
    r[i] = z;
    
    a[z]++;
  }
  
  ans();
  
  for(int i = 0, l, z;i < Q;i++) {
    scanf("%d %c", &l, &t);
    z = g(t);
    
    c[r[l]].upd(l, -1);
    p[r[l]].erase(l);
    a[r[l]]--;
    
    c[r[l] = z].upd(l, 1);
    p[r[l]].insert(l);
    a[r[l]]++;
    
    ans();
  }
  
  return 0;
}