#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,q,g,temp[3];
long long gcd(long long x,long long y)
{
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&q);
	g=gcd(n,m);
//	printf("%lld\n",g); 
	temp[1]=n/g;
	temp[2]=m/g;
	while(q--)
	{
		long long sx,sy,ex,ey;
		scanf("%I64d%I64d%I64d%I64d",&sx,&sy,&ex,&ey);
		if(((sy-1)/temp[sx])==((ey-1)/temp[ex]))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}