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

	// -- Primes start --
	const int MAX_PRIME = 1000005;
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
	// -- Primes end --
	
	function<vector<ll>(ll)> pfacs = [&](ll x) {
		/* Returns the prime factors of x, in increasing order. O(sqrt(x)/log(x))
			If x < MAX_PRIME, it's faster to just use sieve[x]. */
		assert(x > 0 && x < (ll) MAX_PRIME*MAX_PRIME);
		vector<ll> v;
		int i = 0;
		while(x > 1 && (ll) primes[i]*primes[i] <= x) {
		  if(x % primes[i] == 0) {
		    v.push_back(primes[i]);
		    x /= primes[i];
		  } else i++;
		}
		if(x > 1) v.push_back(x);
		return v;
	};
	

	cin.tie(0)->sync_with_stdio(0);
	// cout << prime << endl;
	int t;
	cin >> t;
	forn(ti, t){
		ll a, b, k;
		cin >> a >> b >> k;
		if(k == 1){
			if(a == b){
				cout << "NO\n";
				continue;
			}
			if(a%b == 0 || b%a == 0){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
			continue;
		}
		int A = pfacs(a).size(), B = pfacs(b).size();
		if(A + B >= k){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}

	}
}