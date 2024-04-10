#include<bits/stdc++.h>  
using namespace std;  
  
#define fast ios::sync_with_stdio(false);cin.tie(NULL)  
#define fi first  
#define se second  
#define all(v) (v).begin(),(v).end()  
#define pb push_back  
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)
#define mp make_pair
  
typedef long long ll;  
typedef pair<int,int> pii;  
typedef pair<ll,ll> pll;  
const long long INF = 1e18;  
const int inf = 1e9;

ll n, ans;
ll x[3000], y[3000];

ll ccw(pll a, pll b) {
	return a.fi * b.se - b.fi * a.se;
}

int main() {
	fast;

	cin >> n;

	for(int i=1; i<=n; i++) {
		cin >> x[i] >> y[i];
	}

	for(int i=1; i<=n; i++) {
		vector<pll> v;
		for(int j=1; j<=n; j++) {
			if(j == i) continue;

			v.eb(x[j] - x[i], y[j] - y[i]);
		}

		sort(all(v), [] (pll a, pll b) {
			if(a.fi == 0 && a.se < 0) return true;
			if(b.fi == 0 && b.se < 0) return false;
			if(a.fi * b.fi > 0) return a.se * b.fi < b.se * a.fi;
			else return a.fi > b.fi;
		});

		ans += (n-1) * (n-2) * (n-3) / 6;

		for(int j=0, k=0; j<v.size(); j++) {
			if(k == j) k = (k+1)%v.size();
			while(ccw(v[j], v[k]) > 0 && k != j) k = (k+1)%v.size();

			ll t = (k - j + v.size() - 1) % v.size();

			ans -= t * (t-1) / 2;
		}
	}

	ans = ans * (n - 4) / 2;

	cout << ans;
}