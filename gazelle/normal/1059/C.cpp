#include<bits/stdc++.h>
#include<random>
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
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back
vector<ll> ans;
void rec(ll prd, ll n) {
	if(n==1) {
		ans.pb(prd);
		return;
	} else if(n==2) {
		ans.pb(prd);
		ans.pb(prd*2LL);
		return;
	} else if(n==3) {
		ans.pb(prd);
		ans.pb(prd);
		ans.pb(prd*3LL);
		return;
	} else {
		REP(i,(n+1)/2) ans.pb(prd);
		rec(prd*2,n/2);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	rec(1,n);
	DUMP(ans);
	return 0;
}