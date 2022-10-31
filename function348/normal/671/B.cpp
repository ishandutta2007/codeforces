#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=500100;
int n,k;
int a[N];
LL s[N];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1,r=n;
	for (int i=1;i<=n;i++)
	if (1LL*a[i]*i-s[i]<=k) l=i;
	for (int i=n;i>=1;i--)
	if (s[n]-s[i]-1LL*(n-i)*a[i]<=k) r=i;
	int minans=(s[n]%n==0)?0:1;
	if (l>=r) { printf("%d\n",minans);return 0;}
	int minx=(k-(1LL*a[l]*l-s[l]))/l+a[l];
	int maxx=a[r]-(k-(s[n]-s[r]-1LL*(n-r)*a[r]))/(n-r+1);
	printf("%d\n",max(minans,maxx-minx));
	return 0;
}