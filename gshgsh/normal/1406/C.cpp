#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define pb push_back
#define MAXN 100001
int T,N,siz[MAXN],son[MAXN],mx;vector<int>E[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dfs(int u,int f){siz[u]=1;for(auto v:E[u])if(v!=f)dfs(v,u),siz[u]+=siz[v],son[u]=max(son[u],siz[v]);son[u]=max(son[u],N-siz[u]);mx=min(mx,son[u]);}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)E[i].clear(),son[i]=0;For(i,1,N-1){int u=get(),v=get();E[u].pb(v),E[v].pb(u);}mx=N-1,dfs(1,0);
		vector<int>now;For(i,1,N)if(son[i]==mx)now.pb(i);if(now.size()==1){int u=E[1][0];cout<<"1 "<<u<<"\n1 "<<u<<endl;continue;}
		int u=0;for(auto v:E[now[1]])if(v!=now[0]){u=v;break;}cout<<u<<' '<<now[1]<<'\n'<<u<<' '<<now[0]<<endl;
	}
	return 0;
}