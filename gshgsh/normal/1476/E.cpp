#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 100001
int N,M,K,fst[MAXN],cnt,to[MAXN*16],nxt[MAXN*16],deg[MAXN],tot,ans[MAXN];string a[MAXN];map<string,int>id;
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt,deg[v]++;}
int main()
{
	cin>>N>>M>>K;For(i,1,N)cin>>a[i],id[a[i]]=i;
	For(i,1,M){string x;int y;cin>>x>>y;For(j,0,K-1)if(x[j]!=a[y][j]&&a[y][j]!='_'){cout<<"NO\n";return 0;}For(j,0,(1<<K)-1){string s("_",K);For(k,0,K-1)s[k]=(j>>k)&1?x[k]:'_';if(id[s]&&id[s]!=y)add(y,id[s]);}}
	queue<int>q;For(i,1,N)if(!deg[i])q.push(i);while(!q.empty()){int u=q.front();q.pop();ans[++tot]=u;FOR(i,u)deg[to[i]]--,!deg[to[i]]?q.push(to[i]),0:0;}
	if(tot<N){cout<<"NO\n";return 0;}cout<<"YES\n";For(i,1,N)cout<<ans[i]<<' ';return 0;
}