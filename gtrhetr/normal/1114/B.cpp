#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { ll x,id; }a[200010];

ll num[200010],n,m,k;
bool bo[200010];

inline ll rd()
{
	ll x=0,f=1;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

inline bool cmp(const node &x,const node &y) { return x.x>y.x; }

int main()
{
	n=rd();m=rd();k=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=n;i++) a[i].x=num[i],a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=m*k;i++) bo[a[i].id]=true;
	ll ans=0;
	for (int i=1;i<=m*k;i++) ans+=a[i].x;
	printf("%I64d\n",ans);
	int tot=0,tt=0;
	for (int i=1;i<=n;i++)
	{
		tot+=bo[i];
		if (tot==m&&tt<k-1) printf("%d ",i),tot=0,tt++;
	}
	return 0;
}