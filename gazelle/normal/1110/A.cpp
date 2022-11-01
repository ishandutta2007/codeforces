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
	ll b, k;
	cin >> b >> k;
	vector<ll> a(k);
	REP(i, k) cin >> a[i];
	ll ans = 0;
	if(b % 2 == 0) {
		if(a[k - 1] % 2) cout << "odd" << endl;
		else cout << "even" << endl;
	} else {
		REP(i, k) ans += a[i];
		if(ans % 2) cout << "odd" << endl;
		else cout << "even" << endl;
	}
	return 0;
}

/* --------------------------------------- */