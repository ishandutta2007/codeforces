#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

#define maxn 510
#define maxm 50010
#define maxv 600
#define inf 1000000000

struct edge
{
	int to,cap,cost,rev;
	inline void set(int a,int b,int c,int d)
	{
		to=a;cap=b;cost=c;rev=d;
	}
};

vector<edge> g[maxv];
int dist[maxv],que[maxv+10];
int fromv[maxv],frome[maxv];
bool inq[maxv];
int s,t;

void add_edge(int from,int to,int cap,int cost)
{
//	cerr<<from<<' '<<to<<' '<<cap<<' '<<cost<<endl;
    edge t;
    t.set(to,cap,cost,g[to].size());
    g[from].push_back(t);
    t.set(from,0,-cost,g[from].size()-1);
    g[to].push_back(t);
}


bool spfa()
{
    for(int i=0;i<=t;i++)
        dist[i]=inf;
    int head=0,tail=1;
    dist[s]=0;que[0]=s;inq[s]=1;
    while (head!=tail)
    {
        int now=que[head++];
        if (head==maxv+1) head=0;
        for(int i=0;i<g[now].size();i++)
        {
            edge &e=g[now][i];
            if (e.cap && e.cost+dist[now]<dist[e.to])
            {
                dist[e.to]=e.cost+dist[now];
                frome[e.to]=i;
                fromv[e.to]=now;
                if (!inq[e.to])
                {
                    inq[e.to]=1;
                    if (dist[e.to]<dist[que[head]])
                    {
                        head--;
                        if (head==-1) head=maxv;
                        que[head]=e.to;
                    }
                    else
                    {
                        que[tail++]=e.to;
                        if (tail==maxv+1) tail=0;
                    }
                }
            }
        }
        inq[now]=0;
    }
    if (dist[t]==inf)
        return 0;
    return 1;
}


int min_cost_flow()
{
	int x=inf,res=0;
	for(int i=t;i!=s;i=fromv[i])
		x=min(x,g[fromv[i]][frome[i]].cap);
	for(int i=t;i!=s;i=fromv[i])
	{
		edge &e=g[fromv[i]][frome[i]];
		res+=x*e.cost;
		e.cap-=x;
		g[e.to][e.rev].cap+=x;
	}
// 	cerr<<res<<endl;
	return res;
}

int mcf()
{
	int ans=0;
	while (spfa())
		ans+=min_cost_flow();
	return ans;
}

int a[maxm],b[maxm],w[maxm];
int n,q,K;

void init()
{
	char s[maxn],t[maxn];
	int p;
	int m;
	scanf("%d%s%d",&n,s,&m);
	for(int i=1;i<=m;i++)
	{
		int p;
		scanf("%s%d",t,&p);
		int l=strlen(t);
		for(int i=0;i<n;i++)
		{
			int j=0;
			while (j<l && i+j<n && s[i+j]==t[j])
				j++;
			if (j==l)
			{
				add_edge(i+1,i+l+1,1,-p);
			}
		}
	}
	scanf("%d",&K);
}

void build()
{
	s=0;t=n+1;
	for(int i=0;i<t;i++)
		add_edge(i,i+1,K,0);
	printf("%d\n",-mcf());
}

int main()
{
	init();
	build();
	return 0;
}