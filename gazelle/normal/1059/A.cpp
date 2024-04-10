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

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,L,a;
	cin>>n>>L>>a;
	ll ans=0;
	ll ct=0;
	REP(i,n) {
		ll t,l;
		cin>>t>>l;
		ans+=(t-ct)/a;
		ct=t+l;
	}
	ans+=(L-ct)/a;
	cout<<ans<<endl;
	return 0;
}