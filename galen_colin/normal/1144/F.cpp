#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 

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
typedef pair<ll, ll> pll;
ll i, j;

ll n, q, Q, T, m, k, r, x, y, z, g;
vector<int> e[200001];
bool label[200001], vis[200001], ans[200001];
pii edg[200001];

void dfs(int v, bool l) {
  if (vis[v]) return;
  label[v] = l;
  vis[v] = 1;
  for (int i: e[v]) dfs(i, !l);
}

int main() {
  io;
  cin >> n >> m;
  ms(vis, 0);
  ms(label, 0);
  f0r(i, m) {
    int a, b; cin >> a >> b; --a; --b;
    e[a].pb(b); e[b].pb(a);
    edg[i] = (mp(a, b));
  }
  dfs(0, 0);
  bool f = 1;
  f0r(i, n) {
    for (int v: e[i]) f = f & (label[i] != label[v]);
  }
  if (!f) {
    cout << "NO" << endl;
    exit(0);
  }
  cout << "YES" << endl;
  f0r(i, m) {
    cout << label[edg[i].f];
  }
  cout << endl;
}