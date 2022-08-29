#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,head[2000002],cnt,deg[2000002],ia,D;
struct edge{int to,next;}e[4000002];
inline void Add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]},head[x]=cnt;
	e[++cnt]=(edge){x,head[y]},head[y]=cnt;
	++deg[x],++deg[y];
}
inline void dfs(re int x,re int y,re int z){
	if(deg[x]==3&&z&&(x^y))D=1;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x,z^1);
}
char s[500002];
int main(){
	t=read();
	while(t--){
		n=read(),m=n;
		for(re int i=1;i<n;++i)Add(read(),read());
		scanf("%s",s+1);
		for(re int i=1;i<=m;++i)if(s[i]=='W')++n,Add(i,n),Add(n,n+1),Add(n,n+2),n+=2;
		for(re int i=1;i<=n;++i)ia|=deg[i]>=4;
		for(re int i=1;i<=n;++i)
			if(deg[i]==3){
				re int o=0;
				for(re int j=head[i];j;j=e[j].next)o+=deg[e[j].to]>=2;
				ia|=o>=2;
			}
		for(re int i=1;i<=n&&(!ia);++i)if(deg[i]==3)dfs(i,i,1),ia|=D;
		puts(ia?"White":"Draw");
		for(re int i=1;i<=n;++i)head[i]=deg[i]=0;cnt=ia=D=0;
	}
}