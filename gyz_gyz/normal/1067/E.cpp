#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 1000000
#define mo 998244353
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,x,y,fa[N];ll F[N],f[N],G[N],g[N];
vector<int>p[N];
void dp(int x){F[x]=0;f[x]=1;
	for(auto i:p[x])if(i!=fa[x]){
		fa[i]=x;dp(i);
		G[x]=(G[x]*(f[i]+g[i])*2+F[x]*f[i]+F[i]*(g[x]*2+f[x])+G[i]*g[x]*2+f[x]*f[i])%mo;
		g[x]=(g[x]*(f[i]+g[i])*2+f[x]*f[i])%mo;
		F[x]=(F[x]*(f[i]+g[i]*2)+f[x]*(F[i]+G[i]*2))%mo;
		f[x]=f[x]*(f[i]+g[i]*2)%mo;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	dp(1);
	printf("%lld\n",(F[1]+G[1])*2%mo);
}