#include <iostream>
#include <cstdio>

#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
#define mp make_pair
#define ff first
#define ss second

typedef vector<pii> vpi;
#define pb push_back

const int INF = 1e9 + 1e6;
const int MAXN = 1e5 + 100;
const int MAXS = MAXN * 3;

int N, M, K;

void append(vpi& a, pii b) {
  while(!a.empty()) {
    if(a.back().ff <= b.ff and b.ss <= a.back().ss) a.pop_back();
    else if(b.ff <= a.back().ff and a.back().ss <= b.ss) return;
    else break;
  }
  a.pb(b);
}
pii operator + (const pii& a, const pii& b) {return mp(min(a.ff, b.ff), max(a.ss, b.ss));}
vpi merge(const vpi& a, const vpi& b) {
  vpi r;
  for(int i = 0, j = 0;i < a.size() and j < b.size();) {
    append(r, a[i] + b[j]);
    if(j == b.size() - 1 or (i < a.size() - 1 and a[i].ff < b[j].ff)) i++;
    else j++;
  }
  return r;
}
int get(const vpi& a, int g) {
  int l = -1, h = a.size();
  while(h > l + 1) {
    int m = l + ((h - l)>>1);
    if(a[m].ff < g) l = m;
    else h = m;
  }
  if(h == a.size()) return INF; else return a[h].ss;
}
int t;
void workarr(vpi& a) {
  sort(a.begin(), a.end(), [](const pii& x, const pii& y) {return x.ff < y.ff or (not(y.ff < x.ff) and x.ss < y.ss);});
  t = 0;
  for(int i = 0, s = a.size(), q = 1;i < s;i++, q = 1) {
    while(t) {
      if(a[t-1].ff <= a[i].ff and a[i].ss <= a[t-1].ss) --t;
      else if(a[i].ff <= a[t-1].ff and a[t-1].ss <= a[i].ss) {q = 0; break;}
      else break;
    }
    if(q) a[t++] = a[i];
  }
  a.resize(t);
}

void rpl(int& a, int b) {
  if(a < b) a = b;
}

struct ST {
public:
  vpi v[MAXS];
  void build() {
    for(int i = N - 1;i > 0;i--) v[i] = merge(v[i<<1], v[i<<1|1]);
  }
  int qry(int l, int r, int g) {
    int a = 0;
    for(l += N, r += N;l < r;l >>= 1, r >>= 1) {
      if(l&1) rpl(a, get(v[l++], g));
      if(r&1) rpl(a, get(v[--r], g));
    }
    return a;
  }
} st;

void pout(const vpi& a) {
  for(int i = 0;i < a.size();i++) printf("%d %d\n", a[i].ff, a[i].ss);
  printf("\n");
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  
  for(int i = 0, l, r, p;i < K;i++) {
    scanf("%d%d%d", &l, &r, &p);
    st.v[N+--p].pb(mp(l, ++r));
  }
  
  for(int i = 0;i < N;i++) {
    workarr(st.v[N+i]);
    //printf("%d\n", i);
    //pout(st.v[N+i]);
  }
  st.build();
  
  for(int i = 0, a, b, x, y;i < M;i++) {
    scanf("%d%d%d%d", &a, &b, &x, &y);
    if(st.qry(--a, b, x) > ++y) printf("no\n");
    else printf("yes\n");
    fflush(stdout);
  }
  
  return 0;
}