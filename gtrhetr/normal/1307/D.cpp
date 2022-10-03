#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<int> v[200010];

pii h[200010];

int pre[200010],suf[200010];
int dep1[200010],dep2[200010];
int num[200010],n,m,tt;
bool inq[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void bfs(int vs,int *dep)
{
	memset(inq,false,sizeof(inq));
	queue<int> q;
	q.push(vs);inq[vs]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int t:v[x]) if (!inq[t])
		{
			dep[t]=dep[x]+1;inq[t]=true;
			q.push(t);
		}
	}
}

inline bool cmp(const pii &x,const pii &y) { return x.first-y.first<x.second-y.second; }

int main()
{
	n=rd();m=rd();tt=rd();
	for (int i=1;i<=tt;i++) num[i]=rd();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(1,dep1);bfs(n,dep2);
	for (int i=1;i<=tt;i++) h[i]=pii(dep1[num[i]],dep2[num[i]]);
	sort(h+1,h+tt+1,cmp);
	for (int i=1;i<=tt;i++) pre[i]=max(pre[i-1],h[i].first);
	for (int i=tt;i;i--) suf[i]=max(suf[i+1],h[i].second);
	int ans=0;
	for (int i=1;i<=tt;i++)
	{
		if (i>1) ans=max(ans,pre[i-1]+h[i].second+1);
		if (i<tt) ans=max(ans,suf[i+1]+h[i].first+1);
	}
	printf("%d\n",min(ans,dep1[n]));
	return 0;
}