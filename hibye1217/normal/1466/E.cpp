#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

const ll mod = 1e9 + 7;
ll arr[500020];
ll cnt[70];

ll mul(ll a, ll b, ll c){
	return (a%c) * (b%c) % c;
}

void Main(){
	int t;
	cin >> t;
	while (t--){
		ll n;
		cin >> n;
		for (ll i = 1; i <= n; i++){
			cin >> arr[i];
			ll x = arr[i];
			for (ll j = 0; x; j++){
				cnt[j] += x&1;
				x >>= 1;
			}
		}
		//for (ll i = 0; i <= 60; i++){
		//	cout << "BIT " << i << ' ' << cnt[i] << ' ' << mul(cnt[i], 1LL<<i, mod) << endl;
		//}
		ll ans = 0;
		for (ll i = 1; i <= n; i++){
			ll a = 0, o = 0;
			for (ll j = 0; j <= 60; j++){
				if (arr[i] & 1LL<<j){
					a += mul(cnt[j], 1LL<<j, mod);
					a %= mod;
					o += mul(n, 1LL<<j, mod);
					o %= mod;
				}
				else{
					o += mul(cnt[j], 1LL<<j, mod);
					o %= mod;
				}
				//cout << "AND OR BIT " << j << ' ' << a << ' ' << o << endl;
			}
			ans += a*o % mod;
			ans %= mod;
		}
		cout << ans << endl;
		memset(cnt, 0, sizeof(cnt));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}