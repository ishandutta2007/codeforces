#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,x) for(auto i:x)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 1000001
int N,M,K,a[MAXN],top,sta[MAXN][2],fa[MAXN],siz[MAXN],lim[MAXN];ll ans;map<Pair,vector<Pair> >e;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getf(int x){return fa[x]==x?x:getf(fa[x]);}
void mrg(int x,int y){if((x=getf(x))==(y=getf(y)))return;if(siz[x]>siz[y])swap(x,y);fa[x]=y,siz[y]+=siz[x],sta[++top][0]=x,sta[top][1]=y;}
int main()
{
	N=get(),M=get(),K=get();For(i,1,N)a[i]=get();For(i,1,N*2)fa[i]=i,siz[i]=1;
	For(i,1,M){int u=get(),v=get();if(a[u]>a[v])swap(u,v);if(a[u]==a[v])mrg(u,v+N),mrg(u+N,v),!lim[a[u]]&&getf(u)==getf(v)?K--,lim[a[u]]=1:0;else e[{a[u],a[v]}].push_back({u,v});}ans=1ll*K*(K-1)/2;
	FOR(i,e)if(!lim[i.F.F]&&!lim[i.F.S])
	{
		int tmp=top;FOR(j,i.S){int u=j.F,v=j.S;mrg(u,v+N),mrg(u+N,v);if(getf(u)==getf(v)){ans--;break;}}
		while(top>tmp)fa[sta[top][0]]=sta[top][0],siz[sta[top][1]]-=siz[sta[top][0]],top--;
	}
	cout<<ans<<endl;return 0;
}