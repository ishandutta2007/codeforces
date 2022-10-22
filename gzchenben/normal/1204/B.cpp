#include<cstdio>
using namespace std;
int n,l,r;
int minn(int x,int y)
{
	int sum=0;
	for(int i=0;i<y;i++)
	{
		sum+=(1<<i);
		x--;
	}
	sum+=x;
	return sum;
}
int maxn(int x,int y)
{
	int sum=0;
	for(int i=0;i<y;i++)
	{
		sum+=(1<<i);
		x--;
	}
	sum+=x*(1<<(y-1));
	return sum;
}
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	printf("%d ",minn(n,l));
	printf("%d\n",maxn(n,r));
}