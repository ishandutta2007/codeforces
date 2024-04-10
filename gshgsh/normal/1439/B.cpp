#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 100001
int T,N,M,K,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],deg[MAXN],tot,ans[MAXN];bool vis[MAXN];set<int>e[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt,deg[u]++;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt,deg[v]++;}
void dfs(int u){vis[u]=1;ans[++tot]=u;FOR(i,u)if(!vis[to[i]])dfs(to[i]);}
bool check(int u){vector<int>tmp;tmp.clear();tmp.push_back(u);for(auto i:e[u]){if(deg[i]<K-1)return 0;for(auto j:tmp)if(!e[i].count(j))return 0;tmp.push_back(i);}return 1;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get(),K=get();For(i,1,N)fst[i]=deg[i]=vis[i]=0,e[i].clear();cnt=tot=0;For(i,1,M)add(get(),get());For(i,1,N)FOR(j,i)e[i].insert(to[j]);if(K==1){cout<<"2\n1\n";continue;}
		bool flag=0;queue<int>q;For(i,1,N){if(deg[i]<K)q.push(i),vis[i]=1;if(deg[i]==K-1&&1ll*K*(K-1)<=2*M&&check(i)){flag=1;cout<<"2\n"<<i<<' ';for(auto j:e[i])put(j),putchar(' ');cout<<endl;break;}}if(flag)continue;
		while(!q.empty()){int u=q.front();q.pop();for(auto i:e[u]){deg[i]--;e[i].erase(u);if(!vis[i]&&deg[i]<K)q.push(i),vis[i]=1;if(deg[i]==K-1&&1ll*K*(K-1)<=2*M&&check(i)){flag=1;cout<<"2\n"<<i<<' ';for(auto j:e[i])put(j),putchar(' ');cout<<endl;break;}}if(flag)break;e[u].clear();}if(flag)continue;
		For(i,1,N)if(!vis[i]){flag=1;dfs(i);cout<<"1 "<<tot<<endl;For(j,1,tot)put(ans[j]),putchar(' ');cout<<endl;break;}if(!flag)cout<<"-1\n";
	}
	return 0;
}