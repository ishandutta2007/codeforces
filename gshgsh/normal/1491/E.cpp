#include<iostream>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(v,u,f) for(auto v:E[u])if(v!=f)
#define MAXN 200001
int N,M,fib[MAXN],siz[MAXN];set<int>E[MAXN];
void getrt(int u,int f,int dep,int&rt1,int&rt2){siz[u]=1;FOR(v,u,f)getrt(v,u,dep,rt1,rt2),siz[u]+=siz[v];if(siz[u]==fib[dep])rt1=u,rt2=f;}
bool dfs(int u,int dep)
{
	if(dep<=4)return 1;int rt1=0,rt2=0;getrt(u,0,dep-1,rt1,rt2);if(rt1+rt2)return E[rt1].erase(rt2),E[rt2].erase(rt1),dfs(rt1,dep-1)&&dfs(rt2,dep-2);
	getrt(u,0,dep-2,rt1,rt2);if(rt1+rt2)return E[rt1].erase(rt2),E[rt2].erase(rt1),dfs(rt1,dep-2)&&dfs(rt2,dep-1);return 0;
}
int main(){cin>>N;For(i,1,N-1){int u,v;cin>>u>>v;E[u].insert(v),E[v].insert(u);}fib[M=1]=1;while(fib[M]<N)fib[M+1]=fib[M]+fib[M-1],M++;if(fib[M]!=N){cout<<"NO\n";return 0;}cout<<(dfs(1,M)?"YES\n":"NO\n");return 0;}