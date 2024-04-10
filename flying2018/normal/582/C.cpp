#include<iostream>
#include<cstdio>
#include<cstring>
#define N 400010
#define ll long long
using namespace std;
int a[N],f[N],g[N],h[N],c[N];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) g[i]=gcd(i,n);
	ll ans=0;
	for(int d=1;d<n;d++)
	if(n%d==0)
	{
		for(int i=1;i<=n;i++) c[i]=c[i-1]+(g[i]==d);
		for(int i=0;i<d;i++) f[i]=0;
		for(int i=0;i<n;i++) f[i%d]=max(f[i%d],a[i]);
		for(int i=0;i<n;i++) h[i]=h[i+n]=f[i%d]==a[i];
		for(int i=n*2-2;i>=0;i--)
			if(h[i]) h[i]+=h[i+1];
		for(int i=0;i<n;i++) ans+=c[min(n-1,h[i])];
	}
	printf("%lld\n",ans);
	return 0;
}