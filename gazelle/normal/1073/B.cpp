#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i,n) cin >> a[i];
	vector<ll> b(n);
	REP(i,n) cin >> b[i];
	set<ll> s;
	vector<ll> ans(n,0);
	ll pos = 0;
	REP(i,n) {
		if(s.count(b[i])) continue;
		ll cnt = 0;
		while(1) {
			s.insert(a[pos]);
			cnt++;
			pos++;
			if(a[pos - 1] == b[i]) break;
		}
		ans[i] = cnt;
	}
	DUMP(ans);
	return 0;
}