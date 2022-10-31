#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=300010;
typedef long long LL;
int n,tot,ansl,ansr;
LL ans;
int a[N],id[N],q[N];
LL s[N];
int cmp(int i,int j) { return a[i]<a[j];}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+max(0,a[i]);
	}
	for (int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,cmp);
	int l=n+1,r=0;
	ans=-2000010000;
	a[id[n+1]]=a[id[n]]+1;
	for (int i=1;i<=n;i++)
	{
		l=min(l,id[i]);r=max(r,id[i]);
		if (a[id[i+1]]!=a[id[i]])
		{
			if (s[r-1]-s[l]+2*a[l]>ans&&l<r)
				ansl=l,ansr=r,ans=s[r-1]-s[l]+2*a[l];
			l=n+1,r=0;
		}
	}
	cout<<ans<<' ';
	for (int i=1;i<ansl;i++) q[++tot]=i;
	for (int i=ansl+1;i<ansr;i++)
	if (a[i]<0) q[++tot]=i;
	for (int i=ansr+1;i<=n;i++) q[++tot]=i;
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d ",q[i]);
	return 0;
}