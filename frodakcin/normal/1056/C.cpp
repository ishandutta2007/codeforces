#include <iostream>
#include <cstdio>

#include <algorithm>

#include <cassert>

using namespace std;

const int MAXN = 1e3 + 100;

int N, M;
int p[2*MAXN];
int o[2*MAXN];
int v[MAXN][2];
bool u[MAXN*2];
int d[MAXN * 2], t;
int ct;

int pick(const int& n) {
  assert(u[n]);
  printf("%d\n", n + 1);
  fflush(stdout);
  ct++;
  if(ct == 2*N) exit(0);

  int r;
  scanf("%d", &r);
  u[n] = u[--r] = 0;
  ct++;
  if(ct == 2*N) exit(0);
  return r;
}

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 0;i < 2*N;i++) scanf("%d", p + i), d[i] = i;
  for(int i = 0;i < 2*N;i++) for(int j = 0;j < 2;j++) v[i][j] = -1;
  for(int i = 0;i < 2*N;i++) o[i] = -1;
  for(int i = 0;i < M;i++) scanf("%d%d", v[i], v[i] + 1), v[i][0]--, v[i][1]--, o[v[i][0]] = v[i][1], o[v[i][1]] = v[i][0];
  
  sort(d, d + 2*N, [](const int& a, const int& b) {return p[a] > p[b];});
  
  ct = 0;
  for(int i = 0;i < 2*N;i++) u[i] = true;
  
  scanf("%d", &t);
  if(t == 1) {
    for(int i = 0;i < M;i++) {
      if(p[v[i][0]] < p[v[i][1]]) pick(v[i][1]);
      else pick(v[i][0]);
    }
    for(int i = 0;i < 2*N;i++) {
      if(u[d[i]]) pick(d[i]);
    }
  } else {
    int n;
    scanf("%d", &n);
    ct++;
    u[--n] = 0;
    
    while(o[n] != -1) n = pick(o[n]);
    for(int i = 0;i < M;i++) {
      if(u[v[i][0]]) {
        assert(u[v[i][1]]);
        if(p[v[i][0]] < p[v[i][1]]) pick(v[i][1]);
        else pick(v[i][0]);
      }
    }
    for(int i = 0;i < 2*N;i++) {
      if(u[d[i]]) pick(d[i]);
    }
  }
  
  return 0;
}