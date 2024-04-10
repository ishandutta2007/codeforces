#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[200002],cnt,a[200002],f[200002][2],t,X;
struct edge{int to,next;}e[400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	f[x][0]=f[x][1]=0;
	if(a[x]==1)f[x][0]=n+1;if(a[x]==2)f[x][1]=n+1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x);
			for(re int o=0;o<2;++o)
				if(min(f[e[i].to][o^1]+1,f[e[i].to][o])+f[x][o]<=X)
					f[x][o]=max(f[x][o],min(f[e[i].to][o^1]+1,f[e[i].to][o]));
				else f[x][o]=n+1;
		}
}
inline bool ck(re int x){
	X=x,dfs(1,1);
	return min(f[1][0],f[1][1])<=x;
} 
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),head[i]=0;cnt=0;
		for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
		re int l=0,r=n,pos=0;
		while(l<=r){
			re int mid=l+r>>1;
			if(ck(mid))pos=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",(pos+3)/2);
	}
}