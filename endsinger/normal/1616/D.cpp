#include<bits/stdc++.h>
using namespace std;
const int N=50005;
struct nd
{
	int l,r;
	bool operator<(const nd k)const
	{
		return r!=k.r?r<k.r:l<k.l;
	}
}z[N];
int n,c,s[N],t,p,v;
long long x,a[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%lld",&x);
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1]-x;
	t=c=0;
	for(int i=0;i<=n;i++)
	{
		int l=0,r=t;
		while(l<r)
		{
			int m=(l+r+1)>>1;
			if(a[s[m]]>a[i])
				l=m;
			else
				r=m-1;
		}
		if(l)
			z[++c]={s[l]+1,i};
		if(i)
		{
			while(t&&a[s[t]]<=a[i-1])
				t--;
			s[++t]=i-1;
		}
	}
	sort(z+1,z+c+1);
	p=-1,v=n;
	for(int i=1;i<=c;i++)
		if(z[i].l>p)
			v--,p=z[i].r;
	printf("%d\n",v);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}