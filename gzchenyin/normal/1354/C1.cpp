#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long double ans;
int n,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n=n*2;
		ans=(long double)1/sin((long double)3.141592653589/(long double)n);
		ans=sqrt(ans*ans-(long double)1.0);
		printf("%.12Lf\n",ans);
	}
}