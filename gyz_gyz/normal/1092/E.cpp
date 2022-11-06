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
int n,m,r,tot,ans,s[N],d[N],w[N];bool v[N];
vector<int>p[N];
int sol(int x){
	int r=x;v[x]=1;
	for(auto i:p[x])if(!v[i]){
		int t=sol(i);
		if(w[t]<w[r])r=t;
	}return r;
}
void ddfs(int x){
	ans=max(ans,d[x]);
	for(auto i:p[x])if(d[i]==-1){
		d[i]=d[x]+1;ddfs(i);
	}
}
void dfs(int r,int x){
	w[r]=max(w[r],d[x]);
	for(auto i:p[x])if(d[i]==-1){
		d[i]=d[x]+1;dfs(r,i);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	rep(i,1,n){
		rep(j,1,n)d[j]=-1;
		d[i]=0;dfs(i,i);
	}
	rep(i,1,n)if(!v[i]){
		int x=sol(i);s[++tot]=x;
		if(!r||w[x]>w[r])r=x;
	}
	rep(i,1,tot)if(s[i]!=r){
		p[s[i]].pb(r);p[r].pb(s[i]);
	}
	rep(i,1,n){
		rep(j,1,n)d[j]=-1;d[i]=0;ddfs(i);
	}
	printf("%d\n",ans);
	rep(i,1,tot)if(s[i]!=r)printf("%d %d\n",s[i],r);
}