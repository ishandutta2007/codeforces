//speed++
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
int n,m,s1,t1,l1,s2,t2,l2,ds1[3111],ds2[3111],dt1[3111],dt2[3111],dis[3111];
queue<int>q;
vector<int>con[3111];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		con[x].PB(y);
		con[y].PB(x);
	}
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	memset(ds1,-1,sizeof(ds1));ds1[s1]=0,q.push(s1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<con[u].size();i++)if(ds1[con[u][i]]==-1)ds1[con[u][i]]=ds1[u]+1,q.push(con[u][i]);
	}
	memset(ds2,-1,sizeof(ds2));ds2[s2]=0,q.push(s2);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<con[u].size();i++)if(ds2[con[u][i]]==-1)ds2[con[u][i]]=ds2[u]+1,q.push(con[u][i]);
	}
	memset(dt1,-1,sizeof(dt1));dt1[t1]=0,q.push(t1);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<con[u].size();i++)if(dt1[con[u][i]]==-1)dt1[con[u][i]]=dt1[u]+1,q.push(con[u][i]);
	}
	memset(dt2,-1,sizeof(dt2));dt2[t2]=0,q.push(t2);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<con[u].size();i++)if(dt2[con[u][i]]==-1)dt2[con[u][i]]=dt2[u]+1,q.push(con[u][i]);
	}
	int ans=INF;
	if(ds1[t1]<=l1&&ds2[t2]<=l2)ans=ds1[t1]+ds2[t2];
	for(int i=1;i<=n;i++)
	{
		queue<int>q;
		memset(dis,-1,sizeof(dis));dis[i]=0,q.push(i);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			if(ds1[i]+dis[u]>l1||min(ds2[i]+dis[u],dt2[i]+dis[u])>l2||min(ds1[i]+ds2[i]+dis[u],ds1[i]+dt2[i]+dis[u])>ans)
				break;
			if(ds1[i]+dis[u]+dt1[u]<=l1&&ds2[i]+dis[u]+dt2[u]<=l2)
			{
				ans=min(ans,ds1[i]+ds2[i]+dis[u]+dt1[u]+dt2[u]);
			}
			if(ds1[i]+dis[u]+dt1[u]<=l1&&dt2[i]+dis[u]+ds2[u]<=l2)
			{
				ans=min(ans,ds1[i]+dt2[i]+dis[u]+dt1[u]+ds2[u]);
			}
			for(int i=0;i<con[u].size();i++)if(dis[con[u][i]]==-1)dis[con[u][i]]=dis[u]+1,q.push(con[u][i]);
		}
	}
	if(ans==INF)cout<<-1<<endl;else cout<<m-ans<<endl;
	return 0;
}