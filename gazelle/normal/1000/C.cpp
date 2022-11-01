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
#define UNIQUE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<P> seg(n);
	REP(i,n) cin>>seg[i].first>>seg[i].second;
	vector<ll> pnt;
	REP(i,n) {
		pnt.pb(seg[i].first);
		pnt.pb(seg[i].second);
	}
	UNIQUE(pnt);
	map<ll,ll> dict;
	REP(i,(ll)pnt.size()) dict[pnt[i]]=i;
	vector<ll> imo((ll)pnt.size(),0);
	REP(i,n) {
		imo[dict[seg[i].first]]++;
		imo[dict[seg[i].second]]--;
	}
	FOR(i,1,(ll)imo.size()) imo[i]+=imo[i-1];
	vector<ll> ans(n+1,0);
	REP(i,(ll)imo.size()-1) {
		ans[imo[i]]+=max(0ll,pnt[i+1]-pnt[i]-1);
	}
	REP(i,(ll)imo.size()) imo[i]=0;
	imo.pb(0);
	REP(i,n) {
		imo[dict[seg[i].first]]++;
		imo[dict[seg[i].second]+1]--;
	}
	FOR(i,1,(ll)imo.size()) imo[i]+=imo[i-1];
	REP(i,(ll)imo.size()) ans[imo[i]]++;
	FOR(i,1,n+1) {
		cout<<ans[i];
		if(i==n) cout<<endl;
		else cout<<" ";
	}
}