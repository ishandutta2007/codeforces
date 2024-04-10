#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
using ull = uint64_t;
using ii = pair<int, int>;
using iii = pair<int, ii>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  long double;
const int inf = 0x3f3f3f3f3f3f3f3f;
 
const int ms = 2e5+5;
const int mod = 998244353;

int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans*a%mod;
    a = a*a%mod;
    b >>= 1;
  }
  return ans;
}
 

int qnt[ms];
int sz[ms];
map<int, int> dic[ms];
int curans[ms];
int ans = 0;

vector<int> g[ms];
map<int, int> facts[ms];


void add(int u, int f, int q) {
  int curhlp = dic[u][f];
  int newcurhlp = q + curhlp;
  curans[u] = (curans[u] + (qnt[f]-2) * newcurhlp * (qnt[f] - newcurhlp) + mod - ((qnt[f]-2) * curhlp * (qnt[f] - curhlp)) % mod) % mod;
  // cout << "atualizando " << u << " - " << f << " to " <<  newcurhlp * (qnt[f] - newcurhlp) << endl;
  dic[u][f] += q;
}

void dfs(int u, int par = -1) {
  for(int v : g[u]) {
    if(v == par) continue;
    dfs(v, u);
    if(dic[v].size() > dic[u].size()) {
      dic[v].swap(dic[u]);
      swap(curans[u], curans[v]);
    }
  }
  for(auto [f, q] : facts[u]) {
    add(u, f, q);
  }
  for(int v : g[u]) {
    if(v == par) continue;
    if(dic[v].empty()) continue;
    for(auto [f, q] : dic[v]) {
      add(u, f, q);
    }
  }
  // cout << u << " -> " << curans[u] << endl;
  ans = (ans + curans[u]) % mod;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for(int k = 2; k * k <= x; k++) {
      while(x % k == 0) {
        x /= k;
        facts[i][k] = 1;
      }
    }
    if(x > 1) facts[i][x] = 1;
    for(auto p : facts[i]) {
      qnt[p.first]++;
    }
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  dfs(1);
  // cout << tmp << endl;
  cout << ans * fexp(2, mod-2) % mod << '\n';
}
 
 
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int T = 1; T <= t; T++) {
    // cout << "Case #" << T << ": ";
    solve(); 
  }
  return 0;
}