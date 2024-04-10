#include<cstdio>
#include<iostream>
using namespace std;
int n,x,ans;
int f[300010];
int main()
{
	
	scanf("%d",&n);
	if (n>=50) cout<<4653LL+(n-100)*49LL<<endl;
	else
	{
	f[0]=1;
	for (int i=1;i<=n;i++)
	{
		
	for (int j=i*50;j>=0;j--)
	{
		f[j]=0;
		if (j>=50&&f[j-50]) f[j]=1;
		if (j>=10&&f[j-10]) f[j]=1;
		if (j>=5&&f[j-5]) f[j]=1;
		if (j>=1&&f[j-1]) f[j]=1;
	}
	}
	ans=0;
	for (int j=1;j<=n*50;j++) ans+=f[j];
	cout<<ans<<endl;
}
	return 0;
}
/*  n k
4*k2+9*k3+49*k4=k-n
*/