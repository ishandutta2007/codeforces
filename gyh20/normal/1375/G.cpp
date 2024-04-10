#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,c[2],head[200002],cnt;
struct edge{int to,next;}e[400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y,re int z){
	++c[z];
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x,z^1);
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
	dfs(1,1,0);
	printf("%d",min(c[0],c[1])-1);
}