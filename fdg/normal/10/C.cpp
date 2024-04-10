#include <cstdio>

#define ll long long

using namespace std;

ll F(int m,int n)
{
	return n/9+(n%9>=m ? 1 : 0);
}

int main()
{
	int n;
	scanf("%d",&n);
	ll f=0;
	for(int j=1;j<=9;j++)
		for(int t=1;t<=9;t++)
		{
			f+=F(j,n)*F(t,n)*F((j*t-1)%9+1,n);
			for(int r=0;9*r+j<=n;r++)
				f-=F(t,n/(9*r+j));
		}
	printf("%I64d\n",f);
	return 0;
}