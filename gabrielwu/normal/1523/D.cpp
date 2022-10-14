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

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m, p;
	cin >> n >> m >> p;
	vector<ll> v(n);
	forn(i, n){
		forn(j, m){
			char c;
			cin >> c;
			v[i] = 2*v[i] + (c=='1');
		}
	}
	// cout << v << "\n";

	int tries = 30;
	int best = 0;
	ll ans = 0;
	forn(ti, tries){
		int ind = rand(0, n-1);
		int r = __builtin_popcountll(v[ind]);
		// cout << r << "\n";
		vector<int> occ(1LL<<r);
		forn(i, n){
			ll x = v[ind];
			int a = 0;
			forn(ri, r){
				if(x&(-x)&v[i]) a += (1LL)<<ri;
				// cout << x << " " << (x&(-x)) << " x\n";
				x -= x&(-x);
				// cout << a << "\n";
			}
			occ[a]++;
		}
		// cout << occ << "\n";

		forn(i, 1LL<<r){
			int x = i;
			while(x > 0){
				x = (x-1)&i;
				occ[x] += occ[i];
			}
		}

		forn(i, 1LL<<r){
			if(occ[i]*2 >= n){
				if(__builtin_popcount(i) > best){
					best = __builtin_popcount(i);
					int pow = 0;
					ans = 0;
					// cout << i << " " << occ[i] << " " << v[ind] << "\n";
					forn(mi, m){
						if(v[ind] & (1LL<<mi)){
							if(i & (1LL<<pow)) ans += (1LL<<mi);
							pow++;
						}
					}
				}
			}
		}
	}
	// cout << ans << "\n";

	// cout << best << "\n";
	for(int mi=m-1; mi>=0; mi--){
		cout << (bool)(ans & (1LL<<mi));
	}
	cout << "\n";
}