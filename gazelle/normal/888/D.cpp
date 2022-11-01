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
#include<functional>
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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vector<ll> mont(5, 0);
	mont[0] = 1;
	mont[1] = 0; mont[2] = 1;
	mont[3] = 2; mont[4] = 9;
	ll ans = 0;
	for(ll i = 0; i <= k; i++) {
		ll c = 1;
		REP(j, i) c *= (n - j);
		REP(j, i) c /= (j + 1);
		ans += c * mont[i];
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */