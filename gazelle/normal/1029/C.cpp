#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> l(n);
	vector<ll> r(n);
	REP(i,n) cin>>l[i]>>r[i];
	ll ans=0;
	map<ll,ll> ls;
	map<ll,ll> rs;
	REP(i,n) ls[l[i]]++;
	REP(i,n) rs[r[i]]++;
	REP(i,n) {
		ls[l[i]]--;
		if(ls[l[i]]==0) ls.erase(l[i]);
		rs[r[i]]--;
		if(rs[r[i]]==0) rs.erase(r[i]);
		auto ite=ls.end(); ite--;
		ll tmp1=ite->first;
		ite=rs.begin();
		ll tmp2=ite->first;
		ans=max(ans,tmp2-tmp1);
		ls[l[i]]++;
		rs[r[i]]++;
	}
	cout<<ans<<endl;
}