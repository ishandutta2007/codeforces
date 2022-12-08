#include <iostream>
#include <cstdio>

#include <set>
#include <algorithm>
#include <utility>

using namespace std;

const int MN = 2e5 + 100;
const int MM = 2e5 + 100;

typedef long long ll;
#define tll(X) static_cast<ll>(X)

struct EDG {
  int u, v;
  ll w;
  bool operator < (const EDG& o) const {return w < o.w;}
};
EDG e[MM];

ll a[MN];

int N, M;

typedef pair<ll, int> pli;
#define ff first
#define ss second

typedef set<pli> sp;
#define IT iterator
typedef sp::IT sit;

sp L;

template<int MS = MN> struct DSU {
public:
  int p[MS], s[MS], S;
  ll w[MS];
  
  void i(int z) {
    S = z;
    for(int i = 1;i <= S;i++) p[i] = i, w[i] = a[i], s[i] = 1;
  }
  int f(int n) {
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
  }
  bool m(int a, int b) {
    a = f(a), b = f(b);
    if(a == b) return false;
    if(s[a] < s[b]) swap(a, b);
    p[b] = a, s[a] += s[b], s[b] = 0;
    if(w[b] < w[a]) swap(w[a], w[b]);
    w[b] = -1LL;
    return true;
  }
};
DSU<> dsu;

int main() {
  scanf("%d%d", &N, &M);
  
  L.clear();
  for(int i = 1;i <= N;i++) scanf("%lld", a + i), L.insert({a[i], i});
  for(int i = 0;i < M;i++) scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
  dsu.i(N);
  sort(e, e + M);
  
  ll f = 0LL;
  sit l[2];
  for(int i = 0;;) {
    if(L.size() == 1) break;
    l[1] = L.begin(), l[0] = l[1]++;
    if(i < M and e[i].w < l[0]->ff + l[1]->ff) {
      if(dsu.m(e[i].u, e[i].v)) f += e[i].w;
      i++;
    } else {
      if(dsu.m(l[0]->ss, l[1]->ss)) f += l[0]->ff + l[1]->ff;
      L.erase(l[1]);
    }
  }
  printf("%lld\n", f);
  
  return 0;
}