#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
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
using P=pair<ll,ll>;
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
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	priority_queue<P> pq;
	REP(i, n) pq.push(P(a[i], i));
	vector<ll> ans(n);
	ll tmp = 1;
	while(!pq.empty()) {
		P p = pq.top();
		pq.pop();
		ans[p.second] = tmp;
		REP(i, n - p.first - 1) {
			if(pq.empty() || pq.top().first != p.first) {
				cout << "Impossible" << endl;
				return 0;
			}
			ans[pq.top().second] = tmp;
			pq.pop();
		}
		tmp++;
	}
	cout << "Possible" << endl;
	DUMP(ans);
	return 0;
}

/* --------------------------------------- */