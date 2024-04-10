#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1200005;
struct edge{int v,nxt;}c[N<<2];
int front[N],ec=-1,dg[N],res[N];
inline void addedge(int u,int v){c[++ec]=(edge){v,front[u]},front[u]=ec;}
bool vis[N],used[N];
void dfs(int x){
	vis[x]=1;
	for(int i=front[x];~i;i=front[x]){
		front[x]=c[i].nxt;int v=c[i].v;
		if(!used[i>>1])used[i>>1]=1,dfs(v),res[i>>1]=i&1;
	}
}
int main(){
	memset(front,-1,sizeof(front));
	int n,m;read(n,m);
	for(int i=1,x,y,z;i<=m;++i){
		read(x,y,z),--z,x+=z*n,y+=z*n;
		++dg[x],++dg[y],addedge(x,y),addedge(y,x);
	}
	int ans=0;for(int i=1;i<=n;++i)ans+=dg[i]%2;
	for(int i=1;i<=n;++i)if(dg[i]%2&&dg[i+n]%2)addedge(i,i+n),addedge(i+n,i),++dg[i],++dg[i+n];
	int rt=n*2+1;for(int i=1;i<=n*2;++i)if(dg[i]%2)addedge(rt,i),addedge(i,rt),++dg[i],++dg[rt];
	for(int i=1;i<=rt;++i)if(!vis[i])dfs(i);
	printf("%d\n",ans);
	for(int i=0;i<m;++i)printf("%d",res[i]+1);
	printf("\n");
	return 0;
}