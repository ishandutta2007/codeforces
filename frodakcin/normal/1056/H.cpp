#include <iostream>
#include <cstdio>

#include <vector>
#include <utility>

using namespace std;

const int MAXN = 3e5 + 100;
const int MAXQ = 3e5 + 100;
const int R = 500;

int N, Q;

typedef vector<int> vi;
#define pb push_back

vi a[MAXQ], b[MAXQ];
int A, B;

int l[MAXN];

bool testa2(const vi& x, const vi& q) {
  for(int i = 0, t, f = -1;i < q.size();i++) if((t = l[q[i]]) != -1) {
    if(f != -1 and f < t) if(x[t-1] != q[i-1]) return true;
    if(f == -1 or t < f) f = t;
  }
  return false;
}
bool testa(const vi& x) {
  for(int i = 0;i < x.size();i++) l[x[i]] = i;
  for(int i = 0;i < A;i++) if(testa2(x, a[i])) return true;
  for(int i = 0;i < B;i++) if(testa2(x, b[i])) return true;
  for(int i = 0;i < x.size();i++) l[x[i]] = -1;
  return false;
}

typedef pair<int, int> pii;
#define ff first
#define ss second
typedef vector<pii> vpi;
#define pb push_back

vpi e[MAXN];
int p[MAXN];
bool test2(int v) {
  for(int i = 0, t, g;i < e[v].size();i++) {
    for(int j = e[v][i].ss + 1, n = e[v][i].ff, t;j < b[n].size();j++) {
      t = b[n][j-1];
      if(p[b[n][j]] != -1 and p[b[n][j]] != t) return true;
      p[b[n][j]] = t;
    }
  }
  for(int i = 0;i < e[v].size();i++) for(int j = e[v][i].ss + 1;j < b[e[v][i].ff].size();j++) p[b[e[v][i].ff][j]] = -1;
  return false;
}

bool solve() {
  scanf("%d%d", &N, &Q);
  for(int i = 0;i <= N;i++) l[i] = p[i] = -1;
  A = B = 0;
  for(int i = 0, s;i < Q;i++) {
    scanf("%d", &s);
    vi& q = s > R ? a[A++] : b[B++];
    q.assign(s, -1);
    for(int& x : q) scanf("%d", &x);
  }
  
  for(int i = 0;i < A;i++) if(testa(a[i])) return true;
  
  for(int i = 0;i <= N;i++) e[i].clear();
  for(int i = 0;i < B;i++)
    for(int j = 0;j < b[i].size();j++) e[b[i][j]].pb({i, j});
  for(int i = 1;i <= N;i++) if(test2(i)) return true;
  
  return false;
}

int T;
int main() {
  scanf("%d", &T);
  while(T--) if(solve()) printf("Human\n"); else printf("Robot\n");
  return 0;
}