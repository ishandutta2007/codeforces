
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K,per,cnt,sml[1000005];
//cnt:how many days differ in a period
int n,m,a[1000005],b[1000005],posa[1000005],posb[1000005],g;
void Exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
		return ;
	}
	ll xx,yy;
	Exgcd(b,a%b,xx,yy),x=yy,y=xx-(a/b)*yy;
}
ll Calc(ll i,ll j){
	ll k1,k2;
	Exgcd(n,m,k1,k2);
	k1=(k1%(m/g)+(m/g))%(m/g);
	k1*=(j-i)/g;
	ll t=i+k1*n;
	t=(t%per+per)%per;
	if(t==0)t=per;
	return t;
}
ll Calc(ll mid){
	ll t=mid/per*cnt;
	if(mid%per==0)return t;
	mid%=per,t+=mid;
	for(int i=1;i<=n;i++){
		if(!posb[a[i]]||i%g!=posb[a[i]]%g)continue;
		if(sml[i]<=mid)t--;
	}
	return t;
}
int main(){
	cin>>n>>m>>K,g=__gcd(n,m),cnt=per=1ll*n*m/g;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),posa[a[i]]=i;
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),posb[b[i]]=i;
	for(int i=1;i<=n;i++){
		if(!posb[a[i]]||i%g!=posb[a[i]]%g)continue;
		cnt--,sml[i]=Calc(i,posb[a[i]]);
	}
	ll l=0,r=1e18,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(Calc(mid)>=K)ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}