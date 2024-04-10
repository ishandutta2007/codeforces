#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[100005],h[100005],cnt[100005],p,k;
struct Pr{
	ll id,days;
};
bool operator <(const Pr i,const Pr j){
	return i.days>j.days;
}
bool Check(ll mid){
	priority_queue<Pr> q;
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)if(mid-a[i]*m<h[i])q.push({i,mid/a[i]});
	for(int i=1;i<=m&&!q.empty();i++){
		for(int j=1;j<=k&&!q.empty();j++){
			Pr tmp=q.top();
			if(tmp.days<i)return 0;
			cnt[tmp.id]++,q.pop();
			if(cnt[tmp.id]*p+mid-a[tmp.id]*m<h[tmp.id])q.push({tmp.id,(cnt[tmp.id]*p+mid)/a[tmp.id]});
		}
	}
	return q.empty();
}
int main(){
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;i++)cin>>h[i]>>a[i];
	ll l=0,r=1e15,mid,ans=1e15;
	while(l<=r){
		mid=(l+r)/2;
		if(Check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans;
}