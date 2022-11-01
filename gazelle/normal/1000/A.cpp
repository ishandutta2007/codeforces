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
	map<string,ll> a;
	map<string,ll> b;
	REP(i,n) {
		string s;
		cin>>s;
		a[s]++;
	}
	REP(i,n) {
		string s;
		cin>>s;
		b[s]++;
	}
	for(auto x: a) {
		ll diff=min(x.second,b[x.first]);
		//cout<<x.first<<" "<<diff<<endl;
		a[x.first]-=diff;
		b[x.first]-=diff;
	}
	for(auto x: b) {
		ll diff=min(x.second,a[x.first]);
		//cout<<x.first<<" "<<diff<<endl;
		a[x.first]-=diff;
		b[x.first]-=diff;
	}
	map<string,ll> c;
	for(auto x: a) c[x.first]+=x.second;
	for(auto x: b) c[x.first]+=x.second;
	ll ans=0;
	ans+=c["S"]+c["M"]+c["L"]-max({c["S"],c["M"],c["L"]});
	ans+=min(c["XS"],c["XL"]);
	ans+=min(c["XXS"],c["XXL"]);
	ans+=min(c["XXXS"],c["XXXL"]);
	cout<<ans<<endl;
}