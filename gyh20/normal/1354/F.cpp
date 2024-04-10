#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int f[76][76],n,m,t,v[76][76],ans[76],cnt,pos;
struct node{int x,y,id;bool operator <(const node a)const{return y<a.y;};}p[76];
inline void dfs(re int x,re int y){
	if(!x)return;
	if(v[x][y])ans[x]=1,--y;
	dfs(x-1,y);
}
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n;++i)p[i].x=read(),p[i].y=read(),p[i].id=i;
		sort(p+1,p+n+1),memset(v,0,sizeof(v)),memset(f,-0x3f,sizeof(f));f[0][0]=0;
		for(re int i=1;i<=n;++i)
			for(re int j=0;j<=min(i,m);++j){
				f[i][j]=f[i-1][j]+p[i].y*(m-1);
				if(j&&f[i-1][j-1]+p[i].x+p[i].y*(j-1)>f[i][j])f[i][j]=f[i-1][j-1]+p[i].x+p[i].y*(j-1),v[i][j]=1;
			}
		printf("%d\n",m+(n-m)*2);cnt=0;
		memset(ans,0,sizeof(ans)),dfs(n,m);
		for(re int i=1;i<=n;++i)if(ans[i]&&(++cnt!=m))printf("%d ",p[i].id);else if(ans[i])pos=i;
		for(re int i=1;i<=n;++i)if(!ans[i])printf("%d %d ",p[i].id,-p[i].id);
		printf("%d\n",p[pos].id);
	}
}