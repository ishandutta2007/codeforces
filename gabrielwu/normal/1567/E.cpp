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

template <class T> struct Seg {
	std::vector<T> tree;
	int n;

	Seg() {}
	Seg(int _n) { init(_n); }
	Seg(vector<T>& arr) { init(arr.size()); init(arr); }

	void init(int _n) {
		n = _n;
		tree.assign(4 * n, mp(mp(0, false), mp(0, 0)));
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
	const T ID = mp(mp(0, true), mp(0, 0));		//Null value

	T comb(T a, T b){
		return mp(mp(a.f.f + b.f.f + a.s.s * b.s.f, a.f.s && b.f.s),
			mp(a.s.f + (a.f.s ? b.s.f : 0), b.s.s + (b.f.s ? a.s.s : 0)));
	}
	// -- End operation-specific part --

	void pull(int i) {
		tree[i] = comb(tree[2*i+1], tree[2*i+2]);
	}

	void upd(int q, bool v, int i=0, int tl=0, int tr=-1) {
		if(tr == -1) tr = n-1;

		if(q < tl || tr < q) return;

		if (q == tl && tr == q) {
			if(v){
				tree[i] = mp(mp(1, true), mp(1, 1));
			} else {
				tree[i] = mp(mp(0, false), mp(0, 0));
			}
			return;
		}

		int mid = (tl + tr) / 2;
		upd(q, v, 2*i+1, tl, mid);
		upd(q, v, 2*i+2, mid+1, tr);
		pull(i);
	}

	T query(int ql, int qr, int i=0, int tl=0, int tr=-1) {
		if (tr == -1) tr = n-1;
		if (ql > tr || tl > qr) return ID;
		if (ql <= tl && tr <= qr) return tree[i];
		int mid = (tl + tr) / 2;
		return comb(query(ql, qr, 2*i+1, tl, mid), query(ql, qr, 2*i+2, mid+1, tr));
	}
};


int main(){
	cin.tie(0)->sync_with_stdio(0);

	typedef pair<pair<ll, bool>, pair<ll, ll>> C;

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	forn(i, n){
		cin >> a[i];
	}

	Seg<C> s(n-1);
	forn(i, n-1){
		if(a[i] <= a[i+1]){
			s.upd(i, true);
			// cout << s.tree << endl;
		} else {
			s.upd(i, false);
		}
	}

	// cout << s.tree << "\n";

	forn(qi, q){
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1){
			x--;
			a[x] = y;
			if(x > 0){
				if(a[x-1] <= a[x]){
					s.upd(x-1, true);
				} else {
					s.upd(x-1, false);
				}
			}
			if(x < n-1){
				if(a[x] <= a[x+1]){
					s.upd(x, true);
				} else {
					s.upd(x, false);
				}
			}
		} else {
			x--; y--;
			cout << s.query(x, y-1).f.f + y-x+1 << "\n";
		}
	}
}