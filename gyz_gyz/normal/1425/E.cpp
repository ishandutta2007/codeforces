#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

int a[maxn],d[maxn];
long long suma[maxn],sumd[maxn];
int order[maxn];
long long ans;
int n,k;

bool cmp(const int &a,const int &b) {return d[a]<d[b];}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),suma[i]=suma[i-1]+a[i];
	for (int i=1;i<=n;i++) scanf("%d",&d[i]),sumd[i]=sumd[i-1]+d[i];
	for (int i=1;i<=n;i++) order[i]=i;
	sort(order+1,order+1+n,cmp);
	if (k)
	{
		if (order[1]==n)
			ans=max(ans,max(suma[n-1]-d[order[2]],0ll)+max(a[n]-d[n],0));
		else
			ans=max(ans,max(suma[n-1]-d[order[1]],0ll)+max(a[n]-d[n],0));
			
		ans=max(ans,suma[n]-d[order[1]]-d[order[2]]);
		
		ans=max(ans,max(suma[n]-a[1]-d[2],0ll)+max(a[1]-d[1],0));
		for (int i=2;i<n;i++)
			ans=max(ans,max(suma[n]-a[i]-d[1],0ll)+max(a[i]-d[i],0));
			
		if (k>=2)
		{
			if (order[1]==n)
			{
				ans=max(ans,suma[n]-d[order[2]]);
			}
			else
			{
				ans=max(ans,suma[n]-d[order[1]]);
			}
		}
		for (int i=2;i<=n;i++) ans=max(ans,suma[n]-suma[i-1]-d[i]);
	}
	else
	{
		for (int i=1;i<=n;i++) ans=max(ans,suma[n]-suma[i-1]-d[i]);
	}
	printf("%lld\n",ans);
}