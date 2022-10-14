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
		int n; cin >> n;
		vector<char> s, t;
		int a = 0, b = 0, c = 0;
		int a2 = 0, b2 = 0, c2 = 0;
		forn(i, n) {
			char x; cin >> x;
			if(x == 'a') a++;
			if(x == 'b') b++;
			if(x == 'c') c++;
			s.pb(x);
		}
		forn(i, n) {
			char x; cin >> x;
			if(x == 'a') a2++;
			if(x == 'b') b2++;
			if(x == 'c') c2++;
			t.pb(x);
		}

		if(a != a2 || b != b2 || c != c2) {
			cout << "NO\n";
		} else {
			assert(s.size() == t.size());
			bool works = true;

			vector<char> sonly, tonly;
			forn(i, n) if(s[i] != 'b') sonly.pb(s[i]);
			forn(i, n) if(t[i] != 'b') tonly.pb(t[i]);
			assert(sonly.size() == a+c);

			if(sonly != tonly) {
				cout << "NO\n";
				continue;
			}

			vector<int> as(a+c+1), cs(a+c+1);
			forn(i, a+c) {
				as[i+1] = as[i] + (sonly[i] == 'a');
				cs[i+1] = cs[i] + (sonly[i] == 'c');
			}
			vector<int> b1, b2;
			int curr1 = 0, curr2 = 0;
			forn(i, n) {
				if(s[i] == 'b') b1.pb(curr1);
				else curr1++;
				if(t[i] == 'b') b2.pb(curr2);
				else curr2++;
			}
			assert(b1.size() == b && b2.size() == b);
			forn(i, b) {
				int x = b1[i], y = b2[i];
				if(x == y) continue;
				if(x < y) {
					if(as[y] - as[x] > 0) works = false;
				} else {
					if(cs[x] - cs[y] > 0) works = false;
				}
			}

			if(works) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}