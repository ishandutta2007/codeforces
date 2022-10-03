#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&(-(x)))

bool *c[30];
int num[400010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(bool *c,int x,int n) { for (;x<=n;x+=lowbit(x)) c[x]^=1; }

inline bool query(bool *c,int x)
{
	bool res=0;
	for (;x;x-=lowbit(x)) res^=c[x];
	return res;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=0;i<=24;i++)
	{
		c[i]=new bool[(1<<(i+1))+1];
		memset(c[i],0,sizeof(bool)*((1<<(i+1))+1));
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=24;j++)
		{
			int all=(1<<(j+1))-1;
			int l=((1<<j)-(num[i]&all)+(all+1))&all,r=(l+(1<<j)-1)&all;
			bool flag;
			if (l<=r) flag=query(c[j],r+1)^query(c[j],l);
			else flag=query(c[j],r+1)^query(c[j],l)^((i-1)&1);
			if (flag) ans^=(1<<j);
		}
		for (int j=0;j<=24;j++)
		{
			int all=(1<<(j+1))-1,now=num[i]&all;
			add(c[j],now+1,all+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}