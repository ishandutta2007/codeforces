#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500005],b[500005],n,K;
ll A;
int Check(ll mid){
	priority_queue<ll,vector<ll>,greater<ll> > q;
	int ret=0;
	A=0;
	for(int i=1;i<=n;i++){
		if(a[i]+mid<0)q.push(a[i]*2+1);
		if(!q.size())continue;
		ll ww=q.top();
		if((ww/2)+b[i]+mid>=0)continue;
		q.pop();
		A+=(ww/2)+b[i]+mid,ret+=abs(ww%2),q.push((-mid-b[i])*2);
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&K); 
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	ll l=-2e9,r=0,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(Check(mid)<=K)r=mid-1,ans=mid;
		else l=mid+1;
	}
	Check(ans),printf("%lld\n",A-ans*K);
}