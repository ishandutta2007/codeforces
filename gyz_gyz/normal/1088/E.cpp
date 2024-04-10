#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,f[N];ll a[N],b[N],mx,ct;vector<int>p[N];
void vil(){
	ll mx=-inf,ct=0;
	rep(i,1,n){
		if(a[i]==mx)ct++;
		if(a[i]>mx)mx=a[i],ct=1;
	}
	if(mx<=0){
		printf("%lld %lld\n",mx*ct,ct);exit(0);
	}
}
void dp(int x){
	for(auto i:p[x])if(i!=f[x])f[i]=x,dp(i);
	if(b[x]<a[x]&&a[x]==mx)ct++;
	if(a[x]>mx)mx=a[x],ct=1;b[x]=max(a[x],b[x]);
	if(f[x]&&a[x]>0){
		a[f[x]]+=a[x];b[f[x]]=max(b[f[x]],b[x]);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]);vil();
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}dp(1);
	printf("%lld %lld\n",mx*ct,ct);
}