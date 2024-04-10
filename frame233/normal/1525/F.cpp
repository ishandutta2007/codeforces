#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=55;
typedef long long ll;
bool ban[N<<1],e[N][N];
int M[N],vis[N],T,n;
bool dfs(int x){
	if(vis[x]==T||ban[x])return false;
	vis[x]=T;
	for(int i=1;i<=n;++i)if(!ban[i+n]&&e[x][i]){
		if(!M[i]||dfs(M[i]))return M[i]=x,true;
	}
	return false;
}
int calc(){
	T=1,memset(vis,0,sizeof(vis)),memset(M,0,sizeof(M));
	int ans=0;for(int i=1;i<=n;++i,++T)if(dfs(i))++ans;
	return n-ans;
}
int all[N],pos;
ll dp[N][N];
int opt[N][N],o[N];
int main(){
	int m,k;read(n,m,k);
	for(int i=1,x,y;i<=m;++i)read(x,y),e[x][y]=true;
	int ans=calc(),orig=ans;
	while(ans<n){
		for(int i=1;i<=n+n;++i)if(!ban[i]){
			ban[i]=true;
			if(int tp=calc();tp>ans){
				all[++pos]=i>n?-(i-n):i,ans=tp;
				break;
			}
			else ban[i]=false;
		}
	}
	memset(dp,-63,sizeof(dp)),dp[0][orig]=0;
	for(int i=0;i<k;++i){
		int x,y;read(x,y);
		for(int j=orig;j<=n;++j){
			for(int k=0;j+k<=n;++k)if(j+k>i+1){
				ll w=dp[i][j]+std::max(0LL,x-1LL*k*y);
				if(dp[i+1][j+k]<w)dp[i+1][j+k]=w,opt[i+1][j+k]=k;
			}
		}
	}
	ll res=-1;int cur=0;for(int i=0;i<=n;++i)if(dp[k][i]>res)res=dp[k][i],cur=i;
	for(int i=k;i>0;--i)o[i]=opt[i][cur],cur-=opt[i][cur];
	int p=0;
	std::vector<int> qwq;
	for(int i=1;i<=k;++i){
		for(int j=0;j<o[i];++j)qwq.pb(all[++p]);
		qwq.pb(0);
	}
	printf("%d\n",(int)qwq.size());
	for(auto it:qwq)printf("%d ",it);
	printf("\n");
	return 0;
}