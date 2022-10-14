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
		vector<char> v(n);
		forn(i, n) cin >> v[i];

		bool works = false;

		forn(i, n-5) {
			vector<char> u = v;
			forn(j, n) {
				if(j < i || j > i+6) {
					if(u[j] == '?') u[j] = 'z';
				} else {
					if(u[j] == '?') u[j] = "abacaba"[j-i];
				}
			}
			int cnt = 0;
			forn(i, n-6) {
				bool found = true;
				forn(j, 7) {
					if(u[i+j] != "abacaba"[j]) found = false;
				}
				if(found) cnt++;
			}
			if(cnt == 1) works = true;
			if(works) {
				cout << "YES\n";
				forn(i, n) cout << u[i];
				cout << "\n";
				break;
			}
		}
		if(!works) {
			cout << "NO\n";
		}

	}
}