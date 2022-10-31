#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=100010;
int n,l,r,ql,qr;
int a[N];
LL s[N];
LL ans;
int abs(int n) { return n>0?n:-n;}
int main()
{
	scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
	ans=1e+18;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for (int i=0;i<=n;i++)
	{
		LL ext;
		if (abs(n-i*2)<=1) ext=0;else
		if (i*2<=n) ext=1LL*(n-i-i-1)*qr;else
		ext=1LL*(i+i-n-1)*ql;
		LL now=1LL*s[i]*l+1LL*(s[n]-s[i])*r;
		ans=min(ans,ext+now);
	}
	cout<<ans<<endl;
	return 0;
}