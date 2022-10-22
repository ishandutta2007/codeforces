#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define INF 1e18
#define inf 1e9
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll Mod =  998244353;
int n;
vector<pll> v;
ll ans=1;
long long fact[300010];

int main() {
	fast;

	cin >> n;
	for(int i=0; i<n; i++) {
		ll a, b;
		cin >> a >> b;
		v.eb(a, b);
	}

	sort(all(v));

	long long b = 1;

	fact[0] = 1;
	for(int i=1; i<=n; i++) {
		fact[i] = fact[i-1] * i;
		fact[i] %= Mod;
	}

	ans = fact[n];

	for(int i=0; i<n; ) {
		int j = i;
		while(j < n && v[i].fi == v[j].fi) j++;
		b *= fact[j - i];
		b %= Mod;
		i = j;
	}

	ans -= b;
	ans = (ans%Mod+Mod)%Mod;
	//cout << ans << "\n";
	//cout << b << "\n";

	sort(all(v), [](pii a, pii b) {
		if(a.se == b.se) return a.fi < b.fi;
		return a.se < b.se;
	});

	b = 1;
	for(int i=0; i<n; ) {
		int j = i;
		while(j < n && v[i].se == v[j].se) j++;
		b *= fact[j - i];
		b %= Mod;
		i = j;
	}	

	ans -= b;
	ans = (ans%Mod+Mod)%Mod;
	//cout << b << "\n";

	for(int i=1; i<n; i++) {
		if(v[i].fi < v[i-1].fi) {
			cout << ans;
			return 0;
		}
	}

	bool flag = false;
	b = 1;
	for(int i=0; i<n; ) {
		int j = i;
		while(j < n && v[i] == v[j]) j++;
		b *= fact[j - i];
		b %= Mod;
		i = j;
	}	

	ans += b;
	ans = (ans%Mod+Mod)%Mod;
	//cout << b << "\n";

	cout << ans;
}