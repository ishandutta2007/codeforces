#include<cstdio>
using namespace std;
int n,m,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n%2==0 || m%2==0) printf("%d\n",n*m/2);
		else printf("%d\n",(n*m+1)/2);
	}
}