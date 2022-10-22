#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

ll arr[400020];

void Main(){
	int t; cin >> t;
	while (t--){
		ll ans = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		arr[0] = arr[n+1] = 0;
		for (int i = 1; i <= n; i++){
			if (arr[i-1] < arr[i] && arr[i] > arr[i+1]){
				ll dif = min(arr[i]-arr[i-1], arr[i]-arr[i+1]);
				arr[i] -= dif; ans += dif;
			}
		}
		for (int i = 1; i <= n; i++){
			ll r1 = max(arr[i]-arr[i-1], 0LL);
			ll r2 = max(arr[i]-arr[i+1], 0LL);
			ll dif = r1+r2;
			ans += dif;
		}
		cout << ans << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}