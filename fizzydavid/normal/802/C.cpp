// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

struct mincost_flow
{
	struct edge
	{
		int to,cap,cost,rev;
		edge(int to,int cap,int cost,int rev)
		{
			this->to=to;
			this->cap=cap;
			this->cost=cost;
			this->rev=rev;
		}
	};
	vector<edge> g[233];
	int q[256],front,rear,pre[233],pree[233],dist[233];
	bool inq[233];
	void addedge(int from,int to,int cap,int cost)
	{
//		printf("addedge %d %d %d %d\n",from,to,cap,cost);
		g[from].pb(edge(to,cap,cost,(int)g[to].size()));
		g[to].pb(edge(from,0,-cost,(int)g[from].size()-1));
	}
	int mincostflow(int s,int t,int f)
	{
		int ret=0;
		while(f>0)
		{
			memset(dist,127,sizeof(dist));
			dist[s]=0;
			front=rear=0;q[rear++]=s;
			while(front!=rear)
			{
//				printf("%d %d\n",q[front],dist[front]);system("pause");
				int x=q[front++];front&=255;
				inq[x]=0;
				for(int i=0;i<(int)g[x].size();i++)
				{
					edge &e=g[x][i];
					if(e.cap>0&&dist[e.to]>dist[x]+e.cost)
					{
						dist[e.to]=dist[x]+e.cost;
						pre[e.to]=x;
						pree[e.to]=i;
						if(!inq[e.to])
						{
							inq[e.to]=1;
							q[rear++]=e.to;
							rear&=255;
						}
					}
				}
			}
//			printf("t= %d\n",t);
			if(dist[t]==inf)return ret;
			int d=f,cur;
			for(cur=t;cur!=s;cur=pre[cur])
				d=min(d,g[pre[cur]][pree[cur]].cap);
			f-=d;
			ret+=d*dist[t];
			for(cur=t;cur!=s;cur=pre[cur])
			{
				edge &e=g[pre[cur]][pree[cur]];
				e.cap-=d;
				g[cur][e.rev].cap+=d;
			}
//			puts("yr");
		}
		return ret;
	}
}m1;
int n,k,a[100],cost[100];
vector<int>tt;
int last[100];
int main()
{
	get2(n,k);
	for(int i=1;i<=n;i++)get1(a[i]);
	for(int i=1;i<=n;i++)get1(cost[i]);
	tt.pb(0);
	for(int i=1;i<=n;i++)if(a[i]!=a[i-1])tt.pb(a[i]);
	n=(int)tt.size()-1;
	
	int s=0,t=n+1,ans=0;
	m1.addedge(s,1,k-1,0);
	for(int i=1;i<=n;i++)
	{
		ans+=cost[tt[i]];
		m1.addedge(i,i+1,k-1,0);
		if(last[tt[i]])
			m1.addedge(last[tt[i]]+1,i,1,-cost[tt[i]]);
		last[tt[i]]=i;
	}
	printf("%d\n",ans+m1.mincostflow(s,t,k-1));
	return 0;
}