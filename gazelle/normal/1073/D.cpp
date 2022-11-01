#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

ll N = 200020;
ll bit[200020];
void add(ll a, ll w) {
	a++;
	for (ll x = a; x <= N; x += x & -x) bit[x] += w;
}
ll sum(ll a) {
	a++;
	ll ret = 0;
	for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, T;
	cin >> n >> T;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	ll ans = 0;
	ll s = 0;
	REP(i,n) {
		s += a[i];
		add(i, a[i]);
	}
	REP(i,n) {
		ll cyc = T / s;
		ans += cyc * (n - i);
		T -= cyc * s;
		ll l = -1, r = n;
		while(r - l > 1) {
			ll m = (r + l) / 2;
			if(sum(m) > T) r = m;
			else l = m;
		}
		add(r, -a[r]);
		s -= a[r];
	}
	cout << ans << endl;
	return 0;
}