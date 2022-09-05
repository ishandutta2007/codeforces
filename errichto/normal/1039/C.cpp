#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long ll;

const int mod = 1e9 + 7;

const int nax = 5e5 + 5;
vector<int> w[nax];
bool vis[nax];

void dfs(int a, int & cnt) {
  assert(!vis[a]);
  ++cnt;
  vis[a] = true;
  for(int b : w[a]) if(!vis[b]) dfs(b, cnt);
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> two(n + 1);
  two[0] = 1;
  for(int i = 1; i <= n; ++i) two[i] = 2 * two[i-1] % mod;
  vector<ll> value(n);
  for(ll & x : value) scanf("%lld", &x);
  map<ll, vector<pair<int,int>>> mapka;
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    mapka[value[a]^value[b]].push_back(make_pair(a, b));
  }
  int answer = 0;
  for(const auto& pp : mapka) {
    const vector<pair<int,int>> & edges = pp.second;
    // dwudzielny
    vector<int> vertices;
    for(pair<int,int> p : edges) {
      vertices.push_back(p.first);
      vertices.push_back(p.second);
      w[p.first].push_back(p.second);
      w[p.second].push_back(p.first);
    }
    sort(vertices.begin(), vertices.end());
    vertices.resize( unique(vertices.begin(), vertices.end()) - vertices.begin() );
    
    int dobre = 1;
    int remaining = n;
    
    for(int a : vertices) if(!vis[a]) {
      int cnt = 0;
      dfs(a, cnt);
      assert(cnt >= 2);
      debug() << imie(cnt);
      remaining -= cnt;
      dobre = (ll) dobre * 2 % mod;
    }
    debug();
    dobre = (ll) dobre * two[remaining] % mod;
    
    answer = (answer + two[n] - dobre) % mod;
    answer = (answer + mod) % mod;
    
    for(int a : vertices) {
      w[a].clear();
      vis[a] = false;
    }
  }
  answer = (1LL << k) % mod * two[n] % mod - answer;
  answer = ((answer % mod) + mod) % mod;
  printf("%d\n", answer);
}