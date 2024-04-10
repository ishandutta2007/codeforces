#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000000;
typedef long long LL;
struct Edge {int x,y,z,ne;};
Edge e[N*2];int last[N];
int a[N],b[N];
int n,m,k,top;
long long ans;
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	int cnt=n;ans=0;
	for (int i=1;i<=n;i++) 
	{
		int x;scanf("%d",&x);
		if (a[top]==x) b[top]++;else a[++top]=x,b[top]=1;
		if (b[top]==k) b[top]=0,cnt-=k,top--;
	}
	int p=0;
	for (int i=1;i*2<=top;i++)
	if (a[i]==a[top+1-i]&&b[i]+b[top+1-i]==k) p=i;else break;
	if (top%2==0)
	{
		ans=1LL*cnt*m-1LL*(m-1)*k*p;
		if (a[p+1]==a[top-p]&&b[p+1]+b[top-p]>=k) ans-=1LL*(m-1)*k;
	}
	else
	{
		ans=1LL*cnt*m-1LL*(m-1)*k*p;
		if (p<top/2) 
		{
			if (a[p+1]==a[top-p]&&b[p+1]+b[top-p]>=k) ans-=1LL*(m-1)*k;
		}
		else 
		{
			if (1LL*b[p+1]*m%k==0) ans=0;
			else ans-=1LL*b[p+1]*m/k*k;
		}
	}
	printf("%lld\n",ans);
	return 0;
}