#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using base = complex<double>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define M 1000000007
#define M2 998244353
#define ll long long
#define pll pair<long, long>
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPI(i, a, b) for (ll i = b - 1; i >= a; i--)
#define ff first
#define ss second
#define pb push_back
#define db pop_back
#define mp make_pair
#define mt make_tuple
#define g(a, b) get<a>(b)
#define INF (ll)1e18 + 100
#define vl vector<ll>
#define vi vector<int>
#define vll vector<pair<ll, ll>>
#define vii vector<pair<int, int>>
#define all(v) v.begin(), v.end()
#define bset(a, p) ((a) | (1ll << (p)))
#define bchk(a, p) ((a) & (1ll << (p)))
#define bxor(a, p) ((a) ^ (1ll << (p)));
#define brem(a, p) (bchk(a, p) ? (bxor(a, p)) : (a))
#define INT_SIZE 32
/*SOME BITMASK KNOWLEDGE
1)x & (x - 1):sets the last one bit of x to zero
power of two exactly when x & (x  1) = 0.
2)x & -x:sets all the one bits to zero, except last one bit
3)x | (x - 1):inverts all the bits after the last one bit*/
 
#define o_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define o_setpll tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
ll powM(ll x, ll y, ll m)
{
	if (x == 0) {
		return 1;
	}
	ll ans = 1, r = 1;
	if(x >= m){
		x = x%m;
	}
	while (r > 0 && r <= y) {
		if (r & y) {
			ans *= x;
			if(ans >= m){
				ans = ans%m;
			}

		}
		r <<= 1;
		x *= x;
		if(x >= m){
			x = x%m;
		}
	}
	return ans;
}

ll modI(ll a, ll m)
{
	ll m0 = m, y = 0, x = 1;
	if (m == 1)
		return 0;
	while (a > 1) {
		ll q = a / m;
		ll t = m;
		m = a % m;
		a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0)
		x += m0;
	return x;
}
ll extended(ll a, ll b, ll &x, ll &y)
{
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll d = extended(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
ll lcm(ll x, ll y) {
	ll gc = __gcd(x, y);
	x /= gc;
	if ((ll)(8e18) / y <= x) {
		return 8e18;
	}
	return (x * y);
}
ll power(ll x, ll y){
	if(y < 0){
		return 0;
	}
	ll ans = 1;
	REP(i,1,y+1){
		ans *= x;
	}
	return ans;
}
void setIO(string name = "") { // name is nonempty for USACO file I/O
    // alternatively, cin.tie(0)->sync_with_stdio(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}
void solve(){
	ll n;
	cin>>n;
	vll v(n);
	o_setpll s;
	o_setpll e;
	REP(i,0,n){
		cin>>v[i].ff>>v[i].ss;
	}
	sort(all(v));
	REP(i,0,n){
		s.insert({v[i].ff,i});
	}
	ll ans = 1;
	REP(i,0,n){
	    auto it = s.lower_bound({v[i].ff,i});
		s.erase(it);
		// cout<<s.size()<<" ";
		ll cnt = 0;
		if(i < n-1)
		{cnt+= (ll)s.order_of_key({v[i].ss+1,-INF});}
		// cout<<cnt<<" ";
		if(i > 0){cnt += (ll)e.order_of_key({-v[i].ff+1,-INF});} 
		// cout<<cnt<<"\n";
		ans = max(cnt+1,ans);
		e.insert({-v[i].ss,i});
	}
	cout<<n-ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	setIO("hello");
#endif
	ll ntc;
    cin >> ntc;
    // ntc = 1;
    REP(tc, 1, ntc + 1)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
}