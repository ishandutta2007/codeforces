#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000010;
int n,a,b,t,ans;
char s[N];
int f1[N],g1[N],f2[N],g2[N];
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&t);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) s[i+n]=s[i];
	for (int i=2;i<=n;i++) f1[i-1]=f1[i-2]+a+1+(s[i]=='w')*b;
	for (int i=1;i<n;i++) f2[i]=f2[i-1]+a+1+(s[n+1-i]=='w')*b;
	for (int i=1;i<n;i++) g1[i]=f1[i]+i*a;
	for (int i=1;i<n;i++) g2[i]=f2[i]+i*a;
	t-=(s[1]=='w')*b+1;
	if (t<0) { printf("0\n");return 0;}
	for (int i=0,j=n-1;i<n;i++)
	{
		while (f1[i]+g2[j]>t&&j) j--;
		if (f1[i]+g2[j]>t) break;
		ans=max(ans,i+j+1);
	}
	for (int i=0,j=n-1;i<n;i++)
	{
		while (f2[i]+g1[j]>t&&j) j--;
		if (f2[i]+g1[j]>t) break;
		ans=max(ans,i+j+1);
	}
	ans=min(ans,n);
	printf("%d\n",ans);
	return 0;
}