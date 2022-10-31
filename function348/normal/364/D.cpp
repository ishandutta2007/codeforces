#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1000100;
int n;
LL a[N],b[N],c[N],d[N],v[N];
LL ans;
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a;}
int random(int n) { return 1LL*rand()*rand()%n+1;}
int main()
{
	scanf("%d",&n);
	srand(time(0));
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int ii=1;ii<=7;ii++)
	{
		int p=random(n),cnt=0;
		for (int i=1;i<=n;i++) b[i]=gcd(a[i],a[p]);
		for (int i=1;1LL*i*i<=a[p];i++)
		if (a[p]%i==0)
		{
			c[++cnt]=i;v[i]=cnt;
			if (1LL*i*i==a[p]) continue;
			c[++cnt]=a[p]/i;
		}
		for (int i=1;i<=cnt;i++) d[i]=0;
		
	/*	sort(b+1,b+1+n);
		
		for (int i=1,j=1;i<=n;i++)
		{
			while (b[i]>c[j]) j++;
			d[j]++;
		}*/
		for (int i=1;i<=n;i++)
		if (b[i]<=a[p]/b[i]) 
		{
				d[v[b[i]]]++;
		}
		else 
		{
			d[v[a[p]/b[i]]+1]++;
		}
		
		for (int i=1;i<=cnt;i++)
		{
			int tot=0;
			for (int j=1;j<=cnt;j++)
			if (c[j]%c[i]==0) tot+=d[j];
			if (tot*2>=n) ans=max(ans,c[i]);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}