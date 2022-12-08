#include <iostream>
#include <cstdio>

#include <vector>
#include <bitset>
#include <stack>

using namespace std;

const int MAXN = 2e6 + 100;

int N, K;

typedef vector<int> vi;
#define pb push_back

vi adj[MAXN];
bitset<MAXN> u;

int s[MAXN];
int dfs(int n, int p = -1) {
  s[n] = u[n] ? 1 : 0;
  for(int i = 0;i < adj[n].size();i++) {
    if(adj[n][i] == p) continue;
    s[n] += dfs(adj[n][i], n);
  }
  return s[n];
}
int get_centroid(int t, int n, int p = -1) {
  for(int i = 0;i < adj[n].size();i++) {
    if(adj[n][i] == p) continue;
    if(s[adj[n][i]] * 2 >= t) return get_centroid(t, adj[n][i], n);
  }
  return n;
}
int get_centroid(int n) {
  return get_centroid(dfs(n), n);
}

int e[MAXN], es, ec, c;
bool m;

bool y;
int f[MAXN>>1][2], fc;

void fil(int n) {
  if(fc == K) fc = 0, y = true;
  f[fc++][y] = n;
}
void ans(int n, int p) {
  if(u[n]) fil(n);
  for(int i = 0;i < adj[n].size();i++) if(adj[n][i] != p) ans(adj[n][i], n);
}

int main() {
  scanf("%d%d", &N, &K);
  
  for(int i = 0, w, v;i < N - 1;i++) {
    scanf("%d%d", &w, &v);
    adj[w].pb(v);
    adj[v].pb(w);
  }
  
  for(int i = 0;i <= N;i++) u[i] = false;
  for(int i = 0, v;i < 2*K;i++) scanf("%d", &v), u[v] = true;
  
  c = get_centroid(1);
  
  printf("1\n%d\n", c);
  
  fc = 0, y = false;
  if(u[c]) f[fc++][0] = c;
  for(int i = 0;i < adj[c].size();i++) ans(adj[c][i], c);
  
  for(int i = 0;i < K;i++) printf("%d %d %d\n", f[i][0], f[i][1], c);
  
  return 0;
}