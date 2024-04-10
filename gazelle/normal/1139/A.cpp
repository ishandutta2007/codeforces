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
	int n;
	string s;
	cin >> n >> s;
	ll ans = 0;
	REP(i, n) {
		if((s[i] - '0') % 2 == 0) {
			ans += i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */