#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tuple<int, int> pii;
typedef tuple<int, int, int> piii;
typedef tuple<int, int, int, int> piiii;
typedef tuple<int, int, int, int, int> piiiii;
typedef tuple<ll, ll> pll;
typedef tuple<ll, ll, ll> plll;
typedef tuple<ll, ll, ll, ll> pllll;
typedef tuple<ll, ll, ll, ll, ll> plllll;

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		ll a[60] = {};
		ll b[60] = {};
		ll ma = 1e9 + 7, mb = 1e9 + 9;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			ma = min(ma, a[i]);
		}
		for (int i = 1; i <= n; i++){
			cin >> b[i];
			mb = min(mb, b[i]);
		}
		//cout << ma << ' ' << mb <<endl;
		for (int i = 1; i <= n; i++){
			a[i] -= ma;
			b[i] -= mb;
			//cout << a[i] << ' ' << b[i] << endl;
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++) ans += max(a[i], b[i]);
		cout << ans << endl;
	}
}