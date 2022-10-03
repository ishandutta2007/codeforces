#include<bits/stdc++.h>
using namespace std;

struct point { int x,y; }a[100010];

int n;

inline int rd()
{
	int x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline point operator -(const point &x,const point &y) { return (point){x.x-y.x,x.y-y.y}; }

inline bool check(point x,point y)
{
	if (y.x!=-x.x) return false;
	if (y.y!=-x.y) return false;
	return true;
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd();
	if (n&1) { puts("NO");return 0; }
	a[n+1]=a[1];
	for (int i=1;i<=n/2;i++)
	{
		point h1=a[i+1]-a[i],h2=a[i+n/2+1]-a[i+n/2];
		if (!check(h1,h2)) { puts("NO");return 0; }
	}
	puts("YES");
	return 0;
}