//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
ll pw3[33];
int n;
vector<int>con[33];
ll ansx[33],ansy[33];
bool vis[33];
void dfs(int u,ll x,ll y,int tr,int pd)
{
	vis[u]=1;
	ansx[u]=x;
	ansy[u]=y;
	ll r=pw3[tr];
	int dir=0;
	for(int i=0;i<con[u].size();i++)
	{
		if(vis[con[u][i]])continue;
		if(dir==pd)dir++;
		dfs(con[u][i],x+dx[dir]*pw3[tr-1],y+dy[dir]*pw3[tr-1],tr-1,dir^1);
		dir++;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		con[x].PB(y);
		con[y].PB(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(con[i].size()>4)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	pw3[0]=1;
	for(int i=1;i<=32;i++)pw3[i]=pw3[i-1]*3;
	dfs(1,0,0,32,-1);
	for(int i=1;i<=n;i++)cout<<ansx[i]<<" "<<ansy[i]<<endl;
	return 0;
}