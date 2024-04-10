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
	ll q;
	cin >> q;
	ll maxi1 = 0, maxi2 = 0;
	REP(query, q) {
		char c;
		cin >> c;
		if(c == '+') {
			ll x, y;
			cin >> x >> y;
			if(x < y) swap(x, y);
			maxi1 = max(maxi1, x);
			maxi2 = max(maxi2, y);
		} else {
			ll h, w;
			cin >> h >> w;
			if(h < w) swap(h, w);
			if(maxi1 <= h && maxi2 <= w) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}

/* --------------------------------------- */