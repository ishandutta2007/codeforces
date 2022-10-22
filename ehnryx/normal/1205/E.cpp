#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+1;

////////////////////////////////////////////////////////////////////////
// Linear Time Sieve for Multiplicative Functions -- O(n) (UNTESTED)
// f[n] stores the multiplicative function f(n)
// e[n] stores exp_p(n) where p is the smallest prime divisor of n
// Example with Euler's totient function
//
// USAGE:
//  1. set the commented lines to the correct multiplicative function
//  2. Sieve::run()
//  3. ???
//  4. profit
//*!
namespace Sieve {
    vector<int> primes;
    bool composite[N];
    int f[N], e[N];
    void run() {
        memset(composite, 0, sizeof composite);
        f[1] = 1; // input f(1)
        for (int i = 2; i < N; i++) {
            if (!composite[i]) {
                primes.push_back(i);
                f[i] = -1; // input f(i) for prime i
                e[i] = 1;
            }
            for (int j : primes) {
                int v = i*j;
                if (v >= N) break;
                composite[v] = true;
                if (i % j == 0) {
                    // we may need f(ij) = f(i/j^e[i]) f(j^(e[i]+1))
                    f[v] = 0; // calc f(ij) when j divides i
                    e[v] = e[i] + 1;
                    break;
                } else {
                    f[v] = f[i] * f[j]; // calc f(ij) when gcd(i,j)=1
                    e[v] = 1;
                }
            }
        }
    }
}
//*/

////////////////////////////////////////////////////////////////////////
// Mobius Function Properties
//  0. multiplicative with mu(1) = 1 and mu(p^k) = -1 if k=0 else 0
//  1. sum_{d|n} mu(d) = 1 if m=1 else 0
//  2. #{x in [1,a] : gcd(b,x)=1} = sum_{d|b} mu(d) floor(a/d)

vector<int> divisors[N];

int count(int s, int n) {
	int res = 0;
	for(int i:divisors[s]) {
		res += Sieve::f[i]*(n/i);
	}
	assert(res>=0);
	return res;
}

ll power(ll n, ll e) {
	ll r = 1;
	for(e+=MOD-1;e;e/=2) {
		if(e&1) r=r*n%MOD;
		n=n*n%MOD;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	Sieve::run();
	for(int i=1;i<N;i++) {
		for(int j=i;j<N;j+=i) {
			divisors[j].push_back(i);
		}
	}

	int n,k;
	cin>>n>>k;

	ll ans = 0;
	// count pairs (g,s) where s=i+j for i,j in [1,n-1] where g=gcd(i,j)
	for(int g=1;g<n;g++) {
		for(int s=2*g;s<2*n;s+=g) {
			int sum=s/g;
			// i+j=s --> 1<=i<=n-1, 1<=s-i<=n-1 --> max(1,s-n+1) <= i <= min(n-1,s-1)
			// then we want x where max(1, sum-(n-1)/g) <= x <= min((n-1)/g, sum-1)
			int lb = max(1, sum-(n-1)/g);
			int rb = min((n-1)/g, sum-1);
			if(lb <= rb) {
				int cur = count(sum,rb) - count(sum,lb-1);
				assert(cur>=0);
				ans += cur * power(k, max(s-n,g)-n) % MOD;
			}
		}
	}
	cout<<ans%MOD<<nl;

	return 0;
}