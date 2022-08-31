#include<cstdio>
#define re register
int n,m,a[100002],d[100002],head[100002],cnt=1,las,k;
bool v[800002];
struct edge{int to,next;}e[800002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x){
	for(re int &i=head[x];i;i=e[i].next){
		if(v[i])continue;
		v[i]=v[i^1]=1;
		re int tmp=e[i].to;
		dfs(tmp);
		if((++k)&1)printf("%d %d\n",x,tmp);
		else printf("%d %d\n",tmp,x);
	}
}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read(),add(x,y),add(y,x);
		++d[x],++d[y];
	}
	for(re int i=1;i<=n;++i)
		if(d[i]&1){
			if(las)++m,add(las,i),add(i,las),las=0;
			else las=i;
		}
	if(m&1)add(1,1),++m;
	printf("%d\n",m),dfs(1);
}