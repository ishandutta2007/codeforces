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
		vector<int> a(n), b(n);
		vector<int> pos(n), p(n);
		forn(i, n){
			cin >> a[i];
			a[i]--;
			pos[a[i]] = i;
		}
		forn(i, n){
			cin >> b[i];
			b[i]--;
			p[i] = pos[b[i]];
		}

		vector<bool> c(n);
		vector<int> even, odd;
		forn(i, n) {
			if(c[i]) continue;
			int len = 0;
			int x = i;
			while(!c[x]) {
				c[x] = true;
				x = p[x];
				len++;
			}
			if(len%2 == 0) {
				even.pb(len);
			} else {
				odd.pb(len);
			}
		}

		ll ans = 0;
		ll diff = n-1;
		for(int x: even) {
			forn(i, x/2) {
				ans += diff*2;
				diff-=2;
			}
		}

		sort(odd.begin(), odd.end(), greater<int>());
		// cout << odd << "\n";

		for(int x: odd) {
			forn(i, x/2) {
				ans += diff*2;
				diff-=2;
			}
			// diff--;
		}

		// assert(diff == -1);

		cout << ans << "\n";

	}
}