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

	int t; cin >> t;
	forn(ti, t) {
		int n; cin >> n;
		vector<int> v(n);
		forn(i, n) {char c; cin >> c; v[i] = c == '1';}

		int sm = 0;
		forn(i, n) sm += v[i];

		if(sm & 1 || sm == 0) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		if(sm == n) {
			forn(i, n-1) {
				cout << 1 << " " << i+2 << "\n";
			}
		} else {
			forn(i, n) v.pb(v[i]);
			int start = -1;
			forn(i, n) {
				if(v[i] == 1 && v[i+1] == 0) {
					start = i+1;
					break;
				}
			}
			start %= n;
			assert(start >= 0);
			vector<pii> ans;
			bool getnext = false;
			for(int i=1; i<n; i++) {
				if(getnext) {
					ans.pb({start, start+i});
				} else {
					ans.pb({start+i-1, start+i});
				}
				getnext = (v[start+i] == 1);
			}

			for(pii p: ans) {
				cout << ((p.f+n)%n)+1 << " " << ((p.s+n)%n)+1 << "\n";
			}
		}
	}
}