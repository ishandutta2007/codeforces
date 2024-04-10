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
	ll t;
	cin >> t;
	REP(testcase,t) {
		ll n, k;
		cin >> n >> k;
		if(n >= 32) {
			cout << "YES" << " " << n - 1 << endl;
			continue;
		}
		ll sum = 0;
		vector<ll> pow(2 * n, 0);
		ll d = 1;
		REP(i,n) {
			sum += d;
			pow[i + 1] = sum;
			d *= 4;
		}
		ll act = 0;
		d = 2;
		bool ok = false;
		//cout << (ll)sum << endl;
		for(ll i = n - 1; i >= 0; i--) {
			act += d - 1;
			d *= 2;
			//cout  << i << ":" << (ll)act << endl;
			if(k >= act && k <= sum - (d - 1) * pow[i]) {
				ok = true;
				cout << "YES" << " " << i << endl;
				break;
			}
		}
		if(!ok) cout << "NO" << endl;
	}
	return 0;
}
/* --------------------------------------- */