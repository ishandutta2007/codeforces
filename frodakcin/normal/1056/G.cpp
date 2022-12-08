#include <iostream>
#include <cstdio>

#include <utility>
#include <cassert>

using namespace std;

typedef long long ll;
#define tll(X) static_cast<ll>(X)

typedef pair<int, int> pii;
#define ff first
#define ss second

const int MAXN = 1e5 + 100;
const int NL2 = 20;
const int TL2 = 50;

const int MAXS = MAXN * NL2 * 10;

struct PBT {
public:
  int c[MAXS][2];
  int v[MAXS], h[MAXS], s[MAXS];
  int X;
  PBT() : X(1) {}
  int nn(const int& n = 0, const int& q = -1) {
    assert(X < MAXS);
    if(n == 0) {
      c[X][0] = c[X][1] = 0;
      v[X] = q, h[X] = s[X] = 1;
    } else {
      for(int i = 0;i < 2;i++) c[X][i] = c[n][i];
      v[X] = v[n], h[X] = h[n], s[X] = s[n];
    }
    return X++;
  }
  int gs(const int& n) {if(n == 0) return 0; else return s[n];}
  int gh(const int& n) {if(n == 0) return 0; else return h[n];}
  void upd(const int& n) {
    s[n] = gs(c[n][0]) + gs(c[n][1]) + 1;
    h[n] = max(gh(c[n][0]), gh(c[n][1])) + 1;
  }
  //for splay funtions & balance, assume n is already a copy when necessary. Also assume input is balanced, output is balanced
  int L(int& n, bool p = false) {  //cost: 1     //false - not persistent, true - copies child, but not node
    assert(n and c[n][1]);
    int r = p ? nn(c[n][1]) : c[n][1];
    c[n][1] = c[r][0], c[r][0] = n;
    upd(n); upd(r);
    return n = r;
  }
  int R(int& n, bool p = false) {  //cost: 1
    assert(n and c[n][0]);
    int r = p ? nn(c[n][0]) : c[n][0];
    c[n][0] = c[r][1], c[r][1] = n;
    upd(n); upd(r);
    return n = r;
  }
  int bal(int& n, bool p = false) {  //cost: 2
    int b = gh(c[n][0]) - gh(c[n][1]);
    if(b > 1) {
      if(gh(c[c[n][0]][0]) + 1 == gh(c[n][0]))
        return R(n, p);
      else {
        L(p ? (c[n][0] = nn(c[n][0])) : c[n][0], p);
        return R(n, false);
      }
    }
    if(b < -1) {
      if(gh(c[c[n][1]][1]) + 1 == gh(c[n][1]))
        return L(n, p);
      else {
        R(p ? (c[n][1] = nn(c[n][1])) : c[n][1], p);
        return L(n, p);
      }
    }
    return n;
  }
  
    int mergeR(int l, int x, int r, bool p = false) {
    if(gh(l) > gh(r) + 1) {
      if(p) l = nn(l);
      c[l][1] = mergeR(c[l][1], x, r, p);
      upd(l);
      return bal(l, p);
    }
    if(gh(l) < gh(r) - 1) {
      if(p) r = nn(r);
      c[r][0] = mergeR(l, x, c[r][0], p);
      upd(r);
      return bal(r, p);
    }
    int y = nn(0, x);
    c[y][0] = l, c[y][1] = r;
    upd(y);
    return y;
  }
  int merge(int l, int r, bool p = false) {
    if(not r) return l;
    if(not l) return r;
    if(gh(l) < gh(r)) {
      if(p) r = nn(r);
      c[r][0] = merge(l, c[r][0], p);
      upd(r);
      return bal(r, p);
    } else {
      if(p) l = nn(l);
      c[l][1] = merge(c[l][1], r, p);
      upd(l); 
      return bal(l, p);
    }
  }
  pii split(int n, int k) {//automatically persistent
    if(not n) return {0, 0};
    if(k == 0) return {0, n};
    if(k == gs(n)) return {n, 0};
    if(k > gs(c[n][0])) {
      pii d = split(c[n][1], k - gs(c[n][0]) - 1);
      return {mergeR(c[n][0], v[n], d.ff, true), d.ss};
    } else {
      pii d = split(c[n][0], k);
      return {d.ff, mergeR(d.ss, v[n], c[n][1], true)};
    }
  }
  
  int build(int l, int r) {
    if(r - l < 1) return 0;
    if(r - l > 1) {
      int m = l + ((r - l)>>1);
      int x = nn(0, m);
      c[x][0] = build(l, m);
      if(c[x][0]) assert(s[c[x][0]]);
      c[x][1] = build(m + 1, r);
      upd(x);
      return x;
    } else return nn(0, l);
  }
  void fill(int n, int * q, int * w = new int(0)) {
    if(not n) return;
    fill(c[n][0], q, w);
    q[(*w)++] = v[n];
    fill(c[n][1], q, w);
  }
  void pout(int n) {
    if(not n) return;
    pout(c[n][0]);
    cerr << v[n] << " ";
    pout(c[n][1]);
  }
} pbt;

int R;

int N, M, S;
ll T;

int get(int l, int r) {
  while(l >= N) l -= N, r -= N;
  while(l < 0) l += N, r += N;
  if(r > N) return pbt.merge(get(l, N), get(N, r), true);
  return pbt.split(pbt.split(R, r).ff, l).ss;
}

int f[TL2][MAXN];

void brute() {
  int s = T%N;
  for(int i = s;i > 0;i--, T--) {
    if(S < M) S = (S + i)%N;
    else S = (S - i + N)%N;
  }
}

void solve() {
  scanf("%d%lld", &S, &T);
  S--;
  brute();
  T /= N;
  for(int i = 0;T;i++, T>>=1LL)
    if(T&1) S = f[i][S];
  printf("%d\n", ++S);
}

int main() {
  scanf("%d%d", &N, &M);
  
  R = pbt.build(0, N);
  for(int i = 1;i < N;i++)
    R = pbt.merge(get(i, i + M), get(M - i, N - i), true);
  pbt.fill(R, f[0]);
  
  for(int i = 0;i + 1 < TL2;i++)
    for(int j = 0;j < N;j++)
      f[i+1][j] = f[i][f[i][j]];
  
  solve();
  
  return 0;
}