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

ll sum(ll a) {
	if(a == 0) return 0;
	ll b = a / 2;
	ll ret = 0;
	if(a % 2) {
		ret = -(1 + a) * (b + 1) / 2;
		ret += (2 + a - 1) * b / 2;
	} else {
		ret = -(1 + a - 1) * b / 2;
		ret += (2 + a) * b / 2;
	}
	return ret;
}

/* --------------------------------------- */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll q;
	cin >> q;
	REP(i,q) {
		ll l, r;
		cin >> l >> r;
		cout << sum(r) - sum(l - 1) << endl;
	}
	return 0;
}
/* --------------------------------------- */