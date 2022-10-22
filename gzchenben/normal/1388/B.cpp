#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,t,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=n;i>=1;i--)
		{
			if(4*(n-i)<n) a[i]=8;
			else a[i]=9;
		}
		for(int i=1;i<=n;i++)printf("%d",a[i]);
		printf("\n");
	}
}