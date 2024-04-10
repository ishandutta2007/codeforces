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
	ll a,b;
	cin>>a>>b;
	ll c=a+b;
	vector<ll> a_div;
	vector<ll> b_div;
	for(ll i=1; i*i<=a; i++) {
		if(a%i==0) {
			if(i*i==a) a_div.pb(i);
			else {
				a_div.pb(i);
				a_div.pb(a/i);
			}
		}
	}
	for(ll i=1; i*i<=b; i++) {
		if(b%i==0) {
			if(i*i==b) b_div.pb(i);
			else {
				b_div.pb(i);
				b_div.pb(b/i);
			}
		}
	}
	sort(ALL(a_div));
	sort(ALL(b_div));
	ll ans=INF*INF;
	for(ll i=1; i*i<=c; i++) {
		if(c%i!=0) continue;
		auto ite=upper_bound(ALL(a_div),c/i);
		if(ite!=a_div.begin()) {
			ite--;
			if(a/(*ite)<=i) ans=min(ans,2*i+2*(c/i));
		}
		ite=upper_bound(ALL(b_div),c/i);
		if(ite!=b_div.begin()) {
			ite--;
			if(b/(*ite)<=i) ans=min(ans,2*i+2*(c/i));
		}
	}
	cout<<ans<<endl;
}