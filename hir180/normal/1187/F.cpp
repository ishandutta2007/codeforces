#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <assert.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define fi first
#define sc second
typedef pair<int,int> P;
typedef pair<P,P> P2;
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
ll L[200005];
ll R[200005];
ll ans = 0;
ll pr[200005];
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main(){
	int n; cin>>n;
	L[0] = R[0] = 0;
	repn(i,n) cin>>L[i];
	repn(i,n) cin>>R[i];
	repn(i,n){
		ll x = (R[i]-L[i]+1) * (R[i-1]-L[i-1]+1)%mod;
		ll y = max(0ll,min(R[i],R[i-1])-max(L[i],L[i-1])+1);
		
		ans += (x-y) * modpow(x,mod-2)%mod;
		pr[i-1] = (x-y) * modpow(x,mod-2)%mod;
	}
	ll sum = 0;
	rep(i,n) sum += pr[i];
	sum%=mod;
	ans%=mod;
	rep(i,n){
	ll sum2 = sum;
	if(i) sum2 -= pr[i-1];
	sum2-=pr[i];
	if(i!=n-1) sum2 -= pr[i+1];
	sum2=(sum2%mod+mod)%mod;
//	cout<<pr[i]<<" "<<sum2<<endl;
		ans += pr[i]  *sum2%mod;
	}
	ans%=mod; //cout <<ans<<" "<< 7*modpow(2LL,mod-2)%mod;
	for(int i=0;i<n-1;i++){
		//i,i+1,i+2 
		ll x = (R[i]-L[i]+1) * (R[i+1]-L[i+1]+1)%mod* (R[i+2]-L[i+2]+1)%mod;
		vector<ll>za;
		za.pb(L[i]-1); za.pb(L[i]); za.pb(L[i]+1);
		za.pb(L[i+1]-1); za.pb(L[i+1]); za.pb(L[i+1]+1);
		za.pb(L[i+2]-1); za.pb(L[i+2]); za.pb(L[i+2]+1);
		za.pb(R[i]-1); za.pb(R[i]); za.pb(R[i]+1);
		za.pb(R[i+1]-1); za.pb(R[i+1]); za.pb(R[i+1]+1);
		za.pb(R[i+2]-1); za.pb(R[i+2]); za.pb(R[i+2]+1);
		sort(za.begin(),za.end());
		za.erase(unique(za.begin(),za.end()),za.end());
		for(int j=0;j<za.size()-1;j++){
			//za[j]~za[j+1]-1
			if(L[i+1] <= za[j] && za[j+1]-1 <= R[i+1]) ; else continue;
			ll y = (za[j+1]-za[j]);
			if(L[i] <= za[j] && za[j+1]-1 <= R[i]) y=y*(R[i]-L[i]+1-1)%mod; else y=y*(R[i]-L[i]+1)%mod;
			if(L[i+2] <= za[j] && za[j+1]-1 <= R[i+2]) y=y*(R[i+2]-L[i+2]+1-1)%mod; else y=y*(R[i+2]-L[i+2]+1)%mod;
			ans += y*2LL%mod*modpow(x,mod-2)%mod;
		}
	}
	ans = (ans%mod+mod)%mod;
	cout << ans << endl;
}