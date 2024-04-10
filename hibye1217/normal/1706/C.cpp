#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;

ll arr[100020];
ll prf[100020], suf[100020];

void Main(){
	int t; cin >> t; while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		if (n & 1){
			ll ans = 0;
			for (int i = 2; i < n; i+=2){
				ll res = max(arr[i-1], arr[i+1]) - arr[i];
				if (res >= 0){ ans += res+1; }
			}
			cout << ans << endl;
		}
		else{
			prf[0] = 0; for (int i = 2; i < n; i+=2){
				ll res = max(arr[i-1], arr[i+1]) - arr[i];
				prf[i] = prf[i-2]; if (res >= 0){ prf[i] += res+1; }
			}
			suf[n+1] = 0; for (int i = n-1; i > 1; i-=2){
				ll res = max(arr[i-1], arr[i+1]) - arr[i];
				suf[i] = suf[i+2]; if (res >= 0){ suf[i] += res+1; }
			}
			ll ans = 1e18;
			for (int i = 2; i <= n; i+=2){
				ans = min(ans, prf[i-2]+suf[i+1]);
			}
			cout << ans << endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}