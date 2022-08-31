#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,head[2002],cnt,a[1002][502],vis[502][502],v[502][502],sum;
char ist[1002],ans[1002];
struct edge{int to,next;}e[1000002];
int main(){
	int t=read();
	while(t--){
		n=read(),cnt=sum=0;
		re int ttt=1;
		re int iaa=1;
		memset(vis,0,sizeof(vis)),memset(ist,0,sizeof(ist)),memset(ans,0,sizeof(ans));
		for(re int i=1;i<=n+n;++i)for(re int j=1;j<=n;++j)a[i][j]=read(),++vis[j][a[i][j]];
		for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)v[i][j]=vis[i][j],iaa&=vis[i][j]==2;
		while(cnt<n){
			while(1){
				re int iii=1;
				for(re int i=1;i<=n+n;++i){
					if(!ist[i]){
						re bool ia=0;
						for(re int j=1;j<=n;++j)ia|=vis[j][a[i][j]]>=100000; 
						if(ia){
							iii=0;
							ist[i]=2;
							re int pos=i;
							for(re int k=1;k<=n;++k)--vis[k][a[pos][k]];
						}
					}
				}
				if(iii)break;
			}
			re int qq=cnt;
			for(re int i=1;i<=n;++i)
				for(re int j=1;j<=n;++j){
					if(vis[i][j]==1){
						re int pos=0;
						for(re int k=1;k<=n+n;++k)if(a[k][i]==j&&!ist[k])pos=k;
						ist[pos]=1;
						++cnt;
						for(re int k=1;k<=n;++k)vis[k][a[pos][k]]=114514;
					}
				}
			if(cnt<=qq){
				ttt=ttt*2%M;
				re int pos;
				for(re int i=1;i<=n+n;++i)if(!ist[i])pos=i;
				ist[pos]=1;
				++cnt;
				for(re int k=1;k<=n;++k)vis[k][a[pos][k]]=114514;
			}
		}
		for(re int i=1;i<=n+n;++i)ans[i]=ist[i];
		assert(cnt==n);
		re int num=0;
		for(re int i=1;i<=n+n;++i)if(ans[i]==1)++num;
		if(num!=n)while(1);
		for(re int i=1;i<=n+n;++i)
		for(re int j=i+1;j<=n+n;++j)
		if(ans[i]==1&&ans[j]==1){
			for(re int k=1;k<=n;++k)assert(a[i][k]!=a[j][k]);
		}
		
		printf("%d\n",ttt);
		for(re int i=1;i<=n+n;++i)if(ans[i]==1)printf("%d ",i);
		puts("");
	}
}