#include<bits/stdc++.h>
using namespace std;

struct node { int t,next; }a[10000010];

int head[2000010],d[2000010],t,n,tt,tot;
char s[500010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

int main()
{
	t=rd();
	while (t--)
	{
		n=rd();tot=0;
		for (int i=1;i<=n*4;i++) head[i]=0;
		for (int i=1;i<n;i++)
		{
			int x=rd(),y=rd();
			add(x,y);add(y,x);
		}
		scanf("%s",s+1);
		tt=n;
		for (int i=1;i<=n;i++) if (s[i]=='W')
		{
			add(i,tt+1);add(tt+1,i);
			add(tt+1,tt+2);add(tt+2,tt+1);
			add(tt+1,tt+3);add(tt+3,tt+1);
			tt+=3;
		}
		bool flag=false;
		int cnt=0;
		for (int i=1;i<=tt;i++) d[i]=0;
		for (int i=1;i<=tt;i++) for (int j=head[i];j;j=a[j].next) d[i]++;
		for (int i=1;i<=tt;i++) if (d[i]>3) { flag=true;break; }
		if (flag) { puts("White");continue; }
		for (int i=1;i<=tt;i++) if (d[i]==3)
		{
			cnt++;
			int now=0;
			for (int j=head[i];j;j=a[j].next) if (d[a[j].t]>1) now++;
			if (now>=2) { flag=true;break; }
		}
		if (flag) { puts("White");continue; }
		if (cnt<=1) { puts("Draw");continue; }
		cnt=0;
		for (int i=1;i<=tt;i++) if (d[i]>=2) cnt++;
		if (cnt&1) puts("White");
		else puts("Draw");
	}
	return 0;
}