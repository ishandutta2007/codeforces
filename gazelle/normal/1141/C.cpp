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
	ll n;
	cin >> n;
	vector<ll> q(n - 1), p(n);
	REP(i, n - 1) cin >> q[i];
	ll mx = 0;
	ll tmp = 0;
	REP(i, n - 1) {
		tmp += q[i];
		mx = max(mx, tmp);
	}
	if(n - mx <= 0 || n - mx > n) {
		cout << -1 << endl;
		return 0;
	}
	p[0] = n - mx;
	set<ll> s;
	s.insert(p[0]);
	REP(i, n - 1) {
		p[i + 1] = p[i] + q[i];
		if(s.count(p[i + 1]) || p[i + 1] <= 0 || p[i + 1] > n) {
			cout << -1 << endl;
			return 0;
		} else {
			s.insert(p[i + 1]);
		}
	}
	DUMP(p);
	return 0;
}

/* --------------------------------------- */