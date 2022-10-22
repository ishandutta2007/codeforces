#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9+7;

ll power(ll b, int e) {
  ll res = 1;
  for ( ; e>0; e/=2) {
    if (e&1) res = res*b % MOD;
    b = b*b % MOD;
  }
  return res;
}

struct Edge {
  int id, t;
};

const int N = 1e5+1;
vector<Edge> adj[N];
bool vis[N];

int bfs(int s) {
  if (vis[s]) return 0;
  vis[s] = true;
  int res = 1;
  for (const Edge& e : adj[s]) {
    if (e.t == 0) {
      res += bfs(e.id);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  for (int i=1; i<n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }

  ll ans = power(n,k);
	for (int i=1; i<=n; i++) {
		ans -= power(bfs(i), k);
  }
  cout << (ans%MOD + MOD) % MOD << nl;

  return 0;
}