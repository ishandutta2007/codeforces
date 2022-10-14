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
		vector<int> v;
		string s;
		cin >> s;
		for(char c: s){
			if(c == 'A') v.pb(0);
			if(c == 'N') v.pb(1);
			if(c == 'O') v.pb(2);
			if(c == 'T') v.pb(3);
		}
		vector<int> cnt(4);
		int n = v.size();
		forn(i, n){
			cnt[v[i]]++;
		}

		function<ll(vector<int>)> cnt_inv = [&](vector<int> v){
			FenwickTree<int> fwt(n);
			ll ans = 0;
			assert(v.size() == n);
			forn(i, n){
				ans += fwt.query(v[i], n-1);
				fwt.add(v[i], 1);
			}
			return ans;
		};

		function<ll(vector<int>)> f = [&](vector<int> guess){
			vector<int> reb(n);
			vector<int> start(4);
			forn(i, 4){
				forn(j, n){
					if(guess[j] == i){
						start[i] = j;
						break;
					}
				}
			}
			forn(i, n){
				reb[i] = start[v[i]]++;
			}
			return cnt_inv(reb);
		};

		vector<int> p{0,1,2,3};
		vector<int> bp;
		ll best = -1;
		forn(perm, 24){
			vector<int> a(n);
			int ind = 0;
			forn(i, 4){
				forn(j, cnt[p[i]]) a[ind++] = p[i];
			}
			ll val = f(a);
			if(ckmax(best, val)){
				bp = a;
			}
			// cout << p << " " << val << endl;
			next_permutation(p.begin(), p.end());
		}

		vector<char> trans{'A','N','O','T'};
		forn(i, n){
			cout << trans[bp[i]];
		}cout << "\n";
	}
}