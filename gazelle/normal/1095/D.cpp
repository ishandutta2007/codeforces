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
	vector<pll> v(n);
	REP(i, n) cin >> v[i].first >> v[i].second;
	REP(i, n) {
		v[i].first--;
		v[i].second--;
	}
	if(n == 3) {
		cout << 1 << " " << 2 << " " << 3 << endl;
		return 0;
	}
	vector<ll> ans;
	ll pos = 0;
	REP(i, n) {
		ans.pb(pos);
		ll a = v[pos].first, b = v[pos].second;
		if(v[a].first == b || v[a].second == b) {
			pos = a;
		} else {
			pos = b;
		}
	}
	REP(i, n) ans[i]++;
	DUMP(ans);
	return 0;
}

/* --------------------------------------- */