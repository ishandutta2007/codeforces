#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,a[N],b[N]; 
pair<ll,int> check(ll x){
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	int cnt=0;
	ll all=0;
	for(int i=1;i<=n;++i){
		q.push({a[i]-x,1});
		if(b[i]+q.top().first<=0){
			auto [w,t]=q.top();
			q.pop();
			all+=b[i]+w;
			cnt+=t;
			q.push({-b[i],0});
		}
	}
	while(!q.empty())q.pop();
	return make_pair(all,cnt);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	ll l=0,r=1e12+1,ans=0;
	while(l<r){
		ll mid=(l+r)>>1;
		auto [w,t]=check(mid);
		if(t<=m){
			l=mid+1,ans=w+mid*m;
		}
		else{
			r=mid;
		}
	}
	printf("%lld\n",ans);
	return 0;
}