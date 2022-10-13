#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,region,deg[500500],d[500500],r[500500],l[500500];
vector <int> ans[500500],D[500500],a[500500];

void remove(int x)
{
	l[r[x]]=l[x]; r[l[x]]=r[x];
}

int connect(int x,int y)
{
	if (deg[x]>deg[y]) swap(x,y);
	if (!deg[x]) return 1;
	return *(lower_bound(a[x].begin(),a[x].end(),y))!=y;
}

void bfs(int x)
{
	queue <int> q;
	q.push(x); 
	d[x]=++region; 
	remove(x);

	while (!q.empty())
	{
		x=q.front(); q.pop();
		
		for (int y=r[0];y<=n;y=r[y])
			if (connect(x,y))
			{
				q.push(y);
				d[y]=region;
				remove(y);
			}
	}
}

int main()
{
	int x,y,m;
	cin >> n >> m;
	while (m--)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y); deg[x]++;
		a[y].push_back(x); deg[y]++;
	}
	
	for (int i=0;i<=n;i++) r[i]=i+1, l[i+1]=i;
	for (int i=1;i<=n;i++) 
	{
		D[deg[i]].push_back(i);
		sort(a[i].begin(),a[i].end());
	}
	
	for (int i=0;i<n;i++)
		for (int j=0;j<int(D[i].size());j++)
		{
			int x=D[i][j];
			if (!d[x]) bfs(x);
		}
	
	for (int i=1;i<=n;i++)
		if (!d[i]) ans[region+1].push_back(i);
		else ans[d[i]].push_back(i);
		
	cout << (ans[region+1].empty()?region:region+1) << endl;
	for (int i=1;i<=region+1;i++)
		if (ans[i].empty()) break;
		else
		{
			cout << ans[i].size() << ' ';
			for (int j=0;j<int(ans[i].size());j++) printf("%d ",ans[i][j]);
			puts("");
		}
}