#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ll n;
	cin>>n;
	vector<ll> a(n);
	REP(i, n) cin>>a[i];
	map<ll, pair<ll, ll> > m;
	vector<pair<P, ll> > seg;
	for(int i = 0; i < n; ++i) {
		if(m.count(a[i]) == 0) {
			m[a[i]].first = i;
			m[a[i]]. second = i;
		} else {
			m[a[i]].second = i;
		}
	}
	map<ll, pair<ll, ll> >::iterator ite = m.begin();
	REP(i, m.size()) {
		FOR(j, (*ite).second.first + 1, (*ite).second.second + 1) {
			(*ite).second.first = min((*ite).second.first, (*m.find(a[j])).second.first);
				(*ite).second.second = max((*ite).second.second, (*m.find(a[j])).second.second);
		}
		++ite;
	}
	seg.resize(m.size());
	ite = m.begin();
	REP(i, m.size()) {
		ll o = a[(*ite).second.first];
		set<ll> mita;
		mita.insert(o);
		FOR(j, (*ite).second.first + 1, (*ite).second.second + 1) {
			if(mita.count(a[j]) == 0) {
				o = (o ^ a[j]);
				mita.insert(a[j]);
			}
		}
		seg[i] = pair<P, ll>(P((*ite).second.first, (*ite).second.second), o);
		++ite;
	}
	sort(ALL(seg));
	vector<ll> dp(n + 1, -INF);
	ll maxi = 0;
	ll np = 0;
	REP(i, seg.size()) {
		FOR(j, np, seg[i].first.first + 1) {
			maxi = max(maxi, dp[j]);
		}
		np = seg[i].first.first + 1;
		dp[(seg[i].first.second + 1)] = maxi + seg[i].second;
	}
	ll res = 0;
	REP(i, n + 1) {
		res = max(res, dp[i]);
	}
	cout<<res<<endl;
}