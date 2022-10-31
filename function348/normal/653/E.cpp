#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int N=300010;
int n,m,k,f;
int v[N];
set<int> c[N];
set<int> S;
void dfs(int i)
{
	S.erase(i);
	v[i]=1;
	set<int>::iterator it;
	int j;
	for (it=S.begin();it!=S.end();it=S.upper_bound(j))
	{
		
		j=(*it);
		if (i==j) continue;
		if (c[i].count(j)) continue;		
		if (j==1) 	{ f=1;continue;}
		dfs(j);
	}
}
int main()
{
//freopen("data.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	int d=n-1;
	for (int i=1;i<=m;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		c[x].insert(y);
		c[y].insert(x);
		if (x==1||y==1) d--;
	}
	if (d<k) { printf("impossible\n");return 0;}
	int cnt=0,flag=0;
	S.clear();
	for (int i=1;i<=n;i++) S.insert(i);
	for (int i=2;i<=n;i++) 
	if (!v[i]) 
	{
		f=0;
		dfs(i);
		cnt++;
		if (!f) flag=1;
	}
	if (flag) { printf("impossible\n");return 0;}
	if (cnt<=k) printf("possible\n");
	else printf("impossible\n");
	return 0;
}