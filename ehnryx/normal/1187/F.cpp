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

ll power(ll b, ll e) {
	ll r = 1;
	for(;e;e/=2){
		if(e&1) r = r*b % MOD;
		b = b*b % MOD;
	}
	return r;
}

ll inv(ll n) {
	return power(n, MOD-2);
}

const int N = 2e5+1;
ll l[N], r[N];
ll eq[N], neq[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> l[i];
	}
	for(int i=0;i<n;i++){
		cin >> r[i];
	}

	ll ans = 0;
	ll sum = 1;
	for(int i=1;i<n;i++){
		ll top = max((ll)0, min(r[i],r[i-1]) - max(l[i],l[i-1]) + 1);
		ll bot = (r[i]-l[i]+1) * (r[i-1]-l[i-1]+1) % MOD;
		eq[i] = top * inv(bot) % MOD;
		neq[i] = (1-eq[i]+MOD) % MOD;
		sum += neq[i];
		ans += neq[i] - neq[i]*neq[i] % MOD;
		if(i>1){
			ll t = max((ll)0, min(r[i],min(r[i-1],r[i-2])) - max(l[i],max(l[i-1],l[i-2])) + 1);
			ll b = (r[i]-l[i]+1) * (r[i-1]-l[i-1]+1) % MOD * (r[i-2]-l[i-2]+1) % MOD;
			ll p = (1 - eq[i] - eq[i-1] + t*inv(b) % MOD + 3*MOD) % MOD;
			ans += 2*p - 2*neq[i]*neq[i-1] % MOD;
		}
	}
	sum %= MOD;
	ans = ans%MOD + sum*sum%MOD;
	cout << (ans+MOD) % MOD << nl;

	return 0;
}