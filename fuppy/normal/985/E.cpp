// kyopro.cpp : AvP[VGg |Cg`B
//

//#include "stdafx.h"


#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
const int inf = 1000000001;
const ll INF = 2e18;
const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define fio() cin.tie(0); ios::sync_with_stdio(false);



class LazySegmentTree {
public:
	int n;
	vl node, lazy;

	LazySegmentTree(vl a) {
		int _n = a.size();
		n = 1; while (n < _n) n *= 2;
		node.resize(2 * n - 1);
		lazy.resize(2 * n - 1, -2 * INF);
		for (int i = 0; i < _n; i++) node[i + n - 1] = a[i];
		for (int i = n - 2; i >= 0; i--) {
			node[i] = node[i * 2 + 1] + node[i * 2 + 2];
		}
	}

	// km[hx]s
	inline void eval(int k, int l, int r) {
		if (lazy[k] != -2 * INF) {
			node[k] = (r - l) * lazy[k];
			if (r - l > 1) {
				lazy[2 * k + 1] = lazy[k]; /////
				lazy[2 * k + 2] = lazy[k]; /////
			}
			lazy[k] = -2 * INF;
		}
	}

	// [a, b)x
	void add(int a, int b, ll x, int k, int l, int r) {
		// k m[hx]s
		eval(k, l, r);
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			lazy[k] = x;
			eval(k, l, r);
		}
		else {
			add(a, b, x, 2 * k + 1, l, (l + r) / 2);
			add(a, b, x, 2 * k + 2, (l + r) / 2, r);
			node[k] = node[2 * k + 1] + node[2 * k + 2];
		}
	}

	ll getsum(int a, int b, int k, int l, int r) {
		eval(k, l, r);
		if (b <= l || r <= a) return 0;
		if (a <= l && r <= b) return node[k];
		ll resl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
		ll resr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
		return resl + resr;
	}
};



int main() {
	ll n, k, d;
	cin >> n >> k >> d;
	vl a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(all(a));
	//DEBUG_VEC(a);
	vl dp(n + 1);
	dp[0] = 1;
	LazySegmentTree lst(dp);
	rep(i, n) {
		if (lst.getsum(i, i + 1, 0, 0, lst.n) == 0) {
			continue;
		}
		if (i + k - 1 < n && a[i + k - 1] - a[i] <= d) {
			auto itr = lower_bound(all(a), a[i] + d + 1);
			int j = itr - a.begin();
			lst.add(min(i + k, n), min(j + 1, (int)n + 1), 1, 0, 0, lst.n);
		}
	}
	if (lst.getsum(n, n + 1, 0, 0, lst.n)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}