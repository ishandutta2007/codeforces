#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=500005;typedef std::pair<int,int> pi;
int u[N],v[N],a[N],fa[N],dg[N];
std::vector<int> nd[N],e[N];std::vector<pi> E[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int len;void dfs(int x,int fa){++len;for(auto v:e[x])if(v!=fa)dfs(v,x);}
void DFS(int x,int fa,int cur,int d){
	if(cur<=d)return;
	a[x]=cur-=d;for(auto v:e[x])if(v!=fa)DFS(v,x,cur,d);
}
void MAIN(){
	int n,m;read(n,m);
	for(int i=1;i<=n;++i)fa[i]=i,dg[i]=0,nd[i].clear(),E[i].clear(),e[i].clear();
	for(int i=1;i<=m;++i)read(u[i],v[i]),fa[find(u[i])]=find(v[i]),++dg[u[i]],++dg[v[i]],e[u[i]].pb(v[i]),e[v[i]].pb(u[i]);
	for(int i=1;i<=n;++i)nd[find(i)].pb(i);
	for(int i=1;i<=m;++i)E[find(u[i])].pb({u[i],v[i]});
	bool flag=0;
	for(int i=1;i<=n;++i)if(fa[i]==i){
		for(auto it:nd[i])a[it]=dg[it]==1?1:2;
		int s1=0,s2=0;for(auto it:nd[i])s1+=a[it]*a[it];
		for(const auto &it:E[i])s2+=a[it.first]*a[it.second];
		if(s1<=s2){
			puts("YES"),flag=1;
			for(int j=1;j<=n;++j)printf("%d%c",find(j)==i?a[j]:0," \n"[j==n]);
			break;
		}
		for(auto it:nd[i])a[it]=0;
		for(auto x:nd[i])if(SZ(e[x])==3){
			memset(a,0,(n+3)<<2);
			std::vector<int> L(3);
			len=0,dfs(e[x][0],x);L[0]=len;
			len=0,dfs(e[x][1],x);L[1]=len;
			len=0,dfs(e[x][2],x);L[2]=len;
			for(int i=0;i<3;++i)for(int j=0;j<2;++j)if(L[j]>L[j+1])std::swap(L[j],L[j+1]),std::swap(e[x][j],e[x][j+1]);
			bool tag=0;
			if(L[0]==1){
				if((L[1]==2&&L[2]>=5)||L[1]>=3){
					a[x]=60,a[e[x][0]]=30,tag=1;
					if(L[1]==2)DFS(e[x][1],x,60,20),DFS(e[x][2],x,60,10);
					else DFS(e[x][1],x,60,15),DFS(e[x][2],x,60,15);
				}
			}
			else{
				a[x]=3,tag=1;
				for(auto v:e[x]){a[v]=2;for(auto w:e[v])if(w!=x)a[w]=1;}
			}
			if(tag){
				puts("YES"),flag=1;
				for(int j=1;j<=n;++j)printf("%d%c",find(j)==i?a[j]:0," \n"[j==n]);
				break;
			}
		}
		if(flag)break;
	}
	if(!flag)puts("NO");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}