#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double

struct node { ll x,y,z; }a[1000010];

struct point
{
	ll x,y;
	point(ll xx,ll yy):x(xx),y(yy) {}
};

ll f[1000010],st[1000010],n,top;
bool bo[1000010];

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const node &x,const node &y) { return x.x<y.x; }

inline ll gao(int x,int y)
{
	return f[x]-a[y].y*a[x].x;
}

inline ldb cross(point x,point y) { return (ldb)x.x*y.y-(ldb)x.y*y.x; }

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) a[i].x=rd(),a[i].y=rd(),a[i].z=rd();
	sort(a+1,a+n+1,cmp);
	f[0]=0;st[top=1]=0;
	bo[0]=true;
	int now=1;
	for (int i=1;i<=n;i++)
	{
		while (now<top&&gao(st[now],i)<gao(st[now+1],i)) now++;
		f[i]=a[i].x*a[i].y-a[i].z+gao(st[now],i);
		while (top>1&&cross(point(a[st[top]].x-a[st[top-1]].x,f[st[top]]-f[st[top-1]]),point(a[i].x-a[st[top-1]].x,f[i]-f[st[top-1]]))>=0) top--;
		st[++top]=i;
		if (now>top) now=top;
	}
	ll ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}