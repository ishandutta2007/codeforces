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
	vector<vector<pll>> sp(n);
	REP(i, m) {
		ll x, y, w;
		cin >> x >> y >> w;
		x--; y--;
		sp[x].pb(pll(y, w));
		sp[y].pb(pll(x, w));
	}
	ll ans = 0;
	set<pll> s1;
	set<pll> s2;
	s1.insert(pll(a[0], 0));
	priority_queue<pair<ll, pll>,vector<pair<ll, pll>>,greater<pair<ll, pll>>> q;
	REP(i, sp[0].size()) {
		q.push(make_pair(sp[0][i].second, pll(0, sp[0][i].first)));
	}
	FOR(i, 1, n) s2.insert(pll(a[i], i));
	while(!s2.empty()) {
		while(!q.empty()) {
			ll p1 = q.top().second.first, p2 = q.top().second.second;
			if(s1.count(pll(a[p1], p1)) && s1.count(pll(a[p2], p2))) q.pop();
			else break;
		}
		if(q.empty() || q.top().first > s1.begin() -> first + s2.begin() -> first) {
			ans += s1.begin() -> first + s2.begin() -> first;
			ll pos = s2.begin() -> second;
			s2.erase(s2.begin());
			s1.insert(pll(a[pos], pos));
			REP(i, sp[pos].size()) {
				q.push(make_pair(sp[pos][i].second, pll(pos, sp[pos][i].first)));
			}
		} else {
			ans += q.top().first;
			ll p1 = q.top().second.first, p2 = q.top().second.second;
			q.pop();
			if(s1.count(pll(a[p1], p1))) {
				s2.erase(pll(a[p2], p2));
				s1.insert(pll(a[p2], p2));
				REP(i, sp[p2].size()) {
					q.push(make_pair(sp[p2][i].second, pll(p2, sp[p2][i].first)));
				}
			} else {
				s2.erase(pll(a[p1], p2));
				s1.insert(pll(a[p1], p2));
				REP(i, sp[p1].size()) {
					q.push(make_pair(sp[p1][i].second, pll(p1, sp[p1][i].first)));
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */