#include <iostream>
#include <cstdio>

using namespace std;

template<class T> void mx(T& a, const T& b) {if(a < b) a = b;}
template<class T> void mn(T& a, const T& b) {if(b < a) a = b;}

const int MN = 1e5 + 100;
const int MV = 1e5 + 100;
const int MB = 255;
const int ML = 400;

template<int MS = MV> struct DSU {
public:
  int M;
  int p[MS], c[MS], r[MS], v[MS];
  void i(int * s, int * e) {
    M = 0;
    for(int * t = s;t != e;t++) mx(M, *t);
    for(int j = 0;j <= M;j++) p[j] = j, v[j] = j, c[j] = 0, r[j] = 0;
    for(int * t = s;t != e;t++) c[*t]++;
  }
  int f(int n) {
    if(n == p[n]) return n;
    return p[n] = f(p[n]);
  }
  bool m(int a, int b) {
    a = f(a), b = f(b);
    if(a == b) return false;
    if(r[a] < r[b]) swap(a, b); else swap(v[a], v[b]);
    if(r[a] == r[b]) r[a]++;
    p[b] = a, c[v[a]] += c[v[b]], c[v[b]] = 0, r[b] = -1;
    return true;
  }
};
struct DAT {
public:
  DSU<> v;
  int d, S;
  int * s, * e;
  void res() {
    d = 0;
    v.i(s, e);
  }
  void init(int * l, int * r) {s = l, e = r, S = e - s; res();}
  void upd(int x) {
    if(x >= v.M - d) return;
    if(x<<1 > v.M - d) {
      for(int i = d + x + 1;i <= v.M;i++) v.m(i, i - x);
      v.M = d + x;
    } else {
      for(int i = d + 1;i <= d + x;i++) v.m(i, i + x);
      d += x;
    }
  }
  void upd(int l, int r, int x) {
    if(not(l < r)) return;
    if(l == 0 and r == S) return upd(x);
    for(int * t = s + l, i = l, j;i < r;i++, t++) {
      if((j=v.v[v.f(*t)]) - d > x) {
        v.c[j]--;
        *t = j-x;
        v.c[v.v[v.f(*t)]]++;
      }
    }
  }
  int operator [] (const int& x) {if(d + x > v.M) return 0; else return v.c[d + x];}
  int qry(int l, int r, int x) {
    if(l == 0 and r == S) if(d + x > v.M) return 0; else return v.c[d + x];
    int f = 0;
    for(int * t = s + l, i = l;i < r;t++, i++) f += v.v[v.f(*t)] - d == x;
    return f;
  }
};

DAT v[MB];
int N, a[MN], M, b[MN], m[MN];

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 0;i < N;i++) scanf("%d", a + i);
  
  for(int i = 0, j = 0;i < N;i+=ML, j++) {
    if(i+ML>N) {
      v[j].init(a + i, a + N);
      break;
    } else {
      v[j].init(a + i, a + i + ML);
    }
  }
  for(int i = 0, j = 0, k = 0;i < N;i++, k++) {
    if(k == ML) j++, k = 0;
    b[i] = j;
    m[i] = k;
  }
  
  for(int i = 0, o, l, r, x;i < M;i++) {
    scanf("%d%d%d%d", &o, &l, &r, &x), --l, --r;
    if(o == 1) {
      if(b[l] == b[r]) v[b[l]].upd(m[l], 1+(m[r]), x);
      else {
        v[b[l]].upd(m[l], ML, x);
        v[b[r]].upd(0, 1+(m[r]), x);
        for(int j = b[l] + 1;j < b[r];j++) v[j].upd(x);
      }
    } else {
      if(b[l] == b[r]) printf("%d\n", v[b[l]].qry(m[l], 1+(m[r]), x));
      else {
        int f = 0;
        f += v[b[l]].qry(m[l], ML, x);
        f += v[b[r]].qry(0, 1+(m[r]), x);
        for(int j = b[l] + 1;j < b[r];j++) f += v[j][x];
        printf("%d\n", f);
      }
    }
  }
  
  return 0;
}