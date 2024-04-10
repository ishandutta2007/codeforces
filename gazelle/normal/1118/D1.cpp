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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	sort(ALL(a)); reverse(ALL(a));
	ll sum = 0; REP(i, n) sum += a[i];
	if(sum < m) {
		cout << -1 << endl;
		return 0;
	}
	ll l = 0, r = n;
	while(r - l > 1) {
		ll mid = (l + r) / 2;
		ll power = 0;
		ll cnt = 0, cost = 0;
		REP(i, n) {
			if(a[i] < cost) break;
			power += a[i] - cost;
			cnt++;
			if(cnt == mid) {
				cnt = 0;
				cost++;
			}
		}
		if(power >= m) r = mid;
		else l = mid;
	}
	cout << r << endl;
	return 0;
}

/* --------------------------------------- */