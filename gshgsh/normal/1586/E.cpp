#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,M,Q,f[MAXN],fa[MAXN],dep[MAXN],sum[MAXN],a[MAXN],b[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){fa[u]=f,dep[u]=dep[f]+1;for(auto v:E[u])if(v!=f)dfs(v,u);}
void print(int x,int y){vector<int>ans1,ans2;while(dep[x]>dep[y])ans1.push_back(x),x=fa[x];while(dep[x]<dep[y])ans2.push_back(y),y=fa[y];while(x!=y)ans1.push_back(x),ans2.push_back(y),x=fa[x],y=fa[y];cout<<ans1.size()+ans2.size()+1<<'\n';for(auto i:ans1)cout<<i<<' ';cout<<x<<' ';while(!ans2.empty())cout<<ans2.back()<<' ',ans2.pop_back();cout<<'\n';}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	N=get(),M=get();For(i,1,N)f[i]=i;For(i,1,M){int u=get(),v=get();if(getf(u)!=getf(v))f[getf(u)]=getf(v),E[u].push_back(v),E[v].push_back(u);}
	dfs(1,0);Q=get();For(i,1,Q)sum[a[i]=get()]^=1,sum[b[i]=get()]^=1;For(i,1,N)sum[i]+=sum[i-1];if(sum[N]){cout<<"NO\n"<<sum[N]/2<<'\n';return 0;}
	cout<<"YES\n";For(i,1,Q)print(a[i],b[i]);return 0;
}