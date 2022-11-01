#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 998244353ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<ll> bunkai(ll n) {
	if(n==1) return {};
	for(ll i=2; i*i<=n; i++) {
		if(n%i==0) {
			vector<ll> ret=bunkai(n/i);
			ret.pb(i);
			return ret;
		}
	}
	vector<ll> ret;
	ret.pb(n);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> a(n);
	vector<ll> b(n);
	REP(i,n) cin>>a[i]>>b[i];
	set<ll> s;
	vector<ll> v1=bunkai(a[0]);
	vector<ll> v2=bunkai(b[0]);
	REP(i,v1.size()) s.insert(v1[i]);
	REP(i,v2.size()) s.insert(v2[i]);
	for(auto x: s) {
		bool d=true;
		REP(i,n) {
			if(a[i]%x!=0&&b[i]%x!=0) d=false;
		}
		if(d) {
			cout<<x<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
}