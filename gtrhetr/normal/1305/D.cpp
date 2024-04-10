#include<bits/stdc++.h>
using namespace std;

vector<int> v[1010];

int d[1010],h[1010],c[1010],n,tt,t1;

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
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd();
		v[x].push_back(y);
		v[y].push_back(x);
		d[x]++;d[y]++;
	}
	tt=0;
	for (int i=1;i<=n;i++) h[++tt]=i;
	while (233)
	{
		if (tt==1) { printf("! %d\n",h[1]);fflush(stdout);return 0; }
		int h1=0,h2=0;
		for (int i=1;i<=tt;i++) if (d[h[i]]==1)
		{
			if (!h1) h1=i;
			else h2=i;
		}
		printf("? %d %d\n",h[h1],h[h2]);
		fflush(stdout);
		int x=rd();
		if (x==h[h1]||x==h[h2]) { printf("! %d\n",x);fflush(stdout);return 0; }
		for (int t:v[h[h1]]) d[t]--;
		for (int t:v[h[h2]]) d[t]--;
		t1=0;
		for (int i=1;i<=tt;i++) if (i!=h1&&i!=h2) c[++t1]=h[i];
		tt=t1;
		for (int i=1;i<=tt;i++) h[i]=c[i];
	}
	return 0;
}