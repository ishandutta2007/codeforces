#include<bits/stdc++.h>
using namespace std;

const int N=1e5+11;

int n,m;
char s[N];

const int H=26;
namespace Frie{
	int c[N][H],d[N];
	int root=1,cnt=1;
	void insert(){
		int p=root;
		for(char*t=s;*t;++t){
			int b=*t-'a';
			if(!c[p][b])c[p][b]=++cnt;
			p=c[p][b];
		}
		++d[p];
	}
	int so[N],dep[N],mxd[N];
	void dfs(int x){
		mxd[x]=dep[x];
		for(int i=0,y;i<H;++i){
			if(y=c[x][i]){
				dep[y]=dep[x]+1;
				dfs(y);
				if(mxd[y]>mxd[x]){
					mxd[x]=mxd[y];
					so[x]=y;
				}
			}
		}
	}
}
using namespace Frie;
namespace Dp{
	const int MX=N*4;
	int pool[MX],*f[N],*cur=pool+MX-2;
	int dp(int x){
		if(!so[x]){
			f[x]=--cur;
			f[x][0]=d[x];
			return 0;
		}
		int t=0;
		for(int i=0,y;i<H;++i)if((y=c[x][i])!=so[x] && y){
			t=max(t,dp(c[x][i])+1);
		}
		t=max(t,dp(so[x])+1);
		f[x]=--cur;
		int L=mxd[x]-dep[x];
		for(int i=0,y;i<H;++i)if((y=c[x][i])!=so[x] && y){
			int LL=mxd[y]-dep[y];
			for(int j=0;j<=LL;++j)f[x][j+1]+=f[y][j];
		}
		if(x==root)return t;
		if(!(f[x][0]+=d[x])){
			++f[x][0];
			--f[x][t];
			for(;t>=0&&!f[x][t];--t);
		}
		return t;
	}
}

using namespace Dp;
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		insert();
	}
	dfs(1);
	dp(1);
	int L=mxd[1]-dep[1];
	int ans=0;
	for(int i=1;i<=L;++i)ans+=i*f[1][i];
	printf("%d\n",ans);
}