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
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

ll arr[200020], prf[200020], suf[200020];
ll tmp[200020], res[200020];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){ cin >> arr[i]; }
	for (int i = 1; i <= n; i++){ prf[i] = prf[i-1] + arr[i]; }
	for (int i = n; i >= 1; i--){ suf[i] = suf[i+1] + arr[i]; }
	ll st = 0, ed = 2e9, ans = 2e9;
	while (st <= ed){
		ll mid = st+ed >> 1;
		bool flg = 1;
		for (int i = 1; i <= n; i++){ tmp[i] = arr[i]; }
		for (int i = 1; i <= n; i++){
			tmp[i] -= mid; if (tmp[i] > 0){ flg = 0; }
			tmp[i+1] += tmp[i]; tmp[i] -= tmp[i];
		}
		if (flg){ ed = mid-1; ans = mid; } else{ st = mid+1; }
	}
	res[n] = ans; //cout << "RES " << n << " = " << res[n] << endl;
	for (int i = n-1; i >= 1; i--){
		ll tim = res[i+1];
		ll lft = max(suf[i] - (tim*i - prf[i-1]), 0LL);
		res[i] = min(res[i+1] + (lft+i-1)/i, 2'000'000'000LL);
		//cout << "RES " << i << " = " << res[i] << "   " << lft << endl;
	}
	int q; cin >> q; while (q--){
		ll x; cin >> x;
		auto idx = lower_bound(res+1, res+n+1, x, [](ll a, ll b){ return a > b; }) - res;
		if (idx > n){ cout << -1; } else{ cout << idx; } cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}