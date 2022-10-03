#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { ll x,y,z; }h[2000010];

struct hhhh { ll x,id; }a[300010],b[300010];

queue<int> q;

int id1[300010],id2[300010];
ll s[300010],t[300010],num[300010],pre[300010],n,tt;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const hhhh &x,const hhhh y) { return x.x<y.x; }

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) s[i]=rd();
	for (int i=1;i<=n;i++) t[i]=rd();
	ll sum1=0,sum2=0;
	for (int i=1;i<=n;i++) sum1+=s[i];
	for (int i=1;i<=n;i++) sum2+=t[i];
	if (sum1!=sum2) { puts("NO");return 0; }
	for (int i=1;i<=n;i++) a[i].x=s[i],a[i].id=i;
	for (int i=1;i<=n;i++) b[i].x=t[i],b[i].id=i;
	sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++) s[i]=a[i].x,id1[i]=a[i].id;
	for (int i=1;i<=n;i++) t[i]=b[i].x,id2[i]=b[i].id;
	if (s[1]>t[1]) { puts("NO");return 0; }
	if (s[n]<t[n]) { puts("NO");return 0; }
	for (int i=1;i<=n;i++) num[i]=t[i]-s[i];
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+num[i];
	for (int i=1;i<=n;i++) if (pre[i]<0) { puts("NO");return 0; }
	tt=0;
	for (int i=1;i<=n;i++)
	{
		if (num[i]==0) continue;
		if (num[i]>0) { q.push(i);continue; }
		while (s[i]>t[i])
		{
			int hh=q.front();
			ll now=min(t[hh]-s[hh],s[i]-t[i]);
			s[hh]+=now;s[i]-=now;
			h[++tt]=(node){id1[hh],id1[i],now};
			if (s[hh]==t[hh]) q.pop();
		}
	}
	puts("YES");
	printf("%d\n",tt);
	for (int i=1;i<=tt;i++) printf("%lld %lld %lld\n",h[i].x,h[i].y,h[i].z);
	return 0;
}