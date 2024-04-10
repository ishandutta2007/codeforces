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
	forn(ti, t) {
		int n;
		cin >> n;
		vector<int> v(n);
		forn(i, n) {
			cin >> v[i];
			v[i]--;
		}

		ll ans = 0;
		FenwickTree<ll> f(n);
		f.add(v[0],1);
		for(int c = 1; c<n-1; c++) {
			f.add(v[c],1);
			ll add = 0;
			for(int a=c-2; a>=0; a--) {
				add += v[a+1] - f.query(0, v[a+1]-1);
				if(v[c] > v[a]) ans += add;
			}
		}

		cout << ans << "\n";
	}
}