#include<bits/stdc++.h>
using namespace std;

struct node { int x,y; }a[300010];

int h1[300010],h2[300010],n,t1,t2;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp1(const int &x,const int &y) { return a[x].y>a[y].y; }

inline bool cmp2(const int &x,const int &y) { return a[x].y<a[y].y; }

inline void gao1()
{
	printf("%d\n",t1);
	sort(h1+1,h1+t1+1,cmp1);
	for (int i=1;i<=t1;i++) printf("%d ",h1[i]);
	puts("");
}

inline void gao2()
{
	printf("%d\n",t2);
	sort(h2+1,h2+t2+1,cmp2);
	for (int i=1;i<=t2;i++) printf("%d ",h2[i]);
	puts("");
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	t1=t2=0;
	for (int i=1;i<=n;i++) if (a[i].x<a[i].y) h1[++t1]=i;else h2[++t2]=i;
	if (t1>t2) gao1();
	else gao2();
	return 0;
}