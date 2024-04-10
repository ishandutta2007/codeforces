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
	vector<pll> ob(n);
	set<pll> cl;
	REP(i, n) {
		cin >> ob[i].first >> ob[i].second;
	}
	REP(i, n) {
		ll a, b;
		cin >> a >> b;
		cl.insert(pll(a, b));
	}
	for(auto x: cl) {
		pll tgt = pll(ob[0].first + x.first, ob[0].second + x.second);
		bool ok = true;
		FOR(j, 1, n) {
			if(!cl.count(pll(tgt.first - ob[j].first, tgt.second - ob[j].second))) ok = false;
		}
		if(ok) {
			cout << tgt.first << " " << tgt.second << endl;
			return 0;
		}
	}
	return 0;
}

/* --------------------------------------- */