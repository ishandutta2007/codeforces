#include<bits/stdc++.h>
#define re register
using namespace std;
int n,m,col[400002],head[400002],cnt,d[400002];
struct edge{int to,next,w;}e[400002];
inline void add(re int x,re int y,re int w){
	e[++cnt]=(edge){y,head[x],w},++d[y];
	head[x]=cnt;
}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline void dfs(re int x,re int y){
	for(re int &i=head[x];i;i=e[i].next)
		if(!col[e[i].w]){
			col[e[i].w]=y;
			dfs(e[i].to,y^1);
			return;
		}
}
int main(){
	n=read();
	for(re int i=1,x,y;i<=n;++i){
		x=read(),y=read();
		add(x,y+200000,i),add(y+200000,x,i);
	}
	for(re int i=1;i<=400000;++i)if(d[i]&1)dfs(i,2);
	for(re int i=1;i<=400000;++i)dfs(i,2);
	for(re int i=1;i<=n;++i)if(col[i]==2)putchar('r');else putchar('b');
}