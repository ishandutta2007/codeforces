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
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 40;
bool adj[N][N];

int comps;
vector<int> dsu(N,-1);
int find(int i) {
	if(dsu[i] == -1) return i;
	return dsu[i] = find(dsu[i]);
}
void link(int i, int j) {
	if (find(i)!=find(j)) {
		dsu[find(i)] = find(j);
	}
}

ll solve012(int n) {
	return 1LL<<n;
}

ll naive_iset(int n) {
	int cnt = 0;
	for(int bm=0;bm<1<<n;bm++) {
		bool ok = true;
		for(int i=0;i<n&&ok;i++) {
			if(!(bm&1<<i)) continue;
			for(int j=0;j<i&&ok;j++) {
				if(!(bm&1<<j)) continue;
				if(adj[i][j]) ok = false;
			}
		}
		cnt += ok;
	}
	return cnt;
}

ll solve01(int n) {
	if(n<=20) {
		return naive_iset(n);
	}

	vector<int> cnt(1<<20);
	for(int bm=0;bm<1<<20;bm++) {
		bool ok = true;
		for(int i=0;i<20&&ok;i++) {
			if(!(bm&1<<i)) continue;
			for(int j=0;j<i&&ok;j++) {
				if(!(bm&1<<j)) continue;
				if(adj[i][j]) ok = false;
			}
		}
		cnt[bm] = ok;
	}
	for(int i=0;i<20;i++) {
		for(int bm=0;bm<1<<20;bm++) {
			if(bm&1<<i) cnt[bm] += cnt[bm^1<<i];
		}
	}

	int m = n-20;
	ll ans = 0;
	for(int bm=0;bm<1<<m;bm++) {
		bool bad = false;
		for(int i=0;i<m&&!bad;i++) {
			if(!(bm&1<<i)) continue;
			for(int j=0;j<i&&!bad;j++) {
				if(!(bm&1<<j)) continue;
				if(adj[i+20][j+20]) bad = true;
			}
		}
		if(bad) continue;

		int om = 0;
		for(int i=0;i<20;i++) {
			bool ok = true;
			for(int j=0;j<m&&ok;j++) {
				if(!(bm&1<<j)) continue;
				if(adj[i][j+20]) ok = false;
			}
			if(ok) om |= 1<<i;
		}
		ans += cnt[om];
	}
	return ans;
}

ll solve02(int n) {
	return 1LL<<comps;
}

ll solve0(int n) {
	int iso = 0;
	for(int i=0;i<n;i++) {
		int deg = 0;
		for(int j=0;j<n;j++) {
			deg += adj[i][j];
		}
		iso += (deg == 0);
	}
	return 1LL<<iso;
}

ll solve1(int n) {
	int dist[n][n];
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(adj[i][j]) dist[i][j] = 1;
			else if(i==j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for(int k=0;k<n;k++) {
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			for(int k=0;k<n;k++) {
				if(dist[i][j]==INF || dist[j][k]==INF) continue;
				if((dist[i][j]+dist[j][k]+dist[k][i]) % 2) {
					return 0;
				}
			}
		}
	}
	return 1LL<<comps;
}

ll solve_(int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(adj[i][j]) return 0;
		}
	}
	return 1LL<<n;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n,m;
	cin >> n >> m;
	for (int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		--a; --b;
		adj[a][b] = adj[b][a] = true;
		link(a,b);
	}

	comps = 0;
	for(int i=0;i<n;i++) {
		if(find(i) == i) {
			comps++;
		}
	}

	ll ans = solve012(n);
	ans -= 2*solve01(n) + solve02(n);
	ans += 2*solve0(n) + solve1(n);
	ans -= solve_(n);
	cout << ans << nl;

	return 0;
}