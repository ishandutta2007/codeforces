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

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
template <class T> struct SegmentTree {
	int n;
	std::vector<T> seg;

	const T ID = 0;		//Null value

	T comb(T a, T b) {
		return __gcd(a, b);	//Edit operation here
	}

	SegmentTree() {}
	SegmentTree(int n_) { init(n_);	}
	void init(int _n) {
		n = _n;
		seg.assign(2 * n, ID);
	}

	void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	void add(int p, T val) {
		seg[p += n] += val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = comb(ra, seg[l++]);
			if (r & 1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};
template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<T>> jump;

	T comb(T a, T b) {
		return __gcd(a, b);	//Change operation here
	}

	int level(int x) { return 31 - __builtin_clz(x); }

	SparseTable() {}
	SparseTable(const std::vector<T>& _v) { init(_v); }
	void init(const std::vector<T>& _v) {
		v = _v;
		jump = {v};
		for (int j = 1; (1 << j) <= (int)v.size(); j++) {
			jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
			for (int i = 0; i < (int)jump[j].size(); i++) {
				jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
	
	T query(int l, int r) {
		assert(l <= r);
		int d = level(r - l + 1);
		return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
	}
};


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;

		// vector<int> v(2*n);
		// forn(i, n){
		// 	cin >> v[i];
		// 	v[i+n] = v[i];
		// }
		// SparseTable<int> st;
		// st.init(v);
		SegmentTree<int> st;
		st.init(2*n);
		forn(i, n){
			int x;
			cin >> x;
			st.upd(i, x);
			st.upd(i+n, x);
		}

		int lo = 0, hi = n-1;
		while(lo < hi){
			int mid = (lo+hi)/2;
			int bef = -1;
			bool works = true;
			forn(i, n){
				int x = st.query(i, i+mid);
				if(bef == -1) bef = x;
				else{
					works &= bef == x;
				}
			}
			if(works){
				hi = mid;
			}else{
				lo = mid+1;
			}
		}

		cout << lo << "\n";

	}
}