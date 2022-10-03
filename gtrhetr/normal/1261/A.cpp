#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

pii h[2010];

int num[2010],c[2010],t,n,k,tt=0;
char s[2010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void work()
{
	n=rd();k=rd();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) num[i]=(s[i]=='(')?1:-1;
	for (int i=1;i<k;i++) c[i*2-1]=1,c[i*2]=-1;
	int hh=n-(k-1)*2;
	for (int i=1;i<=hh/2;i++) c[(k-1)*2+i]=1;
	for (int i=1;i<=hh/2;i++) c[n-i+1]=-1;
	tt=0;
	for (int i=1;i<=n;i++)
	{
		int id=0;
		for (int j=i;j<=n;j++) if (num[j]==c[i]) { id=j;break; }
		h[++tt]=pii(i,id);reverse(num+i,num+id+1);
	}
	printf("%d\n",tt);
	for (int i=1;i<=tt;i++) printf("%d %d\n",h[i].first,h[i].second);
}

int main()
{
	t=rd();
	while (t--) work();
	return 0;
}