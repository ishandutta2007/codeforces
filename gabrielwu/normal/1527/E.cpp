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
		tree.assign(4 * n, 0);
		lazy.assign(4 * n, 0);	//Potentially operation-specific
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
	const T ID = 0;		//Null value
	void push(int i, int tl, int tr) {
		tree[i] += lazy[i];
		if (tl != tr) {
			lazy[2*i+1] += lazy[i];
			lazy[2*i+2] += lazy[i];
		}
		lazy[i] = 0;
	}

	T comb(T a, T b){
		return max(a, b);
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
	vector<int> a(n);
	forn(i, n){
		cin >> a[i];
		a[i]--;
	}

	vector<int> first(n, MOD), last(n, -1), bef(n, -1);
	vector<LazySeg<int>> dp(k, LazySeg<int>(n));

	forn(i, n){
		ckmin(first[a[i]], i);
		ckmax(last[a[i]], i);
		if(bef[a[i]] != -1){
			for(int j=1; j<k; j++){
				dp[j].upd(bef[a[i]], i-1, i-bef[a[i]]);
			}
		}
		bef[a[i]] = i;

		for(int j=k-1; j>=1; j--){
			dp[j].upd(i, i, dp[j-1].query(0, n-1));
		}
	}

	ll ans = 0;
	forn(i, n){
		if(first[i] != MOD){
			ans += last[i] - first[i];
		}
	}
	// cout << "bef " << ans << "\n";
	ans -= dp[k-1].query(0, n-1);

	cout << ans << "\n";

}