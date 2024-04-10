#include<cstdio>
#include<iostream>
using namespace std;
const int N=100010;
int n;
int a[N],b[N],c[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	b[0]=c[n+1]=2000000000;
	for (int i=1;i<=n;i++) b[i]=min(b[i-1],a[i]-i);
	for (int i=n;i>=1;i--) c[i]=min(c[i+1],a[i]+i);
	c[1]=2,c[n]=n+1;
	int ans=0;
	for (int i=1;i<=n;i++) 
	{
		ans=max(ans,min(min(b[i]+i,c[i]-i),min(i,n+1-i)));
	}
	printf("%d\n",ans);
	return 0;
}