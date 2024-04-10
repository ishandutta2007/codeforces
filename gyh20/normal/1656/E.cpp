#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],ans,A,B,Du[100002],mx,dep[100002],head[100002],cnt;
struct edge{
	int to,next;
}e[200002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]},head[x]=cnt;
}
char s[1000002];
inline void dfs(re int x,re int y,re int z){
	dep[x]=z;if(Du[x]>Du[mx])mx=x;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs(e[i].to,x,z^1);
}
signed main(){
	t=read();
	while(t--){
		n=read(),mx=0,cnt=0;
		for(re int i=1;i<=n;++i)a[i]=1,Du[i]=head[i]=0;
		for(re int i=1,x,y;i<n;++i)x=read(),y=read(),++Du[x],++Du[y],add(x,y),add(y,x);
		dfs(1,1,0);
		if(dep[mx]==1){
			for(re int i=1;i<=n;++i)
				if(dep[i]&1)a[i]=1+Du[i];
				else a[i]=1-Du[i]-Du[i];
		}
		else{
			for(re int i=1;i<=n;++i)
				if(dep[i]%2==0)a[i]=1+Du[i];
				else a[i]=1-Du[i]-Du[i];
		}
		for(re int i=1;i<=n;++i)printf("%d ",a[i]);puts("");
	}
}