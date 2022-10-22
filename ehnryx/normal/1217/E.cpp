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

struct SegTree {
	static const int N = 1<<18;
	int st[2*N], rmq[2*N];
	SegTree() {
		fill(st, st+2*N, 2*INF);
		fill(rmq, rmq+2*N, INF);
	}
	void pull(int i) {
		st[i] = min(st[2*i], st[2*i+1]);
		if(rmq[2*i] < INF && rmq[2*i+1] < INF) {
			st[i] = min(st[i], rmq[2*i] + rmq[2*i+1]);
		}
		rmq[i] = min(rmq[2*i], rmq[2*i+1]);
	}
	void insert(int i, int v) {
		rmq[i+=N] = v;
		for(i/=2;i;i/=2) {
			pull(i);
		}
	}
	int query(int l, int r) {
		int minv, second;
		minv = second = INF;
		int res = 2*INF;
		for(l+=N, r+=N+1; l<r; l/=2, r/=2) {
			if(l&1) {
				res = min(res, st[l]);
				if(rmq[l] < minv) {
					second = minv; minv = rmq[l];
				} else if(rmq[l] < second) {
					second = rmq[l];
				}
				l++;
			}
			if(r&1) {
				--r;
				res = min(res, st[r]);
				if(rmq[r] < minv) {
					second = minv; minv = rmq[r];
				} else if(rmq[r] < second) {
					second = rmq[r];
				}
			}
		}
		//cerr<<"query got ms "<<minv<<" "<<second<<nl;
		if(minv < INF && second < INF) {
			res = min(res, minv+second);
		}
		return res;
	}
};

const int L = 10;
SegTree st[L];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; i++) {
		int val, v;
		cin >> v;
		val = v;
		//cerr<<"@ "<<i<<nl;
		for(int j=0; j<L; j++) {
			//cerr<<"insert "<<(v%10 ? val : INF)<<" in st "<<j<<nl;
			st[j].insert(i, (v%10 ? val : INF));
			v /= 10;
		}
	}

	for(int i=0; i<m; i++) {
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1) {
			int val = b;
			//cerr<<"update "<<a<<nl;
			for(int j=0; j<L; j++) {
				//cerr<<"insert "<<(b%10 ? val : INF)<<" in st "<<j<<nl;
				st[j].insert(a, (b%10 ? val : INF));
				b /= 10;
			}
		} else {
			int res = 2*INF;
			for(int j=0; j<L; j++) {
				res = min(res, st[j].query(a,b));
			}
			if(res == 2*INF) cout << -1 << nl;
			else cout << res << nl;
		}
	}

	return 0;
}