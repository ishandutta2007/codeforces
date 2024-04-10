#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=1e18;
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
int n;
ll a[N],ans;
mt19937 rnd(time(0));
inline ll calc(ll x){
	ll tot=0;
	for(int i=1;i<=n;++i){
		tot+=a[i]<x?x-a[i]:min(a[i]%x,x-a[i]%x);
		if(tot>ans)return inf;
	}
	return tot;
}
void Split(ll x){
	for(ll i=2;i*i<=x;++i){
		if(x%i==0){
			while(x%i==0)x/=i;
			ans=min(ans,calc(i));
		}
	}
	if(x>1)ans=min(ans,calc(x));	
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	ans=inf;
	ans=calc(2);
	for(int i=1;i<=12;++i){
		int u=rnd()%n+1;
		Split(a[u]),Split(a[u]-1),Split(a[u]+1);
	}
	printf("%lld\n",ans);
	return 0;
}