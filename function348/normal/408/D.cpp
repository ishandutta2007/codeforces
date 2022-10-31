#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
int main()
{
	int n,a[1010],f[1010],mo=1000000007;
	f[1]=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n+1;i++) 
		f[i]=(f[i-1]*2%mo+2-f[a[i-1]])%mo;
	f[n+1]=(f[n+1]+mo)%mo;
	printf("%d\n",f[n+1]);
	return 0;
}