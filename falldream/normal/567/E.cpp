#include<iostream>
#include<cstdio>
#define MAXN 200005
#define INF 1e17
#include<queue>
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
struct edge{
	int to,next;
	ll x;
}e[3][MAXN*2];
struct edge2{
    int from,to,x,num;
}rec[MAXN*2];
struct POS{
    int u;
    ll d;
    bool operator < (const POS& x) const {
        return d > x.d; 
    }
};
int n,m,s,t;
ll minn;
ll d[2][MAXN];
int vis[2][MAXN];
int cnt=0;
int head[3][2*MAXN];
int num[2*MAXN],fa[2*MAXN],dfn[2*MAXN],low[2*MAXN],cc=0;
int tj[MAXN*2],flag;

void ins_new(int u,int v,int ww,int flag,int d)
{
	e[flag][++cnt].to=v;  
    e[flag][cnt].next=head[flag][u];  
    e[flag][cnt].x=ww;  
    num[cnt]=d;
    head[flag][u]=cnt;  
    e[flag][++cnt].to=u;  
    e[flag][cnt].next=head[flag][v];  
    e[flag][cnt].x=ww;  
    num[cnt]=d;
    head[flag][v]=cnt;  
}

void ins(int u,int v,int ww,int flag)
{
	e[flag][++cnt].to=v;  
    e[flag][cnt].next=head[flag][u];  
    e[flag][cnt].x=ww;  
    head[flag][u]=cnt;  
}

void add(int u,int v,int x,int d)
{
	rec[d].from=u;
	rec[d].to=v;
	rec[d].x=x;
    rec[d].num=cnt;
}

void dij(int flag,int from)
{
	priority_queue<POS> q;
    for (int i=1;i<=n;i++) 
	{
        d[flag][i]=INF;   
        vis[flag][i]=0;
    }
    d[flag][from]=0;
    q.push((POS){from,0});
    while (!q.empty()) {
        int u=q.top().u;q.pop();  
        if (vis[flag][u]) continue;
        vis[flag][u]=1;
        for (int i=head[flag][u];i>0;i=e[flag][i].next) {
            int v=e[flag][i].to;   
            if (d[flag][v]>d[flag][u]+e[flag][i].x) {
                d[flag][v]=d[flag][u]+e[flag][i].x;
                q.push((POS){v,d[flag][v]});
            }
        }
    }
}

void tarjan(int x)
{
	dfn[x]=low[x]=++cc;     
    for (int i=head[2][x];i>0;i=e[2][i].next){
        int v=e[2][i].to;  
        if (!dfn[v]){
            fa[v]=num[i];
            tarjan(v);  
            low[x]=min(low[x],low[v]);
            if (low[v]>dfn[x]) tj[fa[v]]=1;
        } 
		else 
		    if (fa[x]!=num[i]) 
                low[x]=min(low[x],dfn[v]);
    }
}

int main()
{
	//freopen("path.in","r",stdin);
    //freopen("path.out","w",stdout);
    n=read();m=read();s=read();t=read();
    for(int i=1;i<=m;i++)
	{
	    register int a=read(),b=read(),c=read();
		ins(a,b,c,1);
		ins(b,a,c,0);	
	    add(a,b,c,i);
	} 
	dij(1,s);
	dij(0,t);
	minn=d[1][t];
    cnt=0; edge2 r;
    for(int i=1;i<=m;i++)
    {
		r=rec[i];
		if (d[0][r.to]+d[1][r.from]+r.x==minn) {
            ins_new(r.from,r.to,r.x,2,i);
        } 
	}
	tarjan(s);
	for(int i=1;i<=m;i++)
	{
        r=rec[i];
        if (d[1][r.from]==INF||d[0][r.to]==INF) {
            printf("NO\n"); 
            continue;
        }
        ll dis=d[1][r.from]+d[0][r.to]+r.x;
        if (tj[i]) printf("YES\n");
        else if (dis==minn&&r.x>1) printf("CAN 1\n");
        else if (dis>minn) {
            ll t=dis-minn+1; 
            if (r.x<=t) printf("NO\n");
            else printf("CAN %d\n",t);
        } else printf("NO\n");
    }
	return 0;
}