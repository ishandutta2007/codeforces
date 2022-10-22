#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1<<18;
const int S = 93;
vector<int> adj[N];
int par[N], sz[N], pos[N], jump[N], child[N];
ll val[N];
bool big[N];

int id = 0;
void build(int u, int p, int pre, int ch) {
	par[u] = p;
	child[u] = (ch ? ch : u);
	jump[u] = pre;
	big[u] = (adj[u].size() > S);

	pos[u] = id++;
	sz[u] = 1;
	for(int v:adj[u]) {
		if(v==p) continue;
		if(big[u]) {
			build(v, u, u, 0);
		} else {
			build(v, u, pre, child[u]);
		}
		sz[u] += sz[v];
	}
}

ll st[2*N];
void update(int l, int r, ll v) {
	for(l+=N,r+=N; l<r; l/=2,r/=2) {
		if(l&1) { st[l] = (st[l] + v) % MOD; l++; }
		if(r&1) { --r; st[r] = (st[r] + v) % MOD; }
	}
}
ll query(int i) {
	ll res = st[i+=N];
	for(i/=2;i;i/=2) {
		res = (res + st[i]) % MOD;
	}
	res %= MOD;
	return res;
}

/*
#define DEBUG
ld stf[2*N];
void updatef(int l, int r, ld v) {
	for(l+=N,r+=N; l<r; l/=2,r/=2) {
		if(l&1) { stf[l] = (stf[l] + v) ; l++; }
		if(r&1) { --r; stf[r] = (stf[r] + v) ; }
	}
}
ld queryf(int i) {
	ld res = stf[i+=N];
	for(i/=2;i;i/=2) {
		res += stf[i];
	}
	return res;
}
*/

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(1, 0, 0, 0);
	assert(id==n);

	ll inv = 1;
	ll base = n;
	for(int e=MOD-2;e;e/=2) {
		if(e&1) inv = inv*base % MOD;
		base = base*base % MOD;
	}
	assert(inv*n % MOD == 1);

	for(int i=0;i<m;i++) {
		int t;
		cin>>t;
		if(t == 1) {
			int a,b;
			cin>>a>>b;
			ll all = sz[a] * inv % MOD * b % MOD;
			update(pos[a], pos[a]+1, b);
			update(0, n, all);
			update(pos[a], pos[a]+sz[a], -all);

#ifdef DEBUG
			ld allf = sz[a]/(ld)n * b;
			updatef(pos[a], pos[a]+1, b);
			updatef(0, n, allf);
			updatef(pos[a],pos[a]+sz[a], -allf);
#endif

			if(big[a]) {
				val[a] = (val[a] + b) % MOD;
			} else {
				for(int c:adj[a]) {
					if(c == par[a]) continue;
					ll down = (n-sz[c]) * inv % MOD;
					update(pos[c], pos[c]+sz[c], down*b % MOD);

#ifdef DEBUG
					ld downf = (n-sz[c])/(ld)n;
					updatef(pos[c], pos[c]+sz[c], downf*b);
#endif
				}
			}
		}

		else {
			int a;
			cin>>a;
			ll res = query(pos[a]);
			for(int u=jump[a], c=child[a]; u!=0; u=jump[u]) {
				//cerr<<" JUMP "<<u<<" w/ child "<<c<<nl;
				assert(par[c] == u);
				res += (n-sz[c]) * inv % MOD * val[u] % MOD;
				c = child[u];
			}
			res = (res%MOD + MOD) % MOD;
			cout<<res<<nl;

#ifdef DEBUG
			ld resf = queryf(pos[a]);
			//cerr<<"before: "<<resf<<nl;
			for(int u=jump[a], c=child[a]; u!=0; u=jump[u]) {
				assert(par[c] == u);
				resf += (ld) (n-sz[c]) / n  * val[u] ;
				c = child[u];
			}
			cout<<resf<<nl;
#endif
		}
	}

	return 0;
}