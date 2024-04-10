#include "bits/stdc++.h"

using namespace std;

#define fori(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define ford(i, a, b) for(int i = (int) (a); i >= (int) (b); --i)
#define forIT(it, begin, end) for(__typeof(end) it = (begin) + ((begin) > (end)); it != (end) - ((begin) > (end)); it += 1 - 2 * ((begin) > (end)))

#define fi first
#define se second
#define b_e(x) begin(x), end(x)
#define ii pair<int, int>
#define vi vector<int> 
#define vvi vector<vi>

#define pb push_back
#define pf push_front
#define eb emplace_back
#define em emplace
#define ob pop_back
#define om pop
#define of pop_front

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define sp ' '

void solve();

int32_t main() {
// freopen("test.inp","r",stdin);
// freopen("test.out","w",stdout);
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int test_num = 1;
   fori(test, 1, test_num) {
      solve();
   }
   return 0;
}

#define ld long double
#define int long long
const ld pi = 4 * atan(1.0), eps = 1e-9;
const int maxn = 3e5 + 5, inf = INT_MAX / 2ll;
int n; 
int h[maxn]; 
vi g[maxn]; 
int light[maxn]; 
int vs[maxn]; 
int par[maxn]; 
int ans = 0; 
void dfs(int u, int p) { 
	for(int v: g[u]) { 
		if(v - p) { 
			par[v] = u; 
			dfs(v, u);
		}
	}
}
void climb(int i) { 
	int ti = i; 
	while(!vs[i]) { 
		vs[i] = 1; 
		i = par[i]; 
	}
	if(light[i]) { 
		light[i]--;
		light[ti]++; 
	}
	else light[ti]++, ans += h[ti]; 
}
void solve() {
	cin >> n; 
	fori(i, 1, n) cin >> h[i]; 
	fori(i, 1, n - 1) { 
		int u, v; cin >> u >> v; 
		g[u].eb(v); 
		g[v].eb(u); 
	}
	int mx = *max_element(h + 1, h + n + 1); 
	int root; fori(i, 1, n) if(h[i] == mx) root = i; 
	light[root] += 2; ans += 2 * h[root]; vs[root] = 1; 
	vector<int> ord; fori(i,1, n) if(i != root) ord.eb(i); 
	sort(b_e(ord), [] (int x, int y) { return h[x] > h[y]; }); 
	dfs(root, root); 
	for(int i: ord) { 
		if(!vs[i]) { 
			climb(i); 
		}
	}
	cout << ans; 
}