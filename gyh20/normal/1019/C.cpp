#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[1000002],cnt,Q[1000002],d[1000002];
char v[1000002],u[1000002];
struct edge{int to,next;}e[2000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=m;++i){
		re int x=read(),y=read();
		add(x,y),++d[y];
	}
	for(re int i=1;i<=n;++i)
		if(v[i])continue;
		else{
			v[i]=u[i]=1;
			for(re int j=head[i];j;j=e[j].next)v[e[j].to]=1;
		}
	for(re int i=n;i;--i)if(u[i])for(re int j=head[i];j;j=e[j].next)u[e[j].to]=0;
	int k=0;
	for(re int i=1;i<=n;++i)if(u[i])++k;
	printf("%d\n",k);
	for(re int i=1;i<=n;++i)if(u[i])printf("%d ",i);
}