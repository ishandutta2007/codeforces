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
		const int LG = 10;

		vector<int> p(10), pc(10);
		forn(i, 10){
			p[i] = i+1;
			pc[i] = 9 - i;
		}

		int n;
		cin >> n;
		vector<int> digs(LG);
		int x = n;
		forn(i, LG){
			digs[i] = x%10;
			x /= 10;
		}

		ll ans = 0;

		for(int b=0; b<(1<<(LG-2)); b++){
			ll ways = 1;
			x = b;
			vector<bool> carry(LG-2);
			forn(i, LG-2){
				carry[i] = x&1;
				x >>= 1;
			}
			for(int i=0; i<LG; i++){
				int want = digs[i];
				if(i > 1 && carry[i-2]) want--;
				bool wc = (i < LG-2) && carry[i];
				// cout << i << " " << want << " " << wc << "\n";
				if(want == -1){
					want = 9;
					if(wc) wc = false;
					else{
						// cout << "k";
						ways = 0;
						break;
					}
				}

				if(wc){
					ways *= pc[want];
				} else {
					ways *= p[want];
				}
			}
			// cout << carry << " " << ways << "\n";
			ans += ways;
		}

		cout << ans-2 << "\n";
	}
}