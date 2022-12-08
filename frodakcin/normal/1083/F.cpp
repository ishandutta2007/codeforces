#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

const int MAXN = 2e5 + 100;

const int BITS = 14;
const int MAXV = (1 << BITS) - 1;

const int DSZ = 500;

#define ti(X) static_cast<int>(X)
const inline int ci(const int& x) {return ti(x)-97;}

int N, K, Q;
int a[2][MAXN], b[MAXN], r[MAXN];

int ans, z;

void edge() {
  ans = 0;
  for(int i = 0;i < N;i++) scanf("%d", a[0] + i);
  for(int i = 0;i < N;i++) scanf("%d", a[1] + i), ans += (a[0][i] xor a[1][i]) != 0;
  printf("%d\n", ans);
  char t;
  for(int i = 0, l, p, v;i < Q;i++) {
    scanf(" %c%d%d", &t, &p, &v);
    p--;
    l = t == 'b';
    if(not(a[0][p] xor a[1][p])) ans++;
    if(not(a[not l][p] xor (a[l][p] = v))) ans--;
    printf("%d\n", ans);
  }
}

int B;

struct DAT {
public:
  int c[MAXV + 1], m;
  int v[DSZ];
  DAT() {
    for(int i = 0;i <= MAXV;i++) c[i] = 0;
    for(int i = 0;i < DSZ;i++) v[i] = -1;
    m = 0;
  }
  int upd(int x) {
    m^=x;
    return c[m] - c[m xor x];
  }
  int upd(int l, int r, int x) {
    int z = c[m];
    for(int i = l;i < r;i++)
      if(v[i] != -1) c[v[i]]--, c[v[i] ^= x]++;
    return c[m] - z;
  }
  int add(int p, int x) {
    c[v[p] = x xor m]++;
    return x == m;
  }
};
typedef vector<DAT> vd;
struct RQ {
public:
  vd v;
  int s;
  RQ(const int& s = 0) : s(s) {
    v.clear();
    for(int i = 0;i < s;i += DSZ) v.push_back(DAT());
  }
  void upd(int l, int r, int q) {
    int j = l/DSZ, k = (r - 1)/DSZ;
    if(j == k) {ans += v[j].upd(l%DSZ, 1 + (r-1)%DSZ, q); return;}
    ans += v[j].upd(l%DSZ, DSZ, q);
    ans += v[k].upd(0, 1 + (r-1)%DSZ, q);
    for(int i = j + 1;i < k;i++)
      ans += v[i].upd(q);
  }
  void add(int p, int x) {
    ans += v[p/DSZ].add(p%DSZ, x);
  }
};
typedef vector<RQ> vrq;

vrq rq;

void R() {
  if(z < K - 1) printf("-1\n");
  else printf("%d\n", N - ans);
}
char s;
int p, v, x;
bool f;
void Z(int l) {
  l = N - (N-l-1)%K - 1;
  if(not(l + K > N)) return;
  if(not b[l]) z--;
  if(not(b[l] ^= x)) z++;
}
void QR() {
  scanf(" %c%d%d", &s, &p, &v);
  f = s == 'b', p--;
  
  //x = a[f][p] xor (a[f][p] = v);
  x = a[f][p] xor v;
  a[f][p] = v;
  
  Z(p);
  if(p + 1 < N) Z(p + 1);
  
  rq[p%K].upd(p/K, B, x);
  if(p + 1 < N) rq[(p+1)%K].upd((p+1)/K, B, x);
}

//case 2

int q2, z2, d2;
char s2;
bool f2;
int p2, v2, x2;

void r2() {
  if(z2 < K - 1) printf("-1\n");
  else printf("%d\n", N - q2);
}
void fd2() {
  d2 = 0;
  if(not b[p2]) d2--;
  if(not(b[p2] = b[p2] xor x2)) d2++;
  q2 += d2;
  if(p2 + K > N) z2 += d2;
}
void fq2() {
  scanf(" %c%d%d", &s2, &p2, &v2);
  f2 = s2 == 'b';
  p2--;
  x2 = a[f2][p2] xor v2;
  a[f2][p2] = v2;
  for(int i = 0;p2 < N;i = not i) {
    fd2();
    if(i) p2 += K - 1; else p2++;
  }
}
void solve2() {
  q2 = z2 = 0;
  for(int i = 0;i < N;i++) scanf("%d", a[0] + i), r[i] = 0;
  for(int i = 0;i < N;i++) scanf("%d", a[1] + i), b[i] = a[0][i] xor a[1][i];
  
  for(int i = 0;i < N;i++) {
    if(i) r[i] ^= r[i-1];
    b[i] ^= r[i];
    if(i + K < N) r[i + K] ^= b[i];
    r[i] ^= b[i];
    
    if(b[i] == 0) {
      q2++;
      if(i + K > N) z2++;
    }
  }
  
  r2();
  for(int i = 0;i < Q;i++) fq2(), r2();
}

//end of case 2

int main() {
  scanf("%d%d%d", &N, &K, &Q);
  
  if(K == 1) {edge(); return 0;}
  if(K > DSZ) {solve2(); return 0;}
  
  for(int i = 0;i < N;i++) scanf("%d", a[0] + i), r[i] = 0;
  for(int i = 0;i < N;i++) scanf("%d", a[1] + i), b[i] = a[0][i] xor a[1][i];
  
  B = (N + K - 1)/K;
  ans = z = 0;
  
  rq.clear();
  for(int i = 0;i < K;i++) rq.push_back(RQ(B));
  
  for(int i = 0;i < N;i++) {
    if(i) r[i] ^= r[i-1];
    b[i] ^= r[i];
    if(i + K < N) r[i + K] ^= b[i];
    r[i] ^= b[i];
    
    if(not(b[i]) and i + K > N) z++;
    rq[i%K].add(i/K, b[i]);
  }
  
  R();
  
  for(int i = 0;i < Q;i++)
    QR(), R();
  
  return 0;
}

/*
10 3 20
8 0 0 0 0 0 0 0 0 8
0 0 0 1 0 9 0 0 9 1
a 3 8
a 3 0
a 10 0
b 1 8
a 2 0
a 6 8
a 5 0
b 3 8
a 7 8
a 10 9
a 7 0
b 1 1
a 2 0
b 4 8
a 8 0
a 4 9
b 9 8
b 9 9
b 9 9
b 6 9
*/