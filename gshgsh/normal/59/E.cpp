#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define Pair pair<int,int>
#define mp make_pair
#define F first
#define S second
#define MAXN 3001
#define MAXM 40001
int N,M,K,fst[MAXN],cnt,to[MAXM],nxt[MAXM],dis[MAXN][MAXN],pre[MAXN][MAXN];map<Pair,bool>lim[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
void print(int u,int p){if(u!=1)print(p,pre[u][p]);put(u),putchar(' ');}
int main()
{
	N=get(),M=get(),K=get();For(i,1,M)add(get(),get());For(i,1,K){int a=get(),b=get(),c=get();lim[b][mp(a,c)]=1;}
	queue<Pair>q;q.push(mp(1,0));while(!q.empty()){int u=q.front().F,p=q.front().S;q.pop();if(u==N){put(dis[u][p]),putchar('\n'),print(u,p);return 0;}FOR(i,u)if(!dis[to[i]][u]&&!lim[u][mp(p,to[i])])dis[to[i]][u]=dis[u][p]+1,pre[to[i]][u]=p,q.push(mp(to[i],u));}
	cout<<-1<<endl;return 0;
}