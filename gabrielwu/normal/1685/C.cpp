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

	int t;
	cin >> t;

	forn(ti, t) {
		int n;
		cin >> n;
		vector<int> v(2*n);
		forn(i, 2*n) {
			char c;
			cin >> c;
			v[i] = c == '(' ? 1 : -1;
		}

		int curr = 0;
		bool everneg = false;
		forn(i, 2*n) {
			curr += v[i];
			everneg |= curr < 0;
		}

		if(!everneg) {
			cout << 0 << "\n";
			continue;
		}

		curr = 0;
		pii best = {0, -1};
		forn(i, 2*n) {
			curr += v[i];
			if(curr > best.f) best = {curr, i};
			if(curr < 0) break;
		}

		curr = 0;
		pii bbest = {0, 2*n};
		for(int i=2*n-1; i>=0; i--) {
			curr -= v[i];
			if(curr > bbest.f) bbest = {curr, i};
			if(curr < 0) break;
		}

		vector<int> u = v;
		// cout << best << " " << bbest << "\n";
		assert(best.s < bbest.s);
		reverse(u.begin() + best.s + 1, u.begin() + bbest.s);

		// cout << u << "\n";

		curr = 0;
		everneg = false;
		forn(i, 2*n) {
			curr += u[i];
			everneg |= curr < 0;
		}

		if(!everneg) {
			cout << 1 << "\n";
			cout << 2+best.s << " " << bbest.s << "\n";
			continue;
		}

		//all time highest
		curr = 0;
		best = {0, -1};
		forn(i, 2*n) {
			curr += v[i];
			if(curr > best.f) best = {curr, i};
		}

		assert(best.s+2 <= 2*n);

		cout << 2 << "\n";
		cout << 1 << " " << best.s+1 << "\n";
		cout << best.s+2 << " " << 2*n << "\n";
	}
}