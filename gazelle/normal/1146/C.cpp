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
#include<cassert>
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
	int t;
	cin >> t;
	REP(testcase, t) {
		int n;
		cin >> n;
		int ans = 0;
		REP(i, 9) {
			vector<ll> a, b;
			FOR(j, 1, n + 1) {
				bitset<32> bi(j);
				if(bi[i]) a.pb(j);
				else b.pb(j);
			}
			if(a.empty() || b.empty()) continue;
			sort(ALL(a)); sort(ALL(b));
			cout << (int)a.size() << " " << (int)b.size() << " ";
			REP(j, b.size()) a.pb(b[j]);
			DUMP(a);
			int ret;
			cin >> ret;
			ans = max(ans, ret);
		}
		cout << -1 << " " << ans << endl;
	}
	return 0;
}
/* --------------------------------------- */