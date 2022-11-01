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

ll gcd(ll a, ll b) {		// 
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll extgcd(ll a, ll b, ll& x, ll& y) {		// 
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll q;
	cin >> q;
	map<ll,ll> memo;
	REP(i, q) {
		ll a;
		cin >> a;
		bitset<25> bi(a);
		bool ok = false;
		int cnt = 0;
		for(ll j = 24; j >= 0; j--) {
			if(bi[j]) ok = true;
			if(ok) {
				if(!bi[j]) {
					cnt++;
					bi[j] = 1;
				}
			}
		}
		if(cnt == 0) {
			if(memo.count(a)) {
				cout << memo[a] << endl;
			} else {
				ll ans = 1;
				for(ll j = 2; j * j <= a; j++) {
					if(a % j == 0) {
						ans = max(ans, j);
						ans = max(ans, a / j);
					}
				}
				memo[a] = ans;
				cout << memo[a] << endl;
			}
		} else cout << bi.to_ullong() << endl;
	}
	return 0;
}

/* --------------------------------------- */