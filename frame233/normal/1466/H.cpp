#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=45,mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
bool vis[N];int n,p[N],cnt[N],nc,a[N],b[N],A,c[1445][N],ss[1445],cc[1445];
std::vector<int> T[1445];
void DFS(int dep,int id){
	if(dep==n+1){if(A!=id)T[A].pb(id);return;}
	for(int i=cnt[dep];i>=a[dep];--i)b[dep]=i,DFS(dep+1,id*(cnt[dep]+1)+i);
}
void dfs(int dep,int id){
	if(dep==n+1){
		for(int i=1;i<=n;++i)c[id][i]=a[i],ss[id]+=a[i]*i,cc[id]+=a[i];
		A=id,DFS(0,0);return;
	}
	for(int i=0;i<=cnt[dep];++i)a[dep]=i,dfs(dep+1,id*(cnt[dep]+1)+i);
}
int dp[1445],f[1445],g[1445],C[N][N],fac[N];
int main(){
	fac[0]=1;for(int i=1;i<N;++i)fac[i]=1LL*fac[i-1]*i%mod;
	for(int i=0;i<N;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	read(n);for(int i=1;i<=n;++i)read(p[i]);
	for(int i=1;i<=n;++i)if(!vis[i]){
		int len=0;for(int u=i;!vis[u];u=p[u])vis[u]=1,++len;
		++cnt[len];
	}
	dfs(1,0);int all=1;for(int i=1;i<=n;++i)all*=cnt[i]+1;
	dp[0]=1;
	for(int st=0;st<all;++st){
		for(auto s:T[st]){
			int coef=0;for(int i=0;i<=ss[st];++i)add(coef,1LL*fac[i]*fac[n-1-i]%mod*C[ss[st]][i]%mod);
			g[s]=ksm(coef,ss[s]-ss[st]);for(int i=1;i<=n;++i)g[s]=1LL*g[s]*C[cnt[i]-c[st][i]][c[s][i]-c[st][i]]%mod;
			(cc[s]-cc[st])&1?add(dp[s],1LL*g[s]*dp[st]%mod):sub(dp[s],1LL*g[s]*dp[st]%mod);
		}
	}
	printf("%d\n",dp[all-1]);
	return 0;
}