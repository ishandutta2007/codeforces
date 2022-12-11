#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n, m;

struct Edge {
    int u, v;
    ll w;
} edges[600 * 600];



ll dp[606][606];

ll mat[606][606];

const ll LINF = 1e18 + 7;


vector<pair<int, int> > kek[606];

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < 606; ++i) {
        for (int j = 0; j < 606; ++j) {
            if (i != j) dp[i][j] = LINF; 
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--; 
        dp[edges[i].u][edges[i].v] = min(dp[edges[i].u][edges[i].v], edges[i].w);
        dp[edges[i].v][edges[i].u] = min(dp[edges[i].v][edges[i].u], edges[i].w);
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int w1, w2, l;
        cin >> w1 >> w2 >> l;
        --w1; --w2;
        kek[w1].pb(mp(w2, l));
        kek[w2].pb(mp(w1, l));
    }

    for (int v = 0; v < n; ++v) {
        for (int ne = 0; ne < n; ++ne) {
            mat[v][ne] = -1;
            for (const auto& [u, l] : kek[v]) {
                mat[v][ne] = max(mat[v][ne], l - dp[ne][u]);
            }
        }
    }


    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int ok = 0;
        for (int v = 0; v < n; ++v) {
            if (mat[v][edges[i].v] >= edges[i].w + dp[v][ edges[i].u ]) {
                ok = 1;
                break;
            }
        }
        ans += ok;
    }

    cout << ans;
}