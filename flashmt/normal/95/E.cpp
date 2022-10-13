#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define oo 1000111222
using namespace std;

int n,m,d[100100],cnt[100100],re=oo,f[80000],head[80000],tail[80000];
vector <int> a,st[80000],pos[80000];

int find(int x)
{
	if (d[x]!=x) d[x]=find(d[x]);
	return d[x];
}

void gen(int x)
{
	if (x>100000) return;
	if (f[x]) re=min(re,f[x]-2);
	gen(x*10+4); gen(x*10+7);
}

int main()
{
	//freopen("e.in.0","r",stdin);
	cin >> n >> m;
	for (int i=1;i<=n;i++) d[i]=i;
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int u=find(x),v=find(y);
		if (u!=v) d[u]=v;
	}
	for (int i=1;i<=n;i++) cnt[find(i)]++;
	for (int i=1;i<=n;i++)
		if (cnt[i]) a.push_back(cnt[i]);
	sort(a.begin(),a.end());
	int m=0;
	cnt[0]=1;
	for (int i=1;i<int(a.size());i++)
		if (a[i]==a[m]) cnt[m]++;
		else a[++m]=a[i], cnt[m]=1;
	// knapsack
	f[0]=1;
	for (int i=0;i<=m;i++)
	{
		if (a[i]>77777) break;
		// init stacks
		for (int j=0;j<a[i];j++)
		{
			st[j].resize(77777/a[i]+1);
			pos[j].resize(77777/a[i]+1);
			head[j]=0; tail[j]=-1; 
		}
		// solve
		for (int j=0;j<=77777;j++)
		{
			int x=j%a[i], y=j/a[i], u=f[j]-y;
			// push
			if (f[j])
			{
				while (tail[x]>=head[x] && u<=st[x][tail[x]]) tail[x]--;
				st[x][++tail[x]]=u;	pos[x][tail[x]]=y;
			}
			// pop
			if (head[x]>tail[x]) continue;
			while (pos[x][head[x]]+cnt[i]<y && head[x]<=tail[x]) head[x]++;
			if (head[x]<=tail[x]) f[j]=st[x][head[x]]+y;
		}
	}
	gen(4); gen(7);
	cout << (re==oo?-1:re) << endl;
	return 0;
}