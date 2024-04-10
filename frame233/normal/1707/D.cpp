#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005;int mod,n;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
std::vector<int> e[N];int dp[N][N],presum[N][N],pre[N][N],suf[N][N],tmp[N],C[N][N],f[N];
void dfs(int x,int fa){
	std::vector<int> son;for(auto v:e[x])if(v!=fa)son.pb(v),dfs(v,x);
	for(int i=0;i<SZ(son);++i)for(int j=1;j<=n;++j)pre[i][j]=suf[i][j]=presum[son[i]][j];
	for(int i=1;i<SZ(son);++i)for(int j=1;j<=n;++j)pre[i][j]=1LL*pre[i-1][j]*pre[i][j]%mod;
	for(int i=SZ(son)-2;i>=0;--i)for(int j=1;j<=n;++j)suf[i][j]=1LL*suf[i+1][j]*suf[i][j]%mod;
	for(int t=0;t<SZ(son);++t){
		int v=son[t];
		for(int j=1;j<=n;++j)tmp[j]=(1LL*(t?pre[t-1][j]:1)*(t+1<SZ(son)?suf[t+1][j]:1)+tmp[j-1])%mod;
		for(int i=2;i<=n;++i)add(dp[x][i],1LL*dp[v][i]*tmp[i-1]%mod);
	}
	if(!son.empty())for(int i=1;i<=n;++i)add(dp[x][i],suf[0][i]);
	else for(int i=1;i<=n;++i)dp[x][i]=1;
	for(int i=1;i<=n;++i)presum[x][i]=presum[x][i-1],add(presum[x][i],dp[x][i]);
}
int main(){
	read(n,mod);
	for(int i=0;i<N;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	for(int i=1,x,y;i<n;++i)read(x,y),e[x].pb(y),e[y].pb(x);
	dfs(1,0);for(int i=1;i<=n;++i)f[i]=suf[0][i];
	for(int i=1;i<n;++i){
		int ans=0;
		for(int j=1;j<=i;++j){
			int tmp=1LL*C[i][j]*f[j]%mod;
			(i-j)%2?sub(ans,tmp):add(ans,tmp);
		}
		printf("%d%c",ans," \n"[i+1==n]);
	}
	return 0;
}