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
			jump.push_back(std::vector<T>((int)v.size() - (1 << j) + 1));
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
		vector<ll> v(n);
		forn(i, n) cin >> v[i];
		vector<ll> d(n-1);
		forn(i, n-1){
			d[i] = v[i+1] - v[i];
		}

		SparseTable<ll> s(d);
		int r = 0;
		int best = 1;
		forn(i, n-1){
			ckmax(r, i);
			while(r < n-1 && abs(s.query(i, r)) > 1){
				r++;
			}
			ckmax(best, r-i+1);
			// cout << i << " " << r << endl;
		}

		cout << best << "\n";
	}
}