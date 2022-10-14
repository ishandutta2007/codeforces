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
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;

		FenwickTree<int> fwt(n);
		forn(i, n){
			fwt.add(i, 1);
		}

		vector<vector<int>> inds(26);
		for(int i=n-1; i>=0; i--){
			inds[s.at(i) - 'a'].pb(i);
		}

		ll best = LLONG_MAX;
		ll curr = 0;
		forn(fr, n){
			ll closest = -1;
			forn(i, t.at(fr)-'a'){
				if(inds[i].size()){
					if(closest == -1) closest = i;
					else {
						if(inds[closest].back() > inds[i].back()){
							closest = i;
						}
					}
				}
			}
			// cout << "c " << closest << "\n";
			if(closest != -1){
				int moves = (inds[closest].back() > 0 ? fwt.sum(inds[closest].back()-1) : 0);
				// cout << curr << " " << moves << "\n";
				ckmin(best, curr + moves);
				// cout << best << " best\n";
			}

			int x = t.at(fr) - 'a';
			if(inds[x].empty()) break;
			curr += (inds[x].back() > 0 ? fwt.sum(inds[x].back()-1) : 0);
			fwt.add(inds[x].back(), -1);
			inds[x].pop_back();
		}

		if(best == LLONG_MAX) best = -1;
		cout << best << "\n";
	}
}