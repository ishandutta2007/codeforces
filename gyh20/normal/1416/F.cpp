#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int p[100006],n,m,head[100006],cnt=1,S,T,v[100006],dis[100006],ans1,ans2,t,N[100006],h1[100006],O[100006],Q[2000002],hd,tl;
vector<int>a[100002];
char vis[100005];
deque<int>q;
struct edge{int to,next,w,w1;}e[1000002];
inline void add(re int x,re int y,re int z,re int w,re int w1=0){if(O[x]==0&&O[y]==0)return;e[++cnt]=(edge){y,head[x],z,w},head[x]=cnt;e[++cnt]=(edge){x,head[y],w1,-w},head[y]=cnt;}
inline bool spfa(){
	memset(dis,-0x3f,sizeof(dis));
	dis[S]=0,v[S]=1;
	Q[hd=tl=1000000]=S;
	while(hd<=tl){
		re int x=Q[hd++];v[x]=0;
		for(re int i=head[x];i;i=e[i].next)
			if(e[i].w&&dis[x]+e[i].w1>dis[e[i].to]){
				dis[e[i].to]=dis[x]+e[i].w1,p[e[i].to]=i;
				if(!v[e[i].to]){
					v[e[i].to]=1;
					if(hd<=tl&&dis[e[i].to]>=dis[Q[hd]])Q[--hd]=e[i].to; 
					else Q[++tl]=e[i].to;
				}
			}
	}
	return dis[T]>0;
}
inline int dfs(re int x,re int y){
	if(x==T)return y;
	vis[x]=1;
	re int dlt=0;
	for(re int i=head[x];y&&(head[x]=i);i=e[i].next)
		if(dis[e[i].to]==dis[x]+e[i].w1&&e[i].w&&!vis[e[i].to]){
			re int z=dfs(e[i].to,min(y,e[i].w));
			if(!z)dis[e[i].to]=-1;
			else e[i].w-=z,y-=z,e[i^1].w+=z,dlt+=z,ans2+=z*e[i].w1;
		}vis[x]=0;
	return dlt;
}
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),cnt=1,S=n*m+1,T=n*m+2;
		for(re int i=1;i<=T;++i)head[i]=0,N[i]=0,O[i]=0;O[S]=O[T]=1;
		re int ss=0;
		for(re int i=1;i<=n;++i){
			a[i].resize(m+1);
			for(re int j=1;j<=m;++j)
				a[i][j]=read();
		}
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j){
				re bool ia=0;
				if(i>1){
					ia|=a[i][j]>a[i-1][j];
				}
				if(j>1){
					ia|=a[i][j]>a[i][j-1];
				}
				if(i<n){
					ia|=a[i][j]>a[i+1][j];
				}
				if(j<m){
					ia|=a[i][j]>a[i][j+1];
				}ss+=ia^1;
				if((i+j)&1)add(S,(i-1)*m+j,1,ia^1);
				else add((i-1)*m+j,T,1,ia^1);
				O[(i-1)*m+j]=ia^1;
			}
		for(re int i=1;i<=n;++i)
			for(re int j=1;j<=m;++j){
				re bool ia=0;
				if(i>1){
					ia|=a[i][j]>a[i-1][j];
					if(a[i][j]==a[i-1][j]){
						if(i+j&1)add((i-1)*m+j,(i-2)*m+j,1,0);
					}
				}
				if(j>1){
					ia|=a[i][j]>a[i][j-1];
					if(a[i][j]==a[i][j-1]){
						if(i+j&1)add((i-1)*m+j,(i-1)*m+j-1,1,0);
					}
				}
				if(i<n){
					ia|=a[i][j]>a[i+1][j];
					if(a[i][j]==a[i+1][j]){
						if(i+j&1)add((i-1)*m+j,i*m+j,1,0);
					}
				}
				if(j<m){
					ia|=a[i][j]>a[i][j+1];
					if(a[i][j]==a[i][j+1]){
						if(i+j&1)add((i-1)*m+j,(i-1)*m+j+1,1,0);
					}
				}
			}
		ans1=ans2=0;
		while(spfa()){
			for(re int i=1;i<=T;++i)h1[i]=head[i];
			dfs(S,n*m);
			for(re int i=1;i<=T;++i)head[i]=h1[i];
		}
		if(ans2!=ss)puts("NO");
		else{
			for(re int i=1;i<=n;++i)
				for(re int j=1;j<=m;++j){
					re int x=(i-1)*m+j;
					if((i+j)&1){
						for(re int k=head[x];k;k=e[k].next)
							if(e[k].to!=S&&!e[k].w)
								N[x]=e[k].to;
					}
					else{
						for(re int k=head[x];k;k=e[k].next)
							if(e[k].to!=T&&!e[k^1].w)
								N[x]=e[k].to;
					}
				}
			puts("YES");
			for(re int i=1;i<=n;++i,puts(""))
				for(re int j=1;j<=m;++j){
					re int x=(i-1)*m+j,X=(N[x]-1)/m+1,Y=(N[x]-1)%m+1;
					if(N[x])printf("%d ",(a[i][j]+((i+j)&1))>>1);
					else{
						if(i>1&&a[i][j]>a[i-1][j])printf("%d ",a[i][j]-a[i-1][j]);
						else if(j>1&&a[i][j]>a[i][j-1])printf("%d ",a[i][j]-a[i][j-1]);
						else if(i<n&&a[i][j]>a[i+1][j])printf("%d ",a[i][j]-a[i+1][j]);
						else if(j<m&&a[i][j]>a[i][j+1])printf("%d ",a[i][j]-a[i][j+1]);
					}
				}
			for(re int i=1;i<=n;++i,puts(""))
				for(re int j=1;j<=m;++j){
					re int x=(i-1)*m+j,X=(N[x]-1)/m+1,Y=(N[x]-1)%m+1;
					if(N[x]){
						if(X<i)printf("U ");
						else if(X>i)printf("D ");
						else if(Y<j)printf("L ");
						else printf("R ");
					}
					else{
						if(i>1&&a[i][j]>a[i-1][j])printf("U ");
						else if(j>1&&a[i][j]>a[i][j-1])printf("L ");
						else if(i<n&&a[i][j]>a[i+1][j])printf("D ");
						else if(j<m&&a[i][j]>a[i][j+1])printf("R ");
					}
				}
		}
	}
}