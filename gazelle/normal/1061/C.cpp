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

/* --------------------------------------- */
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	vector<vector<ll>> b(1000010);
	vector<vector<ll>> div(n);
	REP(i,n) b[a[i]].pb(i);
	FOR(i,1,1000010) {
		for(ll j = 1; i * j < 1000010; j++) {
			REP(k, b[i * j].size()) {
				div[b[i * j][k]].pb(i);
			}
		}
	}
	ll ans = 0;
	vector<ll> cnt(1000010,0);
	REP(i,n) {
		reverse(ALL(div[i]));
		REP(j,div[i].size()) {
			if(div[i][j] == 1) {
				cnt[1]++;
			} else {
				cnt[div[i][j]] += cnt[div[i][j] - 1];
				cnt[div[i][j]] %= MOD;
			}
		}
	}
	FOR(i,1,1000010) ans += cnt[i];
	cout << ans % MOD << endl;
	return 0;
}
/* --------------------------------------- */