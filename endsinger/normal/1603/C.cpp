#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=998244353;
int n,a[N],s;
struct nd
{
	int x,y;
	nd operator+(nd k)
	{
		return {(x+k.x)%mod,(y+k.y)%mod};
	}
};
nd f[2][N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		s=0;
		int p=0,q=1;
		for(int i=n;i>=1;i--)
		{
			swap(p,q);
			for(int x=1,y;x<=a[i];x=y+1)
			{
				y=a[i]/(a[i]/x);
				f[p][a[i]/y]={0,0};
			}
			f[p][a[i]]={1,0};
			if(i!=n)
			{
				for(int x=1,y;x<=a[i+1];x=y+1)
				{
					y=a[i+1]/(a[i+1]/x);
					f[p][a[i]/((a[i]+(a[i+1]/x)-1)/(a[i+1]/x))]=f[p][a[i]/((a[i]+(a[i+1]/x)-1)/(a[i+1]/x))]+(nd){f[q][a[i+1]/x].x,f[q][a[i+1]/x].y+1ll*f[q][a[i+1]/x].x*(((a[i]+(a[i+1]/x)-1)/(a[i+1]/x))-1)%mod};
				}
			}
			for(int x=1,y;x<=a[i];x=y+1)
			{
				y=a[i]/(a[i]/x);
				s=(s+f[p][a[i]/x].y)%mod;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}