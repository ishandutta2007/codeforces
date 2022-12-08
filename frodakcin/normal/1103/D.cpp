#include <iostream>
#include <cstdio>

#include <vector>
#include <utility>
#include <map>
#include <array>
#include <set>
#include <bitset>

using namespace std;

/*
solution copied from https://codeforces.com/contest/1103/submission/48907897
*/

using ll = long long;

template<class T> void rpl(T& a, const T& b) {if(a > b) a = b;}

ll gcd(ll a, ll b) {
  if(a > b) swap(a, b);
  if(a == 0) return b;
  return gcd(b%a, a);
}

using vi = vector<ll>;
#define pb push_back
using i2 = array<int, 2>;
//bool operator < (const i2& a, const i2& b) {return a[0] > b[0] or (not(b[0] > a[0]) and a[1] > b[1]);}
const auto cmp = [](const i2& a, const i2& b) {return a[0] > b[0] or (not(b[0] > a[0]) and a[1] > b[1]);};
#define IT iterator
using si2 = set<i2, decltype(cmp)>;
using vsi2 = vector<si2>;
using msi2 = map<ll, si2>;
using msit = msi2::IT;
using psi2 = pair<ll, si2>;
#define ff first
#define ss second

const int MN = 1e6 + 100;
const ll INF = 1e17;
const int MM = 12;

void fact(ll n, vi& f) {
  f.clear();
  for(ll i = 2;i*i <= n;i++) {
    if(n%i == 0) {
      f.pb(i);
      for(;(n/=i)%i==0;);
    }
  }
  if(n > 1) f.pb(n);
}

ll t;
vi T;

ll conv(ll n, vi& f) {
  f.clear();
  ll r = 1LL;
  for(ll i : T) {
    f.pb(1LL);
    for(;n%i==0;n/=i,f.back()*=i);
    r*=f.back();
  }
  return r;
}

ll a[MN], K, c[MN];
int e[MN], N, M;
vi f[MN];
bitset<MN> u;

void pick() {
  u.reset();
  msi2 m;
  m.clear();
  for(int i = 0;i < N;i++) {
    si2& s = (m.find(c[i]) == m.end() ? m.insert({c[i], si2(cmp)}).ff->ss : m.find(c[i])->ss);
    s.insert({e[i], i});
    if(s.size() > M) s.erase(s.begin());
  }
  for(auto x : m) for(auto y : x.ss) u[y[1]] = true;
}
vector<int> b[MN];
void comp() {
  vsi2 m(1<<M, si2(cmp));
  
  for(si2& x : m) x.clear();
  for(int i = 0;i < N;i++) if(u[i]) {
    for(int j = 1;j < 1<<M;j++) {
      ll v = 1LL;
      for(int k = 0;k < M;k++) if(j&1<<k) v*=f[i][k];
      if(v > K) continue;
      si2& s = m[j];
      s.insert({e[i], i});
      if(s.size() > M) s.erase(s.begin());
    }
  }
  for(int i = 1;i < 1<<M;i++) for(auto y : m[i]) b[y[1]].pb(i);
}

ll d[2][MM][1<<MM];
bool C;

void work(int m, int v) {
  for(int i = 1;i <= M;i++) {
    for(int j = m;j < 1<<M;j=j+1|m) {
      rpl(d[1][i][j], d[0][i-1][j^m]+v);
    }
  }
}

int main() {
  scanf("%d%lld", &N, &K);
  
  t = 0LL;
  for(int i = 0;i < N;i++) scanf("%lld", a + i), t = gcd(t, a[i]);
  for(int i = 0;i < N;i++) scanf("%d", e + i);
  fact(t, T), M = T.size();
  
  if(t == 1) return printf("0\n"), 0;
  
  //cerr << t << "\n";
  
  for(int i = 0;i < N;i++) c[i] = conv(a[i], f[i]);
  
  pick();
  comp();
  
  for(int i = 0;i <= M;i++) for(int j = 0;j < 1<<M;j++) d[1][i][j] = INF;
  d[1][0][0] = 0LL;
  for(int i = 0;i < N;i++) {
    if(b[i].empty()) continue;
    C=not C;
    for(int j = 0;j <= M;j++) for(int k = 0;k < 1<<M;k++) d[0][j][k] = d[1][j][k];
    //for(int j : b[i]) cerr << j << " "; cerr << "\n";
    for(int j : b[i]) work(j, e[i]);
  }
  
  ll z = INF;
  for(int i = 1;i <= M;i++) rpl(z, d[1][i][(1<<M)-1]*i);
  if(z == INF) printf("-1\n"); else printf("%lld\n", z);
  
  return 0;
}