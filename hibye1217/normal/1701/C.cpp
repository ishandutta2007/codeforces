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

int cnt[200020];
int res[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		for (int i = 1; i <= m; i++){ int x; cin >> x; cnt[x] += 1; }
		int st = 0, ed = 2*m, ans = 0;
		while (st <= ed){
			int mid = st+ed >> 1;
			ll num = 0;
			for (int i = 1; i <= n; i++){
				int x = min(cnt[i], mid);
				res[i] = x; num += cnt[i] - x;
			}
			ll val = 0;
			for (int i = 1; i <= n; i++){
				val += (mid-res[i]) / 2;
			}
			//cout << "BINSER " << st << ' ' << ed << endl << flush;
			if (val >= num){ ed = mid-1; ans = mid; } else{ st = mid+1; }
			for (int i = 1; i <= n; i++){ res[i] = 0; }
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++){ cnt[i] = 0; }
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}