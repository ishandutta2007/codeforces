#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 300000
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,f[N];vector<int>p[N];
ll w[N],s[N],a[N],b[N],ans;
void dfs(int x){s[x]=w[x];
	for(auto i:p[x])if(i!=f[x]){
		f[i]=x;dfs(i);
		a[x]+=a[i]+s[i];s[x]+=s[i];
	}
}
void dp(int x){
	if(x>1)b[x]=s[1]-s[x]*2+b[f[x]]+a[f[x]]-a[x];
	for(auto i:p[x])if(i!=f[x])dp(i);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&w[i]);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	dfs(1);dp(1);
	rep(i,1,n)ans=max(ans,a[i]+b[i]);
	printf("%lld\n",ans);
}