#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e5 + 100;
const int MV = 1e5 + 100;
const int M = 998244353;

typedef long long ll;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
#define cs const
int sm(cs int& i, cs int& j) {return ti((tl(i)+j)%M);}
int df(cs int& i, cs int& j) {return ti((tl(i)-j+M)%M);}
int pd(cs int& i, cs int& j) {return ti((tl(i)*j)%M);}

int K;
template<int L> struct BLK {
public:
  int v[L], w[L], d[MV<<1];
  int * k;
  int f, c, g;
  BLK() {
    for(int i = 0;i < MV<<1;i++) d[i] = 0;
    k = d + MV;
    c = f = 0;
  }
  int upd(int d) {
    int of = f;
    if(d == 1)
      f = df(f, k[g--]);
    if(d == -1)
      f = sm(f, k[++g]);
    return df(f, of);
  }
  int upd(int l, int r, int d) {
    if(l == 0&&r == L) return upd(d);
    if(l == r) return 0;
    int of = f;
    if(d == 1)
      for(int i = l;i < r;i++) {
        if(w[i] == g) f = df(f, v[i]);
        k[w[i]] = df(k[w[i]], v[i]);
        w[i]++;
        k[w[i]] = sm(k[w[i]], v[i]);
      }
    if(d == -1)
      for(int i = l;i < r;i++) {
        if(w[i] == g + 1) f = sm(f, v[i]);
        k[w[i]] = df(k[w[i]], v[i]);
        w[i]--;
        k[w[i]] = sm(k[w[i]], v[i]);
      }
    return df(f, of);
  }
  int ins(int l, int x, int y) {
    y += g - K;
    v[l] = x, w[l] = y;
    k[y] = sm(k[y], x);
    if(y <= g) return f = sm(f, x), x;
    return 0;
  }
};
template<int B, int L> struct SQR {
public:
  BLK<L> v[B];
  int b[B*L], w[B*L], f;
  SQR() {
    for(int i = 0, k = 0;i < B;i++)
      for(int j = 0;j < L;j++, k++)
        b[k] = i, w[k] = j;
    f = 0;
  }
  void initk() {
    for(int i = 0;i < B;i++) v[i].g = K;
  }
  void upd(int l, int r, int d) {
    if(l == r) return;
    if(b[l] == b[r-1]) {
      f = sm(f, v[b[l]].upd(w[l], w[r-1]+1, d));
      return;
    }
    f = sm(f, v[b[l]].upd(w[l], L, d));
    f = sm(f, v[b[r-1]].upd(0, w[r-1]+1, d));
    for(int i = b[l]+1;i < b[r-1];i++)
      f = sm(f, v[i].upd(d));
  }
  void ins(int l, int x, int y) {
    f = sm(f, v[b[l]].ins(w[l], x, y));
  }
};

int N, a[MN], b[MN], p[MV], q;

SQR<200, 505> DS;

int main() {
  scanf("%d%d", &N, &K);
  DS.initk();
  for(int i = 1;i <= N;i++) p[i] = -1;
  for(int i = 0;i < N;i++) {
    scanf("%d", a + i);
    b[i] = p[a[i]];
    p[a[i]] = i;
  }
  DS.ins(0, 1, 0);
  for(int i = 0;i < N;i++) {
    if(b[i] != -1) {
      DS.upd(b[i]+1, i+1, 1);
      if(b[b[i]] != -1)
        DS.upd(b[b[i]]+1, b[i]+1, -1);
      else
        DS.upd(0, b[i]+1, -1);
    } else
      DS.upd(0, i+1, 1);
    if(i < N-1) DS.ins(i+1, DS.f, 0);
  }
  printf("%d\n", DS.f);
  
  return 0;
}