#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

ll arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		ll mn = 1e15, ans = 0;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; mn = min(mn, arr[i]); } arr[n+1] = 0;
		if (mn < 0){ ans += -mn; for (int i = 1; i <= n; i++){ arr[i] += -mn; } mn = 0; }
		ll cnt = mn;
		for (int i = 1; i <= n; i++){ arr[i] -= cnt; }
		ll num = 0;
		for (int i = 1; i <= n+1; i++){
			num += max(arr[i-1] - arr[i], 0LL);
		}
		num -= arr[1]; num -= arr[n];
		//cout << ans << ' ' << num << ' ' << cnt << endl;
		cout << ans + arr[1] + arr[n] + 3*num - min(num, cnt) + max(cnt - min(num, cnt), 0LL) << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}