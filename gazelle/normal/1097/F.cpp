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
	ll n, q;
	cin >> n >> q;
	vector<bitset<7001>> mask1(7001, bitset<7001>(0));
	vector<bitset<7001>> mask2(7001, bitset<7001>(0));
	FOR(i, 1, 7001) {
		FOR(j, 1, i + 1) {
			if(i % j == 0) mask1[i][j] = 1;
		}
	}
	FOR(i, 1, 7001) {
		mask2[i][i] = 1;
		for(ll j = i; j <= 7000; j++) {
			if(j % i) continue;
			for(ll k = 2; j * k <= 7000; k++) {
				mask2[i][j * k] = mask2[i][j * k] ^ mask2[i][j];
			}
		}
	}
	vector<bitset<7001>> ms(n, bitset<7001>(0));
	string ans = "";
	REP(i, q) {
		int ty;
		cin >> ty;
		if(ty == 1) {
			ll x, v;
			cin >> x >> v;
			x--;
			ms[x] = mask1[v];
		}
		if(ty == 2) {
			ll x, y, z;
			cin >> x >> y >> z;
			x--; y--; z--;
			ms[x] = ms[y] ^ ms[z];
		}
		if(ty == 3) {
			ll x, y, z;
			cin >> x >> y >> z;
			x--; y--; z--;
			ms[x] = ms[y] & ms[z];
		}
		if(ty == 4) {
			ll x, v;
			cin >> x >> v;
			x--;
			ans += (char)('0' + ((mask2[v] & ms[x]).count() % 2));
		}
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */