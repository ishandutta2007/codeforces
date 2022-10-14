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
template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<T>> jump;

	T comb(T a, T b) {
		if(min(a, b) == 0) return max(a, b);
		if(a == b) return a;
		return 100;
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

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	forn(i, n){
		char c;
		cin >> c;
		if(c != '?') v[i] = c - 'a' + 1;
	}
	SparseTable st(v);
	int lo = 1, hi = n/k + 1;
	while(lo < hi){
		int mid = (lo+hi)/2;

		vector<vector<int>> jump(k, vector<int>(n));
		for(int i=n-1; i>=0; i--){
			int res = 100;
			if(i < n-mid+1){
				res = st.query(i, i+mid-1);
			}
			forn(j, k){
				if(res == 0 || res == j+1) jump[j][i] = i+mid;
				else jump[j][i] = (i < n-1 ? jump[j][i+1] : MOD);
			}
		}

		vector<int> dp(1 << k, MOD);
		dp[0] = 0;
		for(int i=1; i<(1<<k); i++){
			for(int j=0; j<k; j++){
				if(i & (1<<j)){
					dp[i] = min(dp[i], dp[i-(1<<j)] >= n ? MOD : jump[j][dp[i-(1<<j)]]);
				}
			}
		}
		if(dp[(1<<k)-1] <= n){
			lo = mid+1;
		}else{
			hi = mid;
		}
	}

	cout << lo-1 << "\n";
}