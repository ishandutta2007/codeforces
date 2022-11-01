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
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> acm(n);
	for(ll i=n-1; i>=0; i--) {
		if(i!=n-1) acm[i]+=acm[i+1];
 		if(i%2) {
			if(i!=n-1) acm[i]+=a[i+1]-a[i];
			else acm[i]+=m-a[i];
		}
	}
	ll ans=acm[0]+a[0];
	if(a[0]!=1) ans=max(ans,(m-a[0])-acm[0]+(a[0]-1));
	ll sum=a[0];
	REP(i,n) {
		if(!((i<n-1&&a[i+1]-a[i]==1)||(i==n-1&&m-a[i]==1))) {
			if(i%2) {
				if(i!=n-1) ans=max(ans,sum+(m-a[i+1])-acm[i+1]+(a[i+1]-a[i]-1));
			} else {
				if(i!=n-1) ans=max(ans,sum+(m-a[i+1])-acm[i+1]+(a[i+1]-a[i]-1));
				else ans=max(ans,sum+(m-a[i]-1));
			}
		}
		if(i%2&&i!=n-1) sum+=a[i+1]-a[i];
	}
	cout<<ans<<endl;
}