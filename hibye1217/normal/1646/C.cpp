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

const ll N = 1'000'000'000'000;
const int M = 14;
ll fac[20];

int ans = 1e9;
void btk(ll n, int m, int cnt){
	if (m == 2){
		int res = cnt;
		while (n){ res += (n&1); n >>= 1; }
		ans = min(ans, res);
		return;
	}
	if (fac[m] <= n){ btk(n-fac[m], m-1, cnt+1); }
	btk(n, m-1, cnt);
}

void Main(){
	fac[0] = 1; for (int i = 1; i <= M; i++){ fac[i] = fac[i-1] * i; }
	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		ans = 1e9; btk(n, M, 0);
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}