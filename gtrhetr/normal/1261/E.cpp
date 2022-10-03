#include<bits/stdc++.h>
using namespace std;

vector<int> v[1010];

int num[1010],n,tt;
bool bo[1010][1010],flag[1010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	tt=1;
	for (int i=1;i<=n+1;i++) v[1].push_back(i);
	for (int i=1;i<=n;i++)
	{
		int id=0;
		for (int j=1;j<=tt;j++) if (v[j].size()>1) { id=j;break; }
		tt++;
		int tot=v[id].size();
		int hh=num[i]-min(num[i],tot-1);
		for (int j=1;j<=min(num[i],tot-1);j++)
		{
			bo[v[id][tot-j]][i]=true;
			v[tt].push_back(v[id][tot-j]);
		}
		for (int j=1;j<=num[i]-hh;j++) v[id].pop_back();
		for (int j=1;j<tt;j++)
		{
			if (!hh) break;
			if (j==id) continue;
			int now=min(hh,(int)v[j].size());
			for (int k=0;k<now;k++) bo[v[j][k]][i]=true;
			hh-=now;
		}
	}
	int ans=0;
	for (int i=1;i<=n+1;i++)
	{
		flag[i]=false;
		for (int j=1;j<=n;j++) if (bo[i][j]) flag[i]=true;
		ans+=flag[i];
	}
	printf("%d\n",ans);
	for (int i=1;i<=n+1;i++) if (flag[i])
	{
		for (int j=1;j<=n;j++) putchar(bo[i][j]+'0');
		putchar('\n');
	}
	return 0;
}