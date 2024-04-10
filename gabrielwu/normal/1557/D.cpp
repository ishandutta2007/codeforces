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
		tree.assign(4 * n, ID);
		lazy.assign(4 * n, ID);	//Potentially operation-specific
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
	const T ID = mp(MOD, MOD);		//Null value
	void push(int i, int tl, int tr) {
		if(lazy[i] == ID) return;
		ckmin(tree[i], lazy[i]);
		if (tl != tr) {
			ckmin(lazy[2*i+1], lazy[i]);
			ckmin(lazy[2*i+2], lazy[i]);
		}
		lazy[i] = ID;
	}

	T comb(T a, T b){
		return min(a, b);
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

	int n, m;
	cin >> n >> m;
	set<int> s;
	vector<vector<pii>> v(n);
	forn(i, m){
		int x, l, r;
		cin >> x >> l >> r;
		v[x-1].pb(mp(l, r));
		s.insert(l);
		s.insert(r);
	}

	map<int, int> dict;
	int ind = 0;
	for(int x: s){
		dict[x] = ind++;
	}
	forn(i, n){
		forn(j, v[i].size()){
			v[i][j] = mp(dict[v[i][j].f], dict[v[i][j].s]);
		}
	}

	// cout <<v  << "\n";

	LazySeg<pii> st(ind);
	vector<pii> best(n);
	forn(i, n){
		best[i] = mp(i, -1);
		for(pii p: v[i]){
			pii x = st.query(p.f, p.s);
			x.f += i-1;
			ckmin(best[i], x);
		}
		pii y = mp(best[i].f - i, i);
		for(pii p: v[i]){
			st.upd(p.f, p.s, y);
		}
	}
	// cout << best << "\n";

	vector<bool> used(n);
	pii p = st.query(0, ind-1);
	int curr = p.s;
	int cnt = n;
	while(curr != -1){
		used[curr] = true;
		cnt--;
		curr = best[curr].s;
	}

	cout << cnt << "\n";
	forn(i, n){
		if(!used[i]) cout << i+1 << " ";
	}
	cout << "\n";

}