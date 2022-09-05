//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
struct EDGE
{
	int to,id;
	ll d;
};
EDGE make_edge(int to,ll d,int id)
{
	EDGE tmp;
	tmp.to=to;
	tmp.d=d;
	tmp.id=id;
	return tmp;
}
int n,m,U,pre[300111];
vector<EDGE>con[300111];
vector<int>ans[300111];
ll dis[300111],cost[300111];
set<pair<ll,int> >st;
void dijkstra()
{
	for(int i=1;i<=n;i++)dis[i]=LINF;
	dis[U]=0;
	st.insert(MP(0,U));
	while(st.size()>0)
	{
		int u=st.begin()->SS;
		ll d=st.begin()->FF;
		st.erase(st.begin());
		for(int i=0;i<con[u].size();i++)
		{
			EDGE &E=con[u][i];
			if(d+E.d<dis[E.to])
			{
				dis[E.to]=d+E.d;
				pre[E.to]=E.id;
				st.insert(MP(dis[E.to],E.to));
			}
			else if(d+E.d==dis[E.to])
			{
				if(cost[E.id]<cost[pre[E.to]])pre[E.to]=E.id;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int x,y;
	ll z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		con[x].PB(make_edge(y,z,i));
		con[y].PB(make_edge(x,z,i));
		cost[i]=z;
	}
	cin>>U;
	dijkstra();
	ll sum=0;
	for(int i=1;i<=n;i++)if(i!=U)sum+=cost[pre[i]];
	cout<<sum<<endl;
	for(int i=1;i<=n;i++)if(i!=U)cout<<pre[i]<<" ";
	cout<<endl;
	return 0;
}