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
template <class T> struct FenwickTree {
	std::vector<T> fwt; int n;

	FenwickTree() {}
	FenwickTree(int n_) { init(n_);	}
	void init(int n_) { n = n_; fwt.assign(n, 0); }
	void init(std::vector<T>& a) {
		n = (int)a.size();
		fwt.assign(n, 0);
		for (int i = 0; i < (int)a.size(); i++) add(i, a[i]);
	}

	T sum(int r) {
		T ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) ret += fwt[r];
		return ret;
	}

	T query(int l, int r) { return sum(r) - sum(l - 1); }

	void add(int idx, T delta) {
		for (; idx < n; idx = idx | (idx + 1)) fwt[idx] += delta;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n, k;
		cin >> n >> k;

		vector<bool> used(2*n);
		vector<int> f(2*n, -1), b(2*n, -1);
		forn(i, k){
			int x, y;
			cin >> x >> y;
			x--; y--;
			if(x > y) swap(x, y);
			f[x] = y;
			b[y] = x;
			used[x] = true;
			used[y] = true;
		}

		vector<int> v;
		forn(i, 2*n){
			if(!used[i]) v.pb(i);
		}
		assert(v.size() == 2*n - 2*k);
		forn(i, n-k){
			f[v[i]] = v[i+n-k];
			b[v[i+n-k]] = v[i];
		}

		FenwickTree<int> fwt(2*n);
		int ans = 0;
		forn(i, 2*n){
			if(f[i] >= 0){
				fwt.add(i, 1);
			} else {
				fwt.add(b[i], -1);
				ans += fwt.query(b[i], i);
			}
		}
		cout << ans << "\n";
	}
}