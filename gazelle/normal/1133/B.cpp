#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<math.h>
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
	int n, k;
	cin >> n >> k;
	vector<int> c(k, 0);
	REP(i, n) {
		ll d;
		cin >> d;
		c[d % k]++;
	}
	ll ans = c[0] / 2;
	FOR(i, 1, k) {
		if(k - i < i) break;
		if(k - i == i) {
			ans += c[i] / 2;
		} else {
			ans += min(c[i], c[k - i]);
		}
	}
	cout << ans * 2 << endl;
	return 0;
}
/* --------------------------------------- */