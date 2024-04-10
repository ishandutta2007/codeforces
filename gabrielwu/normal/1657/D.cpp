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


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, C;
	cin >> n >> C;

	vector<ll> c(n), d(n), h(n);
	forn(i, n ){
		cin >> c[i] >> d[i] >> h[i];
	}

	int m;
	cin >> m;
	vector<ll> monst(m);
	forn(i, m) {
		ll D, H;
		cin >> D >> H;
		monst[i] = D*H;
	}

	vector<ll> a(C+1), b(C+1);
	forn(i, n) {
		ckmax(b[c[i]], d[i]*h[i]);
	}

	for(int cost = 1; cost <= C; cost++) {
		for(int x = 1; cost*x <= C; x++) {
			ckmax(a[x*cost], b[cost]*x);
		}
	}
	for(int i=1; i<=C; i++) {
		ckmax(a[i], a[i-1]);
	}

	forn(i, m) {
		if(a[C] <= monst[i]) {
			cout << -1 << " ";
			continue;
		}
		int lo = 1, hi = C;
		while(lo < hi) {
			int mid = (lo + hi)/2;
			if(a[mid] > monst[i]) {
				hi = mid;
			} else {
				lo = mid+1;
			}
		}
		cout << lo << " ";
	}


}