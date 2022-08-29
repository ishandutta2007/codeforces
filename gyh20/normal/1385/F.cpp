#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[200002],b[200002],ans,head[200002],cnt,rd[200002],siz[200002];
bool vis[200002];
struct edge{
	int to,next;
}e[400002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;++rd[y];
}
queue<int>q;
int main(){
	t=read();
	while(t--){
		re int tot=0;ans=0;
		n=read();m=read();
		for(re int i=1;i<=n;++i)rd[i]=vis[i]=head[i]=siz[i]=0;
		for(re int i=1,x,y,z;i<n;++i){
			x=read(),y=read();
			add(x,y),add(y,x);
		}if(m==1){
			printf("%d\n",n-1);continue;
		}
		for(re int i=1;i<=n;++i)if(rd[i]==1){
		for(re int j=head[i];j;j=e[j].next)++siz[e[j].to];vis[i]=1;}
		for(re int i=1;i<=n;++i)if(siz[i]&&(siz[i]%m==0)&&(rd[i]-siz[i]==1))q.push(i);
		while(!q.empty()){
			re int x=q.front();q.pop();if(vis[x])continue;
			ans+=siz[x]/m;vis[x]=1;
			for(re int i=head[x];i;i=e[i].next)
				if(!vis[e[i].to]){
					++siz[e[i].to];
					if(siz[e[i].to]%m==0&&siz[e[i].to]==rd[e[i].to]-1)q.push(e[i].to);
				}
		}
		for(re int i=1;i<=n;++i)if(!vis[i])ans+=siz[i]/m;
		printf("%d\n",ans);
	}
}