#include<bits/stdc++.h>
using namespace std;
int n,a[6],x,y;
long long t;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		a[(x&2)+(y&2)/2]++;
	}
	for(int i=0;i<4;i++)
		t+=1ll*a[i]*(a[i]-1)*(a[i]-2)/6+1ll*a[i]*(a[i]-1)*(n-a[i])/2;
	printf("%lld\n",t);
	return 0;
}