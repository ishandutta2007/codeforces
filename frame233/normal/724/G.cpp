#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod=1000000007;typedef long long ll;typedef std::pair<int,ll> pr;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
std::vector<pr> e[N];std::vector<int> son[N];
int dfn[N],id;ll f[N],d[60];
void ins(ll x){
	for(int i=59;i>=0;--i)if(x>>i&1){
		if(d[i])x^=d[i];
		else return d[i]=x,void();
	}
}
void dfs(int x,int fa){
	dfn[x]=++id;
	for(const auto &it:e[x]){
		int v=it.first;ll w=it.second;if(v==fa)continue;
		if(!dfn[v])f[v]=f[x]^w,son[x].pb(v),dfs(v,x);else if(dfn[v]<dfn[x])ins(f[x]^f[v]^w);
	}
}
int dp[N][60][2],c[60][2],c0[60],c1[60],pw[61];
void DFS(int x){
	for(int i=0;i<60;++i)dp[x][i][f[x]>>i&1]=1;
	for(auto v:son[x]){
		DFS(v);
		for(int i=0;i<60;++i){
			add(c[i][0],(1LL*dp[x][i][0]*dp[v][i][0]+1LL*dp[x][i][1]*dp[v][i][1])%mod);
			add(c[i][1],(1LL*dp[x][i][0]*dp[v][i][1]+1LL*dp[x][i][1]*dp[v][i][0])%mod);
			add(dp[x][i][0],dp[v][i][0]),add(dp[x][i][1],dp[v][i][1]);
		}
	}
}
int main(){
	pw[0]=1;for(int i=1;i<=60;++i)pw[i]=2LL*pw[i-1]%mod;
	int n,m;read(n,m);ll z;int ans=0;
	for(int i=1,x,y;i<=m;++i)read(x,y,z),e[x].pb({y,z}),e[y].pb({x,z});
	for(int i=1;i<=n;++i)if(!dfn[i]){
		memset(c,0,sizeof(c)),memset(d,0,sizeof(d)),dfs(i,0),DFS(i);
		memset(c0,0,sizeof(c0)),memset(c1,0,sizeof(c1));
		for(int j=0;j<60;++j)if(d[j])for(int k=0;k<60;++k)++(d[j]>>k&1?c1[k]:c0[k]);
		for(int j=0;j<60;++j){
			if(c1[j])add(ans,(1LL<<j)%mod*pw[c0[j]+c1[j]-1]%mod*(c[j][0]+c[j][1])%mod);
			else add(ans,(1LL<<j)%mod*pw[c0[j]]%mod*c[j][1]%mod);
		}
	}
	printf("%d\n",ans);
	return 0;
}