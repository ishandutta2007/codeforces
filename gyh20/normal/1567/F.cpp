#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
char s[502][502];
int n,m,head[250002],cnt,col[250002],ans[502][502];
struct edge{int to,next;}e[500002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	col[x]=y;
	for(re int i=head[x];i;i=e[i].next)
		if(!col[e[i].to])
			dfs(e[i].to,y^1);
}
inline int pos(re int x,re int y){return (x-1)*m+y;}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)if(s[i][j]=='X'){
			re int o=(s[i][j-1]=='.')+(s[i][j+1]=='.')+(s[i-1][j]=='.')+(s[i+1][j]=='.');ans[i][j]=o*5/2;
			if(o&1)return puts("NO"),0;
			if(o==4)add(pos(i,j-1),pos(i-1,j)),add(pos(i-1,j),pos(i,j-1)),add(pos(i,j+1),pos(i+1,j)),add(pos(i+1,j),pos(i,j+1));
			else{
				re int p1=0,p2=0;
				if(s[i][j-1]=='.')p1=pos(i,j-1);
				if(s[i][j+1]=='.')p2=p1,p1=pos(i,j+1);
				if(s[i+1][j]=='.')p2=p1,p1=pos(i+1,j);
				if(s[i-1][j]=='.')p2=p1,p1=pos(i-1,j);
				add(p1,p2),add(p2,p1);
			}
		}
	for(re int i=1;i<=n*m;++i)if(!col[i])dfs(i,2);
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			if(s[i][j]=='.')
				ans[i][j]=col[pos(i,j)]*2%5;
	puts("YES");
	for(re int i=1;i<=n;++i,puts(""))
		for(re int j=1;j<=m;++j)
			printf("%d ",ans[i][j]);
}