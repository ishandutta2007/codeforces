#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back


ll gcd(ll a, ll b) {		// 
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll extgcd(ll a, ll b, ll& x, ll& y) {		// 
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];
	map<pair<ll, pll>, ll> m;
	ll ans = 0;
	REP(i, n) {
		if(a[i] == 0) {
			if(b[i] == 0) ans++;
		} else if(b[i] == 0) {
			m[{0, pll(1, 0)}]++;
		} else {
			int d = a[i] * b[i] < 0;
			a[i] = abs(a[i]);
			b[i] = abs(b[i]);
			ll g = gcd(a[i], b[i]);
			m[{d, pll(a[i] / g, b[i] / g)}]++;
		}
	}
	ll tmp = 0;
	for(auto x: m) {
		tmp = max(tmp, x.second);
	}
	cout << ans + tmp << endl;
	return 0;
}
/* --------------------------------------- */