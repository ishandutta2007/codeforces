#include<cstdio>
#include<algorithm>
using namespace std;
int n,p,Pow2[31];
bool f(int x,int y)
{
	if(x<y) return false;
	int cnt=0;
	for(int i=30;i>=0;i--)
	{
		if(x>=Pow2[i]) 
		{
			cnt++;
			x-=Pow2[i];
		} 
	}
	if(cnt>y) return false;
	return true;
}
int main()
{
	Pow2[0]=1;
	for(int i=1;i<=30;i++)
	{
		Pow2[i]=Pow2[i-1]*2;
	}
	scanf("%d%d",&n,&p);
	for(int i=0;i<=10000;i++)
	{
		if(f(n-i*p,i))
		{
			printf("%d\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}