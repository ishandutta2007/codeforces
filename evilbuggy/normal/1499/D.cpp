#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 2e7 + 27;
int lpf[N], cnt[N];

void sieve(){
	memset(lpf, -1, sizeof(lpf));
	cnt[1] = 0;
	for(int n = 2; n < N; n++){
		if(lpf[n] == -1){
			lpf[n] = n;
			if(n*1LL*n < N){
				for(int m = n*n; m < N; m += n){
					if(lpf[m] == -1){
						lpf[m] = n;
					}
				}
			}
		}
		int x = n/lpf[n];
		cnt[n] = cnt[x] + (lpf[x] != lpf[n]);
	}
}

void dfs(int i, vector<pair<ll, int> > &pf, vector<ll> &ret, ll x){
	if(i == pf.size()){
		ret.push_back(x);
		return;
	}
	dfs(i + 1, pf, ret, x);
	for(int j = 0; j < pf[i].second; j++){
		x *= pf[i].first;
		dfs(i + 1, pf, ret, x);
	}
}

vector<ll> getFacs(ll x){
	vector<pair<ll, int> > pf;
	while(x > 1){
		ll y = lpf[x];
		pf.push_back({y, 0});
		while(x%y == 0){
			x /= y;
			pf.back().second++;
		}
	}
	vector<ll> ret;
	dfs(0, pf, ret, 1);
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	sieve();
	int t; cin >> t;
	while(t--){
		ll c, d, x;
		cin >> c >> d >> x;
		ll ans = 0;
		vector<ll> facs = getFacs(x);
		for(ll div : facs){
			ll tmp = x/div + d;
			if(tmp%c == 0){
				ans += 1LL<<cnt[tmp/c];
			}
		}
		cout << ans << '\n';
	}

	return 0;
}