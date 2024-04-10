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
#define MOD 1000000000000000007LL
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
	vector<ll> b(n / 2);
	REP(i, n / 2) cin >> b[i];
	vector<ll> a(n);
	REP(i, n / 2) {
		if(i == 0) {
			a[0] = 0;
			a[n - 1] = b[i];
			continue;
		}
		ll l = -1, r = b[i] / 2;
		while(r - l > 1) {
			ll m = (l + r) / 2;
			if(m >= a[i - 1] && (b[i] - m) <= a[n - i]) r = m;
			else l = m;
		}
		a[i] = r;
		a[n - 1 - i] = b[i] - r;
	}
	DUMP(a);
	return 0;
}

/* --------------------------------------- */