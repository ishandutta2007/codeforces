#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,s1,s2;ll ans;
bool v[N],c[N];vector<int>p[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
void dfs(int x){v[x]=1;
	if(c[x])s2++;else s1++;
	for(auto i:p[x])if(!v[i]){
		c[i]=c[x]^1;dfs(i);
	}
}
void sol(){
	scanf("%d%d",&n,&m);ans=1;
	rep(i,1,n)v[i]=c[i]=0,p[i].clear();
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	rep(i,1,n)if(!v[i]){
		s1=s2=0;dfs(i);
		ans=ans*(qk(2,s1)+qk(2,s2))%mo;
	}
	rep(i,1,n)for(auto j:p[i])if(c[i]==c[j]){
		printf("0\n");return;
	}
	printf("%lld\n",ans);
}
int main(){int T;
	for(scanf("%d",&T);T;T--)sol();
}