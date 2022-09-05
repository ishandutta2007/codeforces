//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
struct BIT
{
	int a[200111];
	void init(){memset(a,0,sizeof(a));}
	void add(int x)
	{
		x+=5;
		for(int i=x;i<=200110;i+=i&(-i))a[i]++;
	}
	int sum(int x)
	{
		x+=5;
		int ans=0;
		for(int i=x;i>0;i-=i&(-i))ans+=a[i];
		return ans;
	}
}A;
int n;
int kth(int rk)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int m=l+r>>1;
		if(m-A.sum(m)<rk)l=m+1;else r=m-1;
	}
	return l;
}
void trans(int a[],bool rev)
{
	A.init();
	if(!rev)
	{
		for(int i=1;i<=n;i++)
		{
			A.add(a[i]);
			a[i]-=A.sum(a[i])-1;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=kth(a[i]);
			A.add(a[i]);
		}
	}
}
int a[200111],b[200111];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	trans(a,0);
	trans(b,0);
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl;
	int r=0;
	for(int i=n;i>=1;i--)
	{
		int cur=a[i]+b[i]+r;
		r=cur/(n-i+1);
		cur%=n-i+1;
		a[i]=cur;
	}
	trans(a,1);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}