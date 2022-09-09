#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
const int MAXN = 7e3 + 5;
using namespace std;

vector<int> g[MAXN];
int in[MAXN];
inline void add(int u,int v)
{
	g[u].push_back(v);
	++in[v];
}

ll a[MAXN],b[MAXN];

queue<int> q;
bool del[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin>>a[i];
	for(int i=1; i<=n; ++i) cin>>b[i];
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) if(i!=j)
		{
			if((a[i]|a[j])^a[j]);
			else add(j,i);
		}
	}
	
	for(int i=1; i<=n; ++i)
		if(!in[i])
		{
			del[i]=1;
			q.push(i);
		}
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v=g[u][i];
			--in[v];
			if(!in[v])
			{
				del[v]=1;
				q.push(v);
			}
		}
	}
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
		if(!del[i]) ans+=b[i];
	
	cout<<ans;
	return 0;
}