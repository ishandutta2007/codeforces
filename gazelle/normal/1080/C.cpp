#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
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

P cnt (P z) {
	if(z.first == 0 || z.second == 0) return P(0, 0);
	if(z.first % 2) {
		if(z.second % 2) {
			return P(z.first * z.second / 2 + 1, z.first * z.second / 2);
		} else {
			return P(z.first * z.second / 2, z.first * z.second / 2);
		}
	} else {
		if(z.second % 2) {
			return P(z.first * z.second / 2, z.first * z.second / 2);
		} else {
			return P(z.first * z.second / 2, z.first * z.second / 2);
		}
	}
}

P cnt(P z1, P z2) {
	P ret = cnt(z2);
	P tmp1 = cnt(P(z1.first - 1, z2.second));
	P tmp2 = cnt(P(z2.first, z1.second - 1));
	P tmp3 = cnt(P(z1.first - 1, z1.second - 1));
	ret.first -= tmp1.first; ret.second -= tmp1.second;
	ret.first -= tmp2.first; ret.second -= tmp2.second;
	ret.first += tmp3.first; ret.second += tmp3.second;
	return ret;
}

/* --------------------------------------- */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	REP(i,t) {
		ll n, m;
		cin >> n >> m;
		P z1, z2, z3, z4;
		cin >> z1.first >> z1.second;
		cin >> z2.first >> z2.second;
		cin >> z3.first >> z3.second;
		cin >> z4.first >> z4.second;
		P z5 = P(max(z1.first, z3.first), max(z1.second, z3.second));
		P z6 = P(min(z2.first, z4.first), min(z2.second, z4.second));
		P ans = cnt(P(m, n));
		ll c1 = cnt(z1, z2).second;
		ans.second -= c1;
		ans.first += c1;
		ll c2 = cnt(z3, z4).first;
		ans.first -= c2;
		ans.second += c2;
		if(z6.first - z5.first >= 0 && z6.second - z5.second >= 0) {
			ll c3 = cnt(z5, z6).second;
			ans.first -= c3;
			ans.second += c3;
		}
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}
/* --------------------------------------- */