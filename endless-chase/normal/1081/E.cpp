#include<bits/stdc++.h>
using namespace std;
int n,a[111111],b[222222],x,aa,bb;
long long cur;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n/2;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n/2;i++)
	{
		x=sqrt(a[i]);
		aa=bb=1e9;
		for (int j=1;j<=x;j++)
		{
			if (a[i]%j==0)
			{
				int l=j,r=a[i]/j;
				if (l>r) swap(l,r);
				if ((l+r)%2==0 && (r-l)/2>b[(i-1)*2])
				{
					if (l+r<aa+bb)
					{
						aa=l;
						bb=r;
					}
				}
			}
		}
		if (aa>=1e9)
		{
			printf("No\n");
			return 0;
		}
		if (aa>bb) swap(aa,bb);
		b[i*2-1]=(bb-aa)/2;
		b[i*2]=(bb+aa)/2;
	}
	printf("Yes\n");
	printf("%I64d ",(long long)b[1]*(long long)b[1]);
	for (int i=2;i<=n;i++)
	{
		cur=(long long)(b[i]-b[i-1])*(long long)(b[i]+b[i-1]);
		printf("%I64d ",cur);
	}
	return 0;
}