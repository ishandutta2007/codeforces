#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	vector<ll> e(n, 0), o(n, 0);
	o[0] = a[0];
	FOR(i, 1, n) {
		o[i] = o[i - 1];
		e[i] = e[i - 1];
		if(i % 2) e[i] += a[i];
		else o[i] += a[i];
	}
	ll sum = 0;
	REP(i, n) sum += a[i];
	ll ans = 0;
	REP(i, n) {
		ll c = 0;
		if(i % 2) {
			c = o[i] + e[n - 1] - e[i];
		} else {
			c = e[i] + o[n - 1] - o[i];
		}
		if((sum - a[i]) % 2 == 0 && c == (sum - a[i]) / 2) ans++;
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */