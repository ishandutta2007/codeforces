#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[400002],b[400002],ans,head[400002],cnt,rd[400002];
bool vis[400002];
struct edge{
	int to,next,w;
}e[2000002];
inline void add(re int x,re int y,re int z){
	e[++cnt]=(edge){y,head[x],z};
	head[x]=cnt;
}
queue<int>q;
int main(){
	t=read();
	while(t--){
		re int tot=0;cnt=0;
		n=read();m=read();
		for(re int i=1;i<=n;++i)rd[i]=vis[i]=head[i]=0;
		for(re int i=1,x,y,z;i<=m;++i){
			x=read(),y=read(),z=read();
			if(!x){
				add(y,z,1),add(z,y,1);
			}
			else add(y,z,0),++rd[z];
		}
		for(re int i=1;i<=n;++i)if(!rd[i])q.push(i);
		while(!q.empty()){
			re int x=q.front();q.pop();vis[x]=1;
			for(re int i=head[x];i;i=e[i].next){
				if(vis[e[i].to])continue;//printf("%d %d\n",x);
				if(e[i].w)a[++tot]=x,b[tot]=e[i].to;
				else{
					a[++tot]=x,b[tot]=e[i].to;
					--rd[e[i].to];
					if(!rd[e[i].to])q.push(e[i].to);
				}
			}
		}
		if(tot^m)puts("NO");
		else{
			puts("YES");
			for(re int i=1;i<=m;++i){
				printf("%d %d\n",a[i],b[i]);
			}
		}
	}
}