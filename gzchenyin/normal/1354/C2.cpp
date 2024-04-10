#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long double ans,tmp;
int n,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n=n*2;
		tmp=(long double)1.0/sin((long double)3.141592653589/(long double)n)/2.0;
//		printf("%Lf\n",tmp);
		ans=cos((long double)3.141592653589/(long double)(n*2))*tmp*2.0;
//		ans=sqrt(ans*ans-(long double)1.0);
		printf("%.12Lf\n",ans);
	}
}