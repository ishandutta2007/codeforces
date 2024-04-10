#include<cstdio>
using namespace std;
int n;
long long power(long long x,int y)
{
	 if(y<0) return 0;
	 long long sum=1;
	 for (;y;y>>=1,x*=x) if (y&1) sum*=x;
	 return sum;
}
int main()
{
	  scanf("%d",&n);
	  printf("%I64d\n",power(2,n)-100*power(2,n-13));
}