#include <iostream>
#include <cstdio>

#include <vector>
#include <array>
#include <set>

using namespace std;

const int MN = 1e5 + 1000;

using a2 = array<int, 2>;
using a3 = array<int, 3>;

int N, M;

using vi = vector<a3>;
#define pb push_back

vi a[MN];
bool v[MN], u[MN];
int T;

bool dfs(int n) {
  u[n] = true;
  v[n] = true;
  for(a3 x : a[n]) {
    if(x[1] <= T) continue;
    if(u[x[0]]) return true;
    if(v[x[0]]) continue;
    if(dfs(x[0])) return true;
  }
  u[n] = false;
  return false;
}
bool scc() {
  for(int i = 0;i <= N;i++) v[i] = u[i] = false;
  for(int i = 1;i <= N;i++) if(not v[i] and dfs(i)) return true;
  return false;
}

using si = set<int>;

si f;

int s[MN], sc;
void dfs2(int n) {
  v[n] = true;
  for(a3 x : a[n]) {
    if(x[1] <= T) continue;
    if(v[x[0]]) continue;
    dfs2(x[0]);
  }
  s[n] = sc++;
}

a2 e[MN];

int main() {
  scanf("%d%d", &N, &M);
  
  for(int i = 1, u, v, c;i <= M;i++) {
    scanf("%d%d%d", &u, &v, &c);
    a[u].pb({v, c, i});
    e[i] = {u, v};
  }
  
  int l = -1, h = 1e9 + 100;    //optimize to n log n if necessary
  while(l + 1 < h) {
    T = l + ((h-l)>>1);
    if(scc()) l = T;
    else h = T;
  }
  
  T = h;
  
  for(int i = 0;i <= N;i++) v[i] = false;
  sc = 1;
  for(int i = 1;i <= N;i++) if(not v[i]) dfs2(i);
  //for(int i = 1;i <= N;i++) cerr << s[i] << "\n";
  for(int i = 1;i <= M;i++)
    if(s[e[i][0]] < s[e[i][1]]) f.insert(i);
  
  printf("%d %d\n", T, static_cast<int>(f.size()));
  for(const auto& x : f) printf("%d ", x);
  
  printf("\n");
  
  return 0;
}