#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
template <class T> struct LazySeg {
	std::vector<T> tree, lazy;
	int n;

	LazySeg() {}
	LazySeg(int _n) { init(_n); }
	LazySeg(vector<T>& arr) { init(arr.size()); init(arr); }

	void init(int _n) {
		n = _n;
		tree.assign(4 * n, mp(0,0));
		lazy.assign(4 * n, mp(0,0));	//Potentially operation-specific
	}

	void init(vector<T>& arr, int i=0, int tl=0, int tr=-1) {
		if(tr == -1) tr = n-1;
		if (tl == tr){
			tree[i] = arr[tl];
			return;
		}
		int mid = (tl + tr) / 2;
		init(arr, 2*i+1, tl, mid);
		init(arr, 2*i+2, mid+1, tr);
		pull(i);
	}

	// -- Begin operation-specific part --
	const T ID = mp(0,0);		//Null value
	void push(int i, int tl, int tr) {
		tree[i].f += lazy[i].f;
		if (tl != tr) {
			lazy[2*i+1].f += lazy[i].f;
			lazy[2*i+2].f += lazy[i].f;
		}
		lazy[i] = ID;
	}

	T comb(T a, T b){
		if(a.f >= b.f){
			return a;
		} else {
			return b;
		}
	}
	// -- End operation-specific part --

	void pull(int i) {
		tree[i] = comb(tree[2*i+1], tree[2*i+2]);
	}

	void upd(int ql, int qr, T v, int i=0, int tl=0, int tr=-1) {
		if(tr == -1) tr = n-1;
		push(i, tl, tr);

		if(qr < tl || tr < ql) return;
		if (ql <= tl && tr <= qr) {
			lazy[i] = v;	//Potentially operation-specific
			push(i, tl, tr);
			return;
		}

		int mid = (tl + tr) / 2;
		upd(ql, qr, v, 2*i+1, tl, mid);
		upd(ql, qr, v, 2*i+2, mid+1, tr);
		pull(i);
	}

	T query(int ql, int qr, int i=0, int tl=0, int tr=-1) {
		if (tr == -1) tr = n-1;
		push(i, tl, tr);
		if (ql > tr || tl > qr) return ID;
		if (ql <= tl && tr <= qr) return tree[i];
		int mid = (tl + tr) / 2;
		return comb(query(ql, qr, 2*i+1, tl, mid), query(ql, qr, 2*i+2, mid+1, tr));
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> adj(n);
	forn(i, n-1){
		int x, y;
		cin >> x >> y;
		x--; y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	int t = 0;
	vector<int> leaves;
	vector<int> depth(n);
	vector<int> p(n);
	vector<int> in(n), out(n);
	function<void(int, int, int)> dfs = [&](int u, int par, int d){
		p[u] = par;
		in[u] = t;
		depth[u] = d;
		if(adj[u].size() == 1 && par != -1){
			leaves.pb(u);
			t++;
		}
		for(int oth: adj[u]){
			if(oth != par) dfs(oth, u, d+1);
		}
		out[u] = t-1;
	};
	dfs(0, -1, 0);
	// cout << in << " " << out << endl;

	int l = leaves.size();
	// cout << leaves << "\n";

	if(k >= l){
		ll best = 0;
		for(ll r=l; r<=k; r++){
			ckmax(best, r*(n-r));
		}
		cout << best << "\n";
		return 0;
	}

	vector<pii> arr(l);
	vector<bool> used(n);
	forn(i, l){
		arr[i] = mp(depth[leaves[i]], i);
	}
	LazySeg<pii> seg(arr);

	int locked = 0;
	forn(i, k){
		int x = leaves[seg.query(0, l-1).s];
		// cout << x << endl;
		assert(!used[x]);
		while(x != -1 && !used[x]){
			locked++;
			seg.upd(in[x], out[x], mp(-1, 0));
			used[x] = true;
			x = p[x];
		}
	}

	// cout << "locked " << locked << "\n";

	ll best = LLONG_MAX;
	for(ll b=0; b<=n-locked; b++){
		ckmin(best, (n-b-k)*(k-b));
	}

	cout << best << "\n";


}