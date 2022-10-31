#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=400010;
int n;
LL ans;
int a[N],v[N],c[N];
int gcd(int a,int b) { return b?gcd(b,a%b):a;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n/2;i++)
	if (n%i==0)
	{
		for (int j=1;j<=n;j++) v[j]=0,c[j]=0;
		for (int j=1;j<=i;j++)
		{
			int mx=0;
			for (int k=j;k<=n;k+=i) mx=max(mx,a[k]);
			for (int k=j;k<=n;k+=i) if (a[k]==mx) v[k]=1;
		}
		int flag=1,st=0;
		for (int j=1;j<=n;j++) { v[j+n]=v[j];if (!v[j]) flag=0;}
		if (!flag)
			for (int j=1;j<=n;j++) if (v[j]==0) { st=j+1;break;}
		for (int j=st,k=0;j<=st+n-1;j++)
			if (v[j]) k++;else c[k]++,k=0;
		LL k1=0,k2=0;
		if (flag) k2=n;
		for (int j=n;j>=i;j--)
		{
			k1+=c[j];k2+=k1;
			if (k2&&j%i==0) if (gcd(j,n)==i) ans+=k2;
		}
	}
	cout<<ans<<endl;
	return 0;
}