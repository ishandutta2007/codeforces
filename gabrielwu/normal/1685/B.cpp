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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		string s;
		cin >> s;

		int ac = 0, bc = 0;
		for(char c: s) {
			if(c == 'A') ac++;
			else if(c == 'B') bc++;
		}

		if(ac != a + c + d || bc != b + c + d) {
			cout << "NO\n";
			continue;
		}

		int both = 0;
		vector<int> ab, ba;
		vector<vector<char>> v;
		v.pb({});
		forn(i, s.size()) {
			if(i > 0 && s.at(i-1) == s.at(i)) v.pb(vector<char>(0));
			v.back().pb(s.at(i));
		}

		for(auto run: v) {
			if(run.size() < 2) continue;
			if(run.size() % 2 == 1) {
				both += run.size() / 2;
			} else {
				// both += run.size() / 2 - 1;
				if(run[0] == 'A') ab.pb(run.size() / 2 - 1);
				else ba.pb(run.size() / 2 - 1);
			}
		}

		sort(ab.begin(), ab.end());
		sort(ba.begin(), ba.end());

		for(int x: ab) {
			if(c > x) {
				c -= x+1;
			} else {
				x -= c;
				c = 0;
				d -= x;
				ckmax(d, 0);
			}
		}
		for(int x: ba) {
			if(d > x) {
				d -= x+1;
			} else {
				x -= d;
				d = 0;
				c -= x;
				ckmax(c, 0);
			}
		}

		if(c + d <= both) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}


	}
}