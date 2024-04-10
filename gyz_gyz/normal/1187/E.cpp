#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=1e9+7;
int n,f[N];ll sz[N],ds[N],pf[N];vector<int>p[N];
void dfs(int x){sz[x]=ds[x]=1;
	for(auto &i:p[x])if(i!=f[x]){
		f[i]=x;dfs(i);sz[x]+=sz[i];
		ds[x]+=sz[i]+ds[i];
	}
}
void dp(int x){
	if(x>1){
		pf[x]=pf[f[x]]+ds[f[x]]-ds[x]-sz[x]+(n-sz[x]);
	}
	for(auto &i:p[x])if(i!=f[x])dp(i);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){int x,y;
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}
	dfs(1);dp(1);ll ans=0;
	rep(i,1,n)ans=max(ans,ds[i]+pf[i]);
	printf("%lld\n",ans);
}