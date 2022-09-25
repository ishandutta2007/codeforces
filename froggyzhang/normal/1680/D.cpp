#include<bits/stdc++.h>
using namespace std;
#define N 3030
typedef long long ll;
int n,k,a[N],c[N];
ll s[N];
pair<ll,ll> calc(int l,int r){
	return make_pair(s[r]-s[l-1]-1LL*(c[r]-c[l-1])*k,s[r]-s[l-1]+1LL*(c[r]-c[l-1])*k);
}
void Solve(){
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
		c[i]=c[i-1]+(a[i]==0);
	}
	if(s[n]<-1LL*c[n]*k||s[n]>1LL*c[n]*k){
		cout<<-1<<'\n';
		return;
	}
	ll ans=0;
	for(int i=0;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			auto [l1,r1]=calc(1,i);
			auto [l2,r2]=calc(i+1,j);
			auto [l3,r3]=calc(j+1,n);
			ans=max(ans,min(r1+r3,-l2));
			ans=max(ans,min(-(l1+l3),r2));
		}
	}
	cout<<ans+1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solve();
	return 0;
}