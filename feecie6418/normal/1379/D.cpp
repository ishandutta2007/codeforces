/*
train
tram
train
tram 
*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,h,a[200005],c[14000005][2],sum[14000005],tot,rt,minn=1e9,minp;
void Upd(ll &p,ll l,ll r,ll x,ll y){
	if(!p)p=++tot;
	if(x<=l&&r<=y){
		sum[p]++;
		return ;
	}
	ll mid=(l+r)/2;
	if(x<=mid)Upd(c[p][0],l,mid,x,y);
	if(mid<y)Upd(c[p][1],mid+1,r,x,y);
}
void dfs(ll p,ll l,ll r,ll ns){
	if(!p)return ;
	if(!(c[p][0]||c[p][1])){
		if(ns+sum[p]<minn)minn=ns+sum[p],minp=l;
		return ;
	}
	ll mid=(l+r)/2;
	if(c[p][0])dfs(c[p][0],l,mid,ns+sum[p]);
	else if(ns+sum[p]<minn)minn=ns+sum[p],minp=l;
	if(c[p][1])dfs(c[p][1],mid+1,r,ns+sum[p]);
	else if(ns+sum[p]<minn)minn=ns+sum[p],minp=mid+1;
}
int main(){
	cin>>n>>h>>m>>k;
	if(k==1)return cout<<"0 0"<<endl,0;
	for(int i=1;i<=n;i++){
		ll x,y;
		cin>>x>>y;
		a[i]=(x*m+y)%(m/2)+1;
		ll tmp=a[i]+1,tmp2=a[i]+k-1;
		if(tmp2<=m/2)Upd(rt,1,m/2,tmp,tmp2);
		else Upd(rt,1,m/2,tmp,m/2),Upd(rt,1,m/2,1,tmp2-m/2);
		//if(a[i]<k)a[i]+=h*m;
	}
	dfs(rt,1,m/2,0);
	cout<<minn<<' '<<minp-1<<endl;
	for(int i=1;i<=n;i++){
		ll tmp=minp+m/2-k+1,tmp2=minp-1;
		if(tmp-m/2>=1)tmp-=m/2;
		if(tmp2==0)tmp2=m/2;
	//	cout<<tmp<<' '<<tmp2<<' '<<a[i]<<endl;
		if(tmp<=tmp2){
			if(a[i]>=tmp&&a[i]<=tmp2)cout<<i<<' ';
		}
		else if(a[i]>=tmp||a[i]<=tmp2)cout<<i<<' ';
	}
}