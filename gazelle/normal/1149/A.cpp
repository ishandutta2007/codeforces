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
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n) cin >> a[i];
	int c1 = 0, c2 = 0;
	REP(i, n) {
		if(a[i] == 1) c1++;
		else c2++;
	}
	vector<int> ans;
	if(c1 == 0 || c2 == 0) {
		DUMP(a);
		return 0;
	}
	ans.pb(2);
	ans.pb(1);
	c1--; c2--;
	REP(i, c2) ans.pb(2);
	REP(i, c1) ans.pb(1);
	DUMP(ans);
	return 0;
}
/* --------------------------------------- */