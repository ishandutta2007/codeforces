#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { ll num,val,id; }a[100010];

int p[100010],to[100010],pre[100010],n,m;
ll ans,sum;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const node x,const node y) { return x.val<y.val; }

inline void del(int x)
{
	to[pre[x]]=to[x];
	pre[to[x]]=pre[x];
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) a[i].num=rd();
	for (int i=1;i<=n;i++) a[i].val=rd();
	for (int i=1;i<=n;i++) a[i].id=i;
	sort(a+1,a+n+1,cmp);
	sum=0;
	for (int i=1;i<=n;i++) sum+=a[i].num;
	for (int i=1;i<=n;i++) p[a[i].id]=i;
	for (int i=1;i<=n;i++) pre[i]=i-1,to[i]=i+1;
	to[0]=1;pre[n+1]=n;
	while (m--)
	{
		int x=p[rd()];ll y=rd();
		if (!sum) { puts("0");continue; }
		bool flag=(sum>=y);
		ll res=0,now=min(a[x].num,y);
		if (now)
		{
			a[x].num-=now;res+=a[x].val*now;sum-=now;y-=now;
			if (!a[x].num) del(x);
		}
		for (int i=to[0];i<=n&&y;i=to[i])
		{
			now=min(a[i].num,y);
			a[i].num-=now;res+=a[i].val*now;sum-=now;y-=now;
			if (!a[i].num) del(i);
		}
		if (flag) printf("%I64d\n",res);
		else puts("0");
	}
	return 0;
}