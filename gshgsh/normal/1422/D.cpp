#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define abs(x) ((x)>0?(x):-(x))
#define F first
#define S second
#define pb push_back
#define MAXN 200001
int N,M,dis[MAXN];Pair s,t,x[MAXN],y[MAXN];bool vis[MAXN];vector<Pair>E[MAXN];
int get(){char c=getchar();int x=0;while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,int w){E[u].pb({v,w}),E[v].pb({u,w});}
int main()
{
	N=get(),M=get();s.F=get(),s.S=get(),t.F=get(),t.S=get();add(0,M+1,abs(s.F-t.F)+abs(s.S-t.S));For(i,1,M)x[i]={get(),i},y[i]={get(),i};
	For(i,1,M)add(0,i,min(abs(s.F-x[i].F),abs(s.S-y[i].F))),add(i,M+1,abs(t.F-x[i].F)+abs(t.S-y[i].F));sort(x+1,x+M+1);sort(y+1,y+M+1);For(i,2,M)add(x[i-1].S,x[i].S,x[i].F-x[i-1].F),add(y[i-1].S,y[i].S,y[i].F-y[i-1].F);
	priority_queue<Pair,vector<Pair>,greater<Pair> >q;memset(dis,0x7f,sizeof(dis));dis[0]=0;q.push({0,0});
	while(!q.empty()){int u=q.top().S;q.pop();if(vis[u])continue;vis[u]=1;if(u==M+1)break;for(auto v:E[u])if(dis[v.F]>dis[u]+v.S)dis[v.F]=dis[u]+v.S,q.push({dis[v.F],v.F});}
	cout<<dis[M+1]<<endl;return 0;
}