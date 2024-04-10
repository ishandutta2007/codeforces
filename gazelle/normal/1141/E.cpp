#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll H, n;
	cin >> H >> n;
	vector<ll> d(n);
	REP(i, n) cin >> d[i];
	ll tmp = H, sum = 0;
	REP(i, n) {
		tmp += d[i];
		sum += d[i];
		if(tmp <= 0) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	if(sum >= 0) {
		cout << -1 << endl;
		return 0;
	}
	sum = abs(sum);
	ll ans = INF * INF, diff = 0;
	REP(i, n) {
		diff += d[i];
		ll k = (H + diff) / sum; if((H + diff) % sum) k++;
		ans = min(ans, k * n + i + 1);
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */