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


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	forn(ti, t){
		int n;
		cin >> n;
		vector<char> v(n-1);
		forn(i, n-1) cin >> v[i];
		vector<ll> a(n), b(n);
		ll ac = 0, bc = 0;
		set<ll> as, bs;
		for(int i=1; i<n; i++){
			if(v[i-1] == '>') {
				ac -= n;
				bc --;
			} else {
				ac++;
				bc += n;
			}
			a[i] = ac;
			b[i] = bc;
		}

		for(ll x: a) {
			as.insert(x);
		}
		for(ll x: b) {
			bs.insert(x);
		}

		map<ll, int> am, bm;
		int ind = 1;
		for(ll x: as) {
			am[x] = ind++;
		}
		ind = 1;
		for(ll x: bs) {
			bm[x] = ind++;
		}

		forn(i, n) {
			cout << am[a[i]] << " ";
		} cout << "\n";
		forn(i, n) {
			cout << bm[b[i]] << " ";
		} cout << "\n";


	}
}