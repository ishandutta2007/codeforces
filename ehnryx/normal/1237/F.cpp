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
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3600+1;
const int M = N/2+1;
int row[N], col[N];
ll rdp[N][M], cdp[N][M];
ll ncr[N][N], fact[N];

void update(ll& a, ll& b) {
	if(b!=-1) {
		if(a==-1) a = b;
		else a = (a+b)%MOD;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	for(int i=0;i<N;i++) {
		ncr[i][0] = ncr[i][i] = 1;
		for(int j=1;j<i;j++) {
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
		}
	}
	fact[0] = 1;
	for(int i=1;i<N;i++) {
		fact[i] = fact[i-1] * i % MOD;
	}

	int n,m,k;
	cin>>n>>m>>k;
	int rsum = n;
	int csum = m;
	for(int i=0;i<k;i++) {
		int a,b,x,y;
		cin>>a>>b>>x>>y;
		row[a] = col[b] = 1;
		row[x] = col[y] = 1;
		rsum -= 1 + (a!=x);
		csum -= 1 + (b!=y);
	}
	row[0] = col[0] = 1;
	//cerr<<"sum: "<<rsum<<" "<<csum<<nl;
	//cerr<<"row: "; for(int i=1;i<=n;i++) {
		//cerr<<row[i]; }
	//cerr<<nl;
	//cerr<<"col: "; for(int i=1;i<=m;i++) {
		//cerr<<col[i]; }
	//cerr<<nl;

	memset(rdp,-1,sizeof rdp);
	rdp[0][0] = 1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<M;j++) {
			update(rdp[i][j], rdp[i-1][j]);
			if(j>0 && !row[i] && !row[i-1]) {
				update(rdp[i][j], rdp[i-2][j-1]);
			}
		}
	}

	memset(cdp,-1,sizeof cdp);
	cdp[0][0] = 1;
	for(int i=1;i<=m;i++) {
		for(int j=0;j<M;j++) {
			update(cdp[i][j], cdp[i-1][j]);
			if(j>0 && !col[i] && !col[i-1]) {
				update(cdp[i][j], cdp[i-2][j-1]);
			}
		}
	}

	ll ans = 0;
	for(int r=0;r<M;r++) {
		for(int c=0;c<M;c++) {
			if(rdp[n][r] == -1 || cdp[m][c] == -1) continue;
			if(r*2 + c <= rsum && c*2 + r <= csum) {
				ll cur = rdp[n][r] * cdp[m][c] % MOD;
				cur = cur * ncr[rsum-2*r][c] % MOD;
				cur = cur * ncr[csum-2*c][r] % MOD;
				cur = cur * fact[r] % MOD;
				cur = cur * fact[c] % MOD;
				ans += cur;
			}
		}
	}
	cout<<ans%MOD<<nl;

	return 0;
}