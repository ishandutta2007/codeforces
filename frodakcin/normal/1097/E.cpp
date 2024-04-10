#include <iostream>
#include <cstdio>

#include <vector>
#include <array>
#include <set>

#include <cassert>

using namespace std;

const int MV = 1e5 + 100;
const int MN = 1e5 + 100;

using vi = vector<int>;
using ar2 = array<int, 2>;

void rph(ar2& a, const ar2& b) {if(a[0] < b[0] or (not(b[0] < a[0]) and a[1] > b[1])) a = b;}

int C;
vi F[MN];

template<int MS = MV> struct BIT {
public:
  ar2 v[MS];
  int s;
  void init(int z) {
    s = z;
    for(int i = 0;i < s;i++) v[i] = {0, -1};
  }
  void upd(int p, ar2 q) {
    for(;p<=s;p += p&(p^(p-1))) rph(v[p-1], q);
  }
  ar2 qry(int p) {
    ar2 r = {0, -1};
    for(;p;p &= (~p^(p-1))) rph(r, v[p-1]);
    return r;
  }
};
BIT<> bit;

int N;

int p[MN];
ar2 getLIS(const vi& v) {
  bit.init(N + 10);
  ar2 f = {0, -1};
  for(int i = 0;i < v.size();i++) {
    ar2 x = bit.qry(v[i] - 1);
    bit.upd(v[i], {x[0] + 1, v[i]});
    rph(f, {x[0] + 1, v[i]});
    p[v[i]] = x[1];
  }
  return f;
}

using si = multiset<int>;
#define IT iterator
using sit = multiset<int>::IT;

void outp(int x) {
  if(p[x] != MV) outp(p[x]);
  F[C].push_back(x);
}

bool u[MV];
void ans(const vi& v, int c) {
  si s;
  for(int i = 0;i < N + 10;i++) u[i] = true;
  for(const int& i : v) u[i] = false;
  for(int i = 0;i < c;i++) s.insert(MV);
  for(int i = 0;i < v.size();i++) {
    sit t = s.upper_bound(v[i]);
    assert(t != s.end());
    p[v[i]] = *t;
    s.erase(t);
    s.insert(v[i]);
  }
  for(auto x : s) outp(x), C++;
}

vi a;

using ll = long long;
#define tl(X) static_cast<ll>(X)

void append(vi& r, int x) {
  if(p[x] != -1) append(r, p[x]);
  F[C].push_back(x);
  r.push_back(x);
}

void fix(vi& v, vi r) {
  for(int i = 0, o = 0, j = 0;i < v.size();i++) {
    for(;i + o < v.size() and j < r.size() and r[j] == v[i + o];) o++, j++;
    if(i + o < v.size()) v[i] = v[i + o];
  }
  v.resize(v.size() - r.size());
}

void fin() {
  printf("%d\n", C);
  for(int i = 0;i < C;i++) {
    printf("%lu", F[i].size());
    for(const int& j : F[i]) printf(" %d", j);
    F[i].clear();
    printf("\n");
  }
}

void solve() {
  C = 0;
  
  scanf("%d", &N);
  
  a.assign(N, 0);
  for(int& x : a) scanf("%d", &x);
  
  for(;a.size();) {
    ar2 x = getLIS(a);
    if(tl(x[0]) * (x[0] + 1) / 2 > a.size()) {
      vi y(0, 0);
      append(y, x[1]), C++;
      fix(a, y);
    } else {ans(a, x[0]); break;}
  }
  
  fin();
}

int T;

int main() {
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}