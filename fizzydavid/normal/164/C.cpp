//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input1(x) x=getval()
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
inline int getval()
{
	int __res=0;bool __neg=0;
	char __c;__c=getchar();
	while(__c==' '||__c=='\n')__c=getchar();
	while(__c!=' '&&__c!='\n')
	{
		if(__c=='-')__neg=1;
		else __res=__res*10+__c-'0';
		__c=getchar();
	}
	if(__neg)__res=-__res;
	return __res;
}
struct edge
{
	int to,cap,rev,cost;
};
vector<edge>con[2011];
edge make_edge(int a,int b,int c,int d)
{
	edge e;
	e.to=a;e.cap=b;e.rev=c;e.cost=d;
	return e;
}
void add_edge(int x,int y,int cap,int cost)
{
//	cout<<x<<"-"<<y<<" "<<cap<<" "<<cost<<endl;
	con[x].PB(make_edge(y,cap,con[y].size(),cost));
	con[y].PB(make_edge(x,0,con[x].size()-1,-cost));
}
int n,m,k,a[1011],b[1011],c[1011],epos1[1011],epos2[1011];
vector<int>pos;
int findpos(int x)
{
	return lower_bound(pos.begin(),pos.end(),x)-pos.begin();
}
bool inq[2011];
int dis[2011],prv[2011],pre[2011];
int min_cost_flow(int s,int t,int f)
{
	int ans=0;
	while(f>0)
	{
//		putchar('1');
		for(int i=0;i<=2000;i++)dis[i]=INF;
		dis[s]=0;
		queue<int>q;q.push(s);inq[s]=1;
		while(!q.empty())
		{
			int u=q.front();q.pop();inq[u]=0;
//			cout<<u<<endl;
			for(int i=0;i<con[u].size();i++)
			{
				edge &e=con[u][i];
				if(e.cap>0&&dis[u]+e.cost<dis[e.to])
				{
//					cout<<"update:e("<<u<<","<<e.to<<") with cap "<<e.cap<<" and cost "<<e.cost<<" to:"<<dis[u]+e.cost<<endl;
//					system("pause");
					dis[e.to]=dis[u]+e.cost;
					prv[e.to]=u;pre[e.to]=i;
					if(!inq[e.to])q.push(e.to),inq[e.to]=1;
				}
			}
		}
		if(dis[t]==INF)return -1;
		int d=f;
		for(int u=t;u!=s;u=prv[u])d=min(d,con[prv[u]][pre[u]].cap);
		f-=d;ans+=d*dis[t];
		for(int u=t;u!=s;u=prv[u])
		{
			con[prv[u]][pre[u]].cap-=d;
			con[u][con[prv[u]][pre[u]].rev].cap+=d;
		}
	}
	return ans;
}
int main()
{
	input2(n,k);
	for(int i=1;i<=n;i++)input3(a[i],b[i],c[i]),b[i]=a[i]+b[i],pos.PB(a[i]),pos.PB(b[i]);
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	m=pos.size();
	for(int i=1;i<m;i++)add_edge(i-1,i,INF,0);
	for(int i=1;i<=n;i++)
	{
		int x=findpos(a[i]),y=findpos(b[i]);
		epos1[i]=x;epos2[i]=con[x].size();
		add_edge(x,y,1,-c[i]);
	}
	min_cost_flow(0,m-1,k);
	for(int i=1;i<=n;i++)
	{
		if(con[epos1[i]][epos2[i]].cap==0)putchar('1');else putchar('0');
		i<n?putchar(' '):putchar('\n');
	}
	return 0;
}