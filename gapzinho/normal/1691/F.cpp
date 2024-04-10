#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int ms = 2e5+5;

int sz[ms];
vector<int> g[ms];
int n, k;
int tmp = 0;
int fat[ms], ifat[ms];

int choose(int a, int b) {
   if(b > a) return 0;
   return fat[a] * ifat[b] % mod * ifat[a-b] % mod;
}

int dp[ms];
int sum[ms];

int dfs(int u,  int p = -1) {
   sz[u] = 1;
   vector<int> poss;
   for(int v : g[u]) {
      if(v == p) continue;
      sz[u] += dfs(v, u);
      poss.emplace_back(sz[v]);
   }
   // if(sz[u] != n) poss.emplace_back(n-sz[u]);
   for(int x : poss) {
      sum[u] = (sum[u] + choose(x, k)) % mod;
   }
   // tmp = (tmp + sum) % mod;

   dp[u] = sum[u];
   for(int v : g[u]) {
      if(v == p) continue;
      int miaj = (sum[u] - choose(sz[v], k) + mod) % mod;
      dp[u] = (dp[u] + dp[v] + miaj * sz[v]) % mod;
   }
   // cout << u << " - " << sum << endl;
   // for(int x : poss) {
   //    int miaj = sum;
   //    cout << "Sum -> " << choose(x, k) << " e " << x << " deu = " << miaj*x << endl;
   //    tmp = (tmp + miaj * x) % mod;
   // }
   return sz[u];
}

void dfs2(int u,  int p = -1, int rerr = 0) {
   int aux1 = sum[u]*(n-sz[u]); // enraizar num pai e puff
   int magic = rerr;                     //  enraizar num pai e ter todos do pai? rerr
   int aux2 = sz[u] * choose(n-sz[u], k); // enraizar num filho e ter todos do pai
   int super = (dp[u] + magic + aux2 + aux1) % mod;
               // rerr = 
   tmp = (tmp + super) % mod;
   for(int v : g[u]) {
      if(v == p) continue;
      int miaj = (sum[u] + choose(n-sz[u], k) - choose(sz[v], k) + mod) % mod;
      int aaaaa = (miaj*sz[v] + dp[v] + choose(sz[v], k)*(n-sz[v]))% mod;
      int passar = (super - aaaaa + mod) % mod;
      dfs2(v, u, passar);
   }
}


int fexp(int a, int b) {
  int ans = 1;
  while(b) {
    if(b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}


void solve() {
   cin >> n >> k;
   fat[0] = 1;
   for(int i = 1; i <= n; i++) fat[i] = fat[i-1] * i % mod;
   ifat[n] = fexp(fat[n], mod-2);
   for(int i = n-1; i >= 0; i--) {
      ifat[i] = ifat[i+1] * (i+1) % mod;
   }
   for(int i = 1; i <n ; i++) {
      int x, y;
      cin >> x >> y;
      g[x].emplace_back(y);
      g[y].emplace_back(x);
   }
   dfs(1);
   dfs2(1);
   // cout << fat[3] << " " << ifat[2] << " e " << ifat[1] << endl;
   // cout << choose(n, k)*(n*n) << " e " << tmp << endl;
   int ans = (choose(n, k)*((n*n) % mod) - tmp + mod) % mod;
   cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
//   cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}