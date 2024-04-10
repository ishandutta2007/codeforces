#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define bcnt(x) __builtin_popcount(x)
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

pl2 arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		ll n, k; cin >> n >> k;
		for (int i = 1; i <= n; i++){ cin >> arr[i].fr; }
		for (int i = 1; i < n; i++){ cin >> arr[i].sc; }
		ll cnt = 0, ern = 0;
		ll ans = 1e15;
		for (int i = 1; i <= n; i++){
			ll add = arr[i].fr, val = arr[i].sc;
			ll tar = k-ern;
			//cout << "I " << cnt + (tar+add-1) / add << endl;
			ans = min(ans, cnt + (tar+add-1) / add);
			if (i != n){
				tar = val-ern;
				ll num = max(0LL, (tar+add-1) / add);
				cnt += num+1; ern += add*num; ern -= val;
			}
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