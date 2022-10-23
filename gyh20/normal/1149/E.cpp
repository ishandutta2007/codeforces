// LUOGU_RID: 90911836
#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[200002],cnt,h[200002],a[200002],deg[200002],Q[200002],hd,tl,S[200002];
struct edge{int to,next;}e[200002];
map<int,int>V[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt,++deg[y];}
int main(){
	n=read(),m=read(),hd=1;
	for(re int i=1;i<=n;++i)h[i]=read(); 
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(y,x);
	for(re int i=1;i<=n;++i)if(!deg[i])Q[++tl]=i;
	while(hd<=tl){
		re int x=Q[hd++];
		while(V[x][a[x]])++a[x];  
		S[a[x]]^=h[x];
		for(re int i=head[x];i;i=e[i].next){
			V[e[i].to][a[x]]=1;
			if(!(--deg[e[i].to]))Q[++tl]=e[i].to;
		}
	}
	int pos=-1;
	for(re int i=0;i<=n;++i)if(S[i])pos=i;
	if(pos==-1)puts("LOSE");
	else{
		puts("WIN");
		for(re int i=0;i<=n;++i)
			if(a[i]==pos&&(h[i]^S[pos])<=h[i]){
				h[i]^=S[pos];
				for(re int j=1;j<=n;++j)for(re int k=head[j];k;k=e[k].next)if(e[k].to==i)h[j]^=S[a[j]],S[a[j]]=0;
				break;
			}
		for(re int i=1;i<=n;++i)printf("%d ",h[i]);
	}
}