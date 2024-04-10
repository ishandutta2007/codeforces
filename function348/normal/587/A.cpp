#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000110;
int n,ans;
int a[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	for (int i=0;i<=1000030;i++) 
	{
		a[i+1]+=a[i]/2;
		a[i]%=2;
		ans+=a[i];
	}
	printf("%d\n",ans);
	return 0;
}