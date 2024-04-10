#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1005;typedef std::pair<int,int> pi;
int a[N];bool mark[N];
struct edge{int v,nxt,w;}c[N*N*2];
int front[N],ec=-1;
inline void addedge(int u,int v,int w){
	c[++ec]=(edge){v,front[u],w},front[u]=ec;
	c[++ec]=(edge){u,front[v],0},front[v]=ec;
}
int _q[N],_l,_r,dep[N],S,T,cur[N],nc;
bool bfs(){
	memset(dep,-1,(nc+3)<<2),memcpy(cur,front,(nc+3)<<2),dep[S]=0,_q[_l=_r=1]=S;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(int i=cur[x];~i;i=c[i].nxt)if(c[i].w){
			int v=c[i].v;
			if(dep[v]==-1){
				dep[v]=dep[x]+1,_q[++_r]=v;
				if(v==T)return 1;
			}
		}
	}
	return 0;
}
int dfs(int x,int flow){
	if(x==T||!flow)return flow;
	int f=0,rf;
	for(int &i=cur[x];~i;i=c[i].nxt)if(c[i].w){
		int v=c[i].v;
		if(dep[v]==dep[x]+1&&(rf=dfs(v,std::min(flow,c[i].w)))){
			flow-=rf,f+=rf,c[i].w-=rf,c[i^1].w+=rf;
			if(!flow)return f;
		}
	}
	return f;
}
int dinic(){int ans=0;while(bfs())ans+=dfs(S,1e9);return ans;}
int main(){
	memset(front,-1,sizeof(front));
	int n,m;read(n,m),S=n+1,T=S+1,nc=T;
	for(int i=1;i<=n;++i)read(a[i]);
	std::sort(a+1,a+n+1);std::vector<pi> ans;int tmp=0;
	for(int i=n;i>=1;--i)if(a[i]>m/3){
		if(a[i]>m/2)return puts("-1"),0;
		addedge(S,i,1),++tmp;
		for(int j=1;j<i;++j)if(2*a[i]+a[j]<=m&&a[i]%a[j]==0)addedge(i,j,1);
	}
	else addedge(i,T,1);
	if(dinic()!=tmp)return puts("-1"),0;
	for(int i=n;i>=1;--i)if(a[i]>m/3){
		for(int _=front[i];~_;_=c[_].nxt)if(c[_].w==0&&c[_].v!=S){
			int j=c[_].v;mark[i]=mark[j]=1;
			ans.pb({2*a[i]+a[j],a[i]+a[j]});
		}
	}
	for(int i=1;i<=n;++i)if(!mark[i])ans.pb({3*a[i],2*a[i]});
	printf("%d\n",SZ(ans));
	for(const auto &it:ans)printf("%d %d\n",it.first,it.second);
	return 0;
}