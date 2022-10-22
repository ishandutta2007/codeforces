#include<cstdio> 
using namespace std;
int a,b,n,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&n);
		int ans=0;
		if(n%3!=1) ans^=a;
		if(n%3!=0) ans^=b;
		printf("%d\n",ans);
	}
	return 0;
}