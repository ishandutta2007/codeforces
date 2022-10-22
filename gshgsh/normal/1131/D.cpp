#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 2001
#define MAXM 1000001
int N,M,fa[MAXN],fst[MAXN],cnt,to[MAXM],nxt[MAXM],in[MAXN],out[MAXN],f[MAXN];char opt[MAXN][MAXN];bool vis[MAXN];
char getc(){char c=getchar();while(c!='<'&&c!='>'&&c!='=')c=getchar();return c;}
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;in[v]++,out[u]++;}
int main()
{
	cin>>N>>M;For(i,1,N+M)fa[i]=i;For(i,1,N)For(j,1,M){opt[i][j]=getc();if(opt[i][j]=='=')fa[getf(i)]=getf(j+N);else if(getf(i)==getf(j+N)){cout<<"No\n";return 0;}}
	For(i,1,N)For(j,1,M)if(opt[i][j]!='=')opt[i][j]=='<'?add(getf(i),getf(j+N)):add(getf(j+N),getf(i));queue<int>q;For(i,1,N+M)if(fa[i]==i&&!in[i])q.push(i),f[i]=1;
	For(i,1,N+M)if(fa[i]==i)vis[i]=1;while(!q.empty()){int u=q.front();q.pop();vis[u]=0;FOR(i,u)f[to[i]]=max(f[to[i]],f[u]+1),in[to[i]]--,!in[to[i]]?q.push(to[i]),0:0;}
	For(i,1,N+M)if(vis[i]){cout<<"No\n";return 0;}cout<<"Yes\n";For(i,1,N)cout<<f[getf(i)]<<' ';cout<<endl;For(i,1,M)cout<<f[getf(i+N)]<<' ';return 0;
}