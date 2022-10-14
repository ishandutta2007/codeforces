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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max

template <class T> struct SegmentTree {
	int n;
	std::vector<T> seg;

	const T ID = MOD;		//Null value

	T comb(T a, T b) {
		return min(a, b);	//Edit operation here
	}

	SegmentTree() {}
	SegmentTree(int _n) { init(_n);	}
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

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t) {
		int n, m;
		cin >> n >> m;
		vector<ll> a(n);
		forn(i, n) cin >> a[i];

		set<pii> s;
		forn(i, n) {
			if(i == 0 || a[i] < (--s.end())->s) {
				s.insert({i, a[i]});
			}
		}

		// SegmentTree<int> st(n);
		// int curr = 1;
		// forn(i, n) {
		// 	st.upd(i, a[i]);
		// 	if(i) {
		// 		if(st.query(0, i-1) > a[i]) curr++;
		// 	}
		// }

		forn(i, m) {
			int k, d;
			cin >> k >> d;
			k--;
			s.erase({k, a[k]});
			a[k] -= d;
			s.insert({k, a[k]});
			auto it = s.find({k, a[k]});
			auto bef = it;
			if(it != s.begin() && a[k] >= (--bef)->s) {
				s.erase(it);
			} else {
				bef = it;
				bef++;
				while(bef != s.end()) {
					if(bef->s < a[k]) {
						break;
					} else {
						s.erase(bef++);
					}
				}
			}
			cout << s.size() << " ";
			// if(k) curr -= (st.query(0, k-1) > a[k]);
			// st.add(k, -d);
			// if(k) curr += (st.query(0, k-1) > a[k]);

			// cout << curr << " ";
		}
		cout << "\n";
	}
}