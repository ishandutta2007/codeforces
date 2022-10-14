#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1;
int n,m,tot;
vector<ll>t[N],tmp;
ll ans=1,now,val[N],w[N],h[N],c[N];
ll gcd(ll x,ll y){return!y?x:gcd(y,x%y);}
V init(ll*a){
	FOR(i,1,n)val[++tot]=a[i];
	sort(val+1,val+1+tot),tot=unique(val+1,val+1+tot)-val-1;
	FOR(i,1,n)a[i]=lower_bound(val+1,val+1+tot,a[i])-val;
}
V GG(){cout<<0,exit(0);}
ll solve(vector<ll>&a){
	ll d=0;
	FOR(i,1,m)if(d=gcd(a[i],d),!a[i])GG();
	FOR(i,1,m)if((a[i]/=d)!=t[1][i])GG();
	return d;
}
int main(){
	scanf("%d",&n);
	FOR(i,1,n)scanf("%lld%lld%lld",w+i,h+i,c+i);
	if(init(h),swap(m,tot),init(w),1ll*m*tot>n)GG();
	FOR(i,1,tot)t[i].resize(m+1);
	FOR(i,1,n)t[w[i]][h[i]]=c[i];
	FOR(i,1,tot)now=gcd(solve(t[i]),now);
	for(int p=2,c;1ll*p*p<=now;p++,ans*=c+1)for(c=0;now%p==0;c++)now/=p;
	return cout<<ans*((now>1)+1),0;
}