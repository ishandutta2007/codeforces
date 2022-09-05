//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
struct edge
{
	int u,v,c,id;
};
int n;
ll ed[100111];
double mul[100111];
vector<edge>con[100111];
bool vis[100111];
double cal()
{
	double ans=0;
	for(int i=1;i<n;i++)
	{
		ans+=1.0*mul[i]*ed[i];
	}
	return ans;
}
int dfs(int x)
{
	int cnt=1;
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		if(vis[con[x][i].v])continue;
		int tmp=dfs(con[x][i].v);
		ll tt=1ll*tmp*(tmp-1)/2*(n-tmp)+1ll*(n-tmp)*(n-tmp-1)/2*tmp;
		ll tt2=1ll*n*(n-1)/2*(n-2)/3;
		mul[con[x][i].id]=2.0*tt/tt2;
		cnt+=tmp;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int x,y,c;
	edge e;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>c;
		ed[i]=c;
		e.u=x;e.v=y;e.c=c;e.id=i;
		con[x].PB(e);
		e.u=y;e.v=x;
		con[y].PB(e);
	}
	dfs(1);
	int q;
	cin>>q;
	double ans=cal();
	while(q--)
	{
		cin>>x>>y;
		ans-=mul[x]*(ed[x]-y);
		ed[x]=y;
		cout<<fixed<<setprecision(10)<<ans<<endl;
	}
	return 0;
}