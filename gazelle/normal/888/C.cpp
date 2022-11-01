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
#define MOD 998244353LL
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
	string s;
	cin >> s;
	ll n = (ll)s.size();
	vector<vector<ll>> pos(26, {-1});
	REP(i, n) {
		pos[s[i] - 'a'].pb(i);
	}
	ll ans = INF;
	REP(i, 26) {
		pos[i].pb(n);
		ll tmp = 0;
		REP(j, pos[i].size() - 1) {
			tmp = max(tmp, pos[i][j + 1] - pos[i][j] - 1);
		}
		ans = min(ans, tmp);
	}
	cout << ans + 1 << endl;
	return 0;
}

/* --------------------------------------- */