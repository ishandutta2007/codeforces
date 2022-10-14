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
		vector<bool> a(n), b(n);
		int ac = 0, bc = 0;
		forn(i, n){
			char c;
			cin >> c;
			a[i] = (c == '1');
			ac += a[i];
		}
		forn(i, n){
			char c;
			cin >> c;
			b[i] = (c == '1');
			bc += b[i];
		}

		if(ac == 0){
			if(bc == 0){
				cout << 0 << "\n";
			} else {
				cout << -1 << "\n";
			}
			continue;
		}

		int ans = MOD;
		if(ac == bc){
			int cnt = 0;
			forn(i, n){
				if(a[i] != b[i]) cnt++;
			}
			assert(cnt%2 == 0);
			ckmin(ans, cnt);
		}
		bc = n - bc;
		forn(i, n) b[i] = 1-b[i];
		if(ac == bc+1){
			int cnt = 0;
			forn(i, n){
				if(a[i] != b[i]) cnt++;
			}
			assert(cnt%2 == 1);
			ckmin(ans, cnt);
		}

		if(ans == MOD){
			ans = -1;
		}
		cout << ans << "\n";
	}
}