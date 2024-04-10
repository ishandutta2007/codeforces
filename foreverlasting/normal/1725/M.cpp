#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define gc getchar
#define pli pair<LL,int>
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
inline int rd(){
    int s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
const int N=1e5+10,mxn=1e6+10;
const LL infl=1e18;
int n,m,vis[mxn];
LL dis[mxn];
int t,h[mxn];
struct Edge
{
	int to,val,nxt;
}e[mxn<<1];
void add(int u,int v,int w)
{
	e[++t]=(Edge){v,w,h[u]};h[u]=t;
	e[++t]=(Edge){u+n,w,h[v+n]};h[v+n]=t;
}
int main(){
	n=rd();m=rd();int x,y;
	for(int i=1;i<=m;++i) x=rd(),y=rd(),add(x,y,rd());
	for(int i=1;i<=n;++i) e[++t]=(Edge){i+n,0,h[i]},h[i]=t;
	fill(dis+1,dis+n*2+1,infl);
	priority_queue<pli> q;q.push(mp(dis[1]=0,1));
	int u,v;
	while(!q.empty())
	{
		u=q.top().sc;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
			if(dis[v=e[i].to]>dis[u]+e[i].val)
			{
				dis[v]=dis[u]+e[i].val;
				q.push(mp(-dis[v],v));
			}
	}
	LL res;
	for(int i=2;i<=n;++i)
	{
		res=min(dis[i],dis[i+n]);
		if(res!=infl) printf("%lld ",res);
		else printf("-1 ");
	}
	puts("");
	return 0;
}