//I would have implemented the segtree
//if this problem didn't made be bored out of my mind
//anyway, easiest 2600 of my life

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pci pair <char, int>
#define pld pair <ld, ld>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define cd complex <double>
#define PI 3.14159265358979
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 1;
tree <ll, null_type, less_equal <ll>, rb_tree_tag, tree_order_statistics_node_update> checkpoints;
ll cur = 0;
ll query(ll val){
	return cur + val - checkpoints.order_of_key(val + 1);
}
ll lowest(ll val){
	ll ans = -1;
	for (ll bit = 30; bit >= 0; bit--){
		if (query(ans + (1LL << bit)) < val) ans += (1LL << bit);
	}
	ans++;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	ll last_ans = 0;
	for (ll i = 1; i <= n; i++){
		ll t; cin >> t;
		ll l = lowest(t), r = lowest(t + 1);
		checkpoints.insert(l); 
		checkpoints.insert(r);
		cur = i;
		ll k; cin >> k;
		while (k--){
			ll x; cin >> x;
			(x += last_ans) %= mod;
			last_ans = query(x);
			cout << last_ans << "\n";
		}
	}
}