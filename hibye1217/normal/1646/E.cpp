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

ll gcd(ll a, ll b){ return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b){ return a*b / gcd(a,b); }

pi2 sq[1000020];
ll res[22];
bool chk[1000020];

void Main(){
	memset(res, -1, sizeof(res));
	int n, m; cin >> n >> m;
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ll j = i; int cnt = 1;
		while (j <= n){
			if (sq[j].fr == 0){ sq[j] = {i, cnt}; }
			j *= i; cnt += 1;
			if (j == 1){ break; }
		}
	}
	for (int i = 1; i <= n; i++){
		if (i == 1){ ans += 1; continue; }
		ll val = m; int cnt = sq[i].sc;
		if (res[cnt] != -1){ val -= res[cnt]; }
		else{
			ll num = 0;
			memset(chk, 0, sizeof(chk));
			for (int i = 1; i < cnt; i++){
				//cout << "CNT " << i << ' ' << cnt << endl;
				int l = lcm(i, cnt);
				int a = l / i, b = l / cnt;
				int c = m/a;
				for (ll j = b; j <= c*b; j += b){
					//cout << j << ' ' << c*b << endl;
					if (!chk[j]){ num += 1; }
					chk[j] = 1;
				}
				//cout << "TWST";
			}
			res[cnt] = num;
			val -= num;
		}
		ans += val;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}