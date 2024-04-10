#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[100002],cnt,d[100002],num[100002],v[200002],p[100002],A[100002],B[100002],ID[100002],S[100002],dep[100002],k;
struct edge{int to,next;}e[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	v[x]=1,dep[x]=dep[y]+1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			if(!v[e[i].to])dfs(e[i].to,x),d[x]^=d[e[i].to],num[x]+=num[e[i].to],ID[e[i].to]=i+1>>1;
			else if(dep[e[i].to]<dep[x])S[i+1>>1]=dep[x]-dep[e[i].to],++num[x],--num[e[i].to],d[x]^=i+1>>1,d[e[i].to]^=i+1>>1;
		}
	if(num[x]==1)--S[d[x]];
}
int main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<=m;++i)x=A[i]=read(),y=B[i]=read(),add(x,y),add(y,x),S[i]=-1;
	for(re int i=1;i<=n;++i)if(!v[i])dfs(i,i);
	for(re int i=1;i<=n;++i)if(num[i]==1&&S[d[i]]==0)p[++k]=ID[i];
	for(re int i=1;i<=m;++i)if(S[i]==0)p[++k]=i;sort(p+1,p+k+1);
	printf("%d\n",k);
	for(re int i=1;i<=k;++i)printf("%d ",p[i]);
}