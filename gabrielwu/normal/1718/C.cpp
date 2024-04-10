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

	// -- Sieve start --
	const int MAX_PRIME = 300005;
	vector<int> sieve(MAX_PRIME);	// sieve[i] := smallest factor of i greater than 1.
	vector<int> primes;				// list of primes up to MAX_PRIME
	
	for(int i=2; i<MAX_PRIME; i++) {
			if(!sieve[i]) {
					primes.push_back(i);
					for(int x=i; x<MAX_PRIME; x+=i) {
							if(sieve[x] == 0) {
									sieve[x] = i;
							}
					}
			}
	}
	// -- Sieve end --

	int t; cin >> t;
	forn(ti, t) {
		ll n, q;
		cin >> n >> q;

		vector<ll> fs;
		for(int x: primes) {
			if(n%x == 0) fs.pb(n/x);
			if(x >= n) {
				break;
			}
		}
		int k = fs.size();

		vector<vector<ll>> sm(k);
		forn(i, k) {
			sm[i] = vector<ll>(fs[i]);
		}

		vector<ll> v(n);
		forn(i, n) {
			cin >> v[i];
			forn(j, k) {
				sm[j][i%fs[j]] += v[i];
			}
		}

		// cout << sm << endl;

		multiset<ll> ms;
		forn(i, k) {
			forn(j, fs[i]) {
				ms.insert(sm[i][j] * fs[i]);
			}
		}

		// cout << "HERE"<< endl;

		cout << *(--ms.end()) << "\n";
		forn(qi, q) {
			int p; ll x;
			cin >> p >> x;
			p--;
			x -= v[p];
			v[p] += x;
			forn(j, k) {
				ms.erase(ms.find(sm[j][p%fs[j]] * fs[j]));
				sm[j][p%fs[j]] += x;
				ms.insert(sm[j][p%fs[j]] * fs[j]);
			}
			cout << *(--ms.end()) << "\n";
		}
	}
	
}