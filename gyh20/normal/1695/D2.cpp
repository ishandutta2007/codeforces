#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,head[1000002],cnt,f[1000002],d[1000002],ans;
struct edge{
	int to,next;
}e[2000002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]},head[x]=cnt,++d[x];
}   
inline int dfs(re int x,re int y){
	re int s=0;re char v=0;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)++s,v|=dfs(e[i].to,x);
	if(!s)++ans;
	else if(s>1&&v)v=0,--ans;
	return s==0||v;
}
int main(){
    int t=read();
    while(t--){
        for(int i=1;i<=n;++i)d[i]=head[i]=f[i]=0;ans=0,cnt=0;
	n=read();if(n==1){puts("0");continue;}
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);bool ia=0;
	for(re int i=1;i<=n;++i)if(d[i]>2){dfs(i,i);printf("%d\n",ans);ia=1;break;}
	if(!ia)puts("1");
    }
}