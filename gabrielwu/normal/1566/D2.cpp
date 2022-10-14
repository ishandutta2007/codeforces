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
		int n, m;
		cin >> n >> m;

		vector<int> v(m*n);
		vector<int> a(m*n);
		forn(i, m*n){
			cin >> v[i];
			a[i] = v[i];
		}

		map<int, int> x, y, midx, top, topx, bot;
		map<int, bool> span;

		sort(v.begin(), v.end());
		
		forn(i, n*m){
			if(i == 0 || v[i] > v[i-1]){
				x[v[i]] = i;
			}
			if(i == n*m-1 || v[i] < v[i+1]){
				y[v[i]] = i;
			}
		}

		for(pii p: x){
			int val = p.f;
			if(y[val]/m == x[val]/m){
				span[val] = false;
				top[val] = y[val]/m;
				topx[val] = y[val]%m;
			} else {
				span[val] = true;
				top[val] = x[val]/m;
				bot[val] = y[val]/m;
				midx[val] = m*(y[val]/m - x[val]/m - 1);
				topx[val] = m - x[val]%m;
				// cout << val << " " << top[val] << " " << bot[val] << " " << midx[val] << " " << topx[val] << "\n";
			}
		}

		vector<FenwickTree<int>> fwt(n, FenwickTree<int>(m));
		ll ans = 0;
		forn(i, n*m){
			if(span[a[i]]){
				if(topx[a[i]]){
					topx[a[i]]--;
					ans += fwt[top[a[i]]].query(0, m-1);
				} else if(midx[a[i]]){
					midx[a[i]]--;
				} else {
					fwt[bot[a[i]]].add(0, 1);
				}
			} else {
				ans += fwt[top[a[i]]].query(0, topx[a[i]]);
				fwt[top[a[i]]].add(topx[a[i]], 1);
				topx[a[i]]--;
			}
		}
		cout << ans << "\n";
	}
}