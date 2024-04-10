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
	ll n, k;
	cin >> n >> k;
	if(k * (k - 1) < n) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	pll bef = pll(-1, -1);
	ll c = 0;
	FOR(i, 1, k + 1) FOR(j, i + 1, k + 1) {
		pll cur = pll(i, j);
		if(bef.first == cur.first || bef.second == cur.second) {
			swap(cur.first, cur.second);
		}
		if(c + 1 == n) {
			cout << cur.first << " " << cur.second << endl;
			c++;
		} else {
			cout << cur.first << " " << cur.second << endl;
			cout << cur.second << " " << cur.first << endl;
			c += 2;
		}
		if(c == n) return 0;
		bef.first = cur.second; bef.second = cur.first;
	}
	return 0;
}

/* --------------------------------------- */