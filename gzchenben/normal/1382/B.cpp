#include<cstdio>
#include<cstring>
using namespace std;
int n,m,t,a[100005],x,prex;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		} 
		x=2;
		for(int i=n;i>=1;i--)
		{
			if(a[i]==1) x=(3-x);
			if(a[i]!=1) x=1;
		}
		if(x==1) printf("First\n");
		else printf("Second\n");
	}
}