#include<bits/stdc++.h>
using namespace std;

vector<int> v[300010];
vector<int> g[300010];

int num[300010],id[300010],nxt[300010],mx[300010],t,n,m,sq;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print1() { putchar('R');putchar('o');putchar('b');putchar('o');putchar('t');putchar('\n'); } 
inline void print2() { putchar('H');putchar('u');putchar('m');putchar('a');putchar('n');putchar('\n'); } 

inline bool check1()
{
	for (int i=1;i<=m;i++) if (g[i].size()<=sq) for (int t:g[i]) v[t].push_back(i);
	for (int i=1;i<=n;i++) num[i]=0;
	for (int i=1;i<=n;i++) if (v[i].size()>1)
	{
		bool flag=true;
		for (int t:v[i])
		{
			int id=0;
			for (int j=0;j<g[t].size();j++) if (g[t][j]==i) { id=j;break; }
			if (id==g[t].size()-1) continue;
			for (int j=id+1;j<g[t].size();j++)
			{
				if (num[g[t][j]]&&num[g[t][j]]!=g[t][id+1]) { flag=false;break; }
				num[g[t][j]]=g[t][id+1];
			}
			if (!flag) break;
		}
		for (int t:v[i]) for (int j:g[t]) num[j]=0;
		if (!flag) return false;
	}
	return true;
}

inline bool check(int x)
{
	for (int j=0;j<g[x].size();j++) id[g[x][j]]=j;
	for (int j=0;j<g[x].size()-1;j++) nxt[g[x][j]]=g[x][j+1];
	bool flag=true;
	for (int i=1;i<=m;i++) if (i^x)
	{
		if (i<x&&g[i].size()>sq) continue;
		for (int j=g[i].size()-1;~j;j--)
		{
			mx[j]=mx[j+1];
			if (id[g[i][j]]) mx[j]=max(mx[j],id[g[i][j]]);
		}
		for (int j=0;j<g[i].size()-1;j++) if (nxt[g[i][j]]&&nxt[g[i][j]]!=g[i][j+1]&&mx[j+1]>id[g[i][j]]) { flag=false;break; }
		for (int j=0;j<g[i].size();j++) mx[j]=0;
		if (!flag) break;
	}
	for (int j=0;j<g[x].size();j++) id[g[x][j]]=nxt[g[x][j]]=0;
	return flag;
}

int main()
{
	t=rd();
	while (t--)
	{
		n=rd();m=rd();
		for (int i=1;i<=n;i++) v[i].clear();
		int sum=0;
		for (int i=1;i<=m;i++)
		{
			int k=rd();sum+=k;
			g[i].resize(k);
			for (int j=0;j<k;j++) g[i][j]=rd();
		}
		if (!m) { print1();continue; }
		sq=sqrt(sum);
		if (!check1()) { print2();continue; }
		bool flag=true;
		for (int i=1;i<=m;i++) if (g[i].size()>sq&&!check(i)) { print2();flag=false;break; }
		if (flag) print1();
	}
	return 0;
}