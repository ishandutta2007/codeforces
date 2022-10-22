#include<cstdio>
using namespace std;
int n;
bool comp(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return true;
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	int tmp=2;
	while(1)
	{
		if(comp(n+tmp) && comp(tmp))
		{
			printf("%d %d\n",n+tmp,tmp);
			return 0;
		}
		tmp++;
	}
}