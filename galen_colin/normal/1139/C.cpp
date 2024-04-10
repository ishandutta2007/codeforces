#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
ll i, j;
const ll mod = 1e9 + 7;

ll n, q, Q, T, m, k, r, x;
ll a[100003]; bool vis[100001];
ll ans = 0;
vector<int> edges[100001];
int cnt = 0;

ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2 == 1){
           res = (res * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

void dfs(int a) {
  if (vis[a]) return;
  cnt++;
  vis[a] = 1;
  for(int i: edges[a]) dfs(i);
}
int main() {
  io;
  cin >> n >> k;
  ms(vis, 0);
  f0r(i, n+1) {
    a[i+1] = mpow(i+1, k);
  }
  ll ans = a[n];
  f0r(i, n-1) {
    ll a, b, c;
    cin >> a >> b >> c; a--, b--;
    if (c == 1) continue;
    edges[a].pb(b); edges[b].pb(a);
  }
  f0r(i, n) {
    cnt = 0;
    if (!vis[i]) dfs(i);
    ans = (mod + ((ans - a[cnt]) % mod)) % mod;
  }
  cout << max(ans, 0LL) << endl;
}