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
struct input
{
	int l,c;
}a[311];
vector<int>f; 
int n,sum,sz;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
vector<pair<int,int> >con[100111];
set<pair<int,int> >s;
set<int>s2;
queue<pair<int,int> >q;
int dis[100111],mk[100111];
int dijstra(int x,int y)
{
	for(int i=0;i<sz;i++)dis[i]=INF;
	s.insert(MP(0,x));
	mk[x]=1;dis[x]=0;
	while(s.size()>0)
	{
		int u=(*s.begin()).SS,d=(*s.begin()).FF;
		mk[u]=2;
		s.erase(s.begin());
		for(int i=0;i<con[u].size();i++)
		{
			int v=con[u][i].FF,d2=con[u][i].SS;
			if(mk[v]==0||mk[v]==1&&d+d2<dis[v])
			{
				mk[v]=1;
				dis[v]=d+d2;
				s.insert(MP(dis[v],v));
			}
		}
	}
	if(dis[y]==INF)return -1;else return dis[y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].l;
	for(int i=1;i<=n;i++)cin>>a[i].c;
	f.PB(0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j*j<=a[i].l;j++)
		{
			if(a[i].l%j==0)
			{
				if(s2.count(j)==0)f.PB(j),s2.insert(j);
				if(a[i].l/j>j&&s2.count(a[i].l/j)==0)f.PB(a[i].l/j),s2.insert(a[i].l/j);
			}
		}
	}
	sort(f.begin(),f.end());
	sz=unique(f.begin(),f.end())-f.begin();
	for(int i=0;i<f.size();i++)
	{
		for(int j=1;j<=n;j++)
		{
			con[i].PB(MP(lower_bound(f.begin(),f.end(),gcd(f[i],a[j].l))-f.begin(),a[j].c));
		}
	}
	cout<<dijstra(0,1);
	return 0;
}