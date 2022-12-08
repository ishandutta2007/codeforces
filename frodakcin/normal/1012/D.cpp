#include <iostream>
#include <cstdio>

#include <utility>
#include <deque>
#include <array>

#include <cassert>

using namespace std;

using pi = pair<bool, int>;
using dp = deque<pi>;
#define ff first
#define ss second
#define sz size()
#define bk back()
#define fr front()
#define popb pop_back()
#define popf pop_front()
#define pb push_back
#define pf push_front
#define IT iterator
using dpt = dp::IT;

const int ML = 2e5 + 100;

char I[ML];
void in(bool * s, dp& u, int& S) {
  scanf(" %s", I);
  for(S = 0;I[S] != '\0';S++) {
    s[S] = I[S] == 'b';
    if(not u.empty() and u.bk.ff == s[S]) u.bk.ss++; else u.push_back({s[S], 1});
  }
}

void flip(dp& a, dp& b, int A, int B) {
  assert(A <= a.sz and B <= b.sz);
  dp c, d;
  for(int i = 0;i < A;i++) c.pb(a.fr), a.popf;
  for(int i = 0;i < B;i++) d.pb(b.fr), b.popf;
  for(int i = 0;i < A;i++) (b.empty() or b.fr.ff != c.bk.ff ? b.pf(c.bk), 0 : b.fr.ss += c.bk.ss), c.popb;
  for(int i = 0;i < B;i++) (a.empty() or a.fr.ff != d.bk.ff ? a.pf(d.bk), 0 : a.fr.ss += d.bk.ss), d.popb;
  assert(c.empty() and d.empty());
}

using i2 = array<int, 2>;
const int MN = 5e5 + 100;
i2 f[MN];
int N;

void add(int a, int b) {f[N++] = {a, b};}
void fin() {
  printf("%d\n", N);
  for(int i = 0;i < N;i++) printf("%d %d\n", f[i][0], f[i][1]);
}

bool s[ML], t[ML];
dp u, v;
int S, T, A, B, C;

void greedy() {
  if(u.fr.ff == v.fr.ff) {
    if(u.sz < v.sz) add(0, v.fr.ss), u.fr.ss += v.fr.ss, v.popf;
    else add(u.fr.ss, 0), v.fr.ss += u.fr.ss, u.popf;
  }
  A = B = 0;
  int i = 1;
  if(u.sz < v.sz) for(dpt a = u.begin(), b = v.begin();i < v.sz;i++, b++, (a != u.end() ? a++ : a)) add(A += (a != u.end() ? a->ss : 0), B += b->ss), swap(A, B);
  else for(dpt a = u.begin(), b = v.begin();i < u.sz;i++, a++, (b != v.end() ? b++ : b)) add(A += a->ss, B += (b != v.end() ? b->ss : 0)), swap(A, B);
}

int F, X, Y, L;

void rp(int a, int b, int c) {
  if(a < F) F = a, X = b, Y = c;
}
void pick(const dp& a, const dp& b) {
  F = max(u.sz - 1, v.sz - 1) + (u.sz == v.sz and u.fr.ff == v.fr.ff), X = Y = -1;
  
  if(a.fr.ff == b.fr.ff) {
    if(a.sz < b.sz) {
      L = (b.sz - a.sz + 1)>>1;
      rp(max(b.sz - L, a.sz + L - 1), not (a.fr.ff xor b.fr.ff xor (L&1)), L);
    } else {
      L = (a.sz - b.sz + 1)>>1;
      rp(max(a.sz - L, b.sz + L - 1), L, not (a.fr.ff xor b.fr.ff xor (L&1)));
    }
  } else {
    if(a.sz < b.sz) {
      L = (b.sz - a.sz + 1)>>1|1;
      rp(max(b.sz - L, a.sz + L - 2), 1, L);
    } else {
      L = (a.sz - b.sz + 1)>>1|1;
      rp(max(a.sz - L, b.sz + L - 2), L, 1);
    }
  }
}

int main() {
  in(s, u, S), in(t, v, T);
  
  pick(u, v);
  if(X == -1) greedy();
  else {
    int F1, F2;
    F1 = F2 = 0;
    for(int i = 0;i < X;i++) F1 += u[i].ss;
    for(int i = 0;i < Y;i++) F2 += v[i].ss;
    add(F1, F2);
    flip(u, v, X, Y);
    greedy();
  }
  
  fin();
  
  return 0;
}