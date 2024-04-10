#include<cstdio>
#include<cstring>
const int MAXN  = 100 + 5;
using namespace std;

char s[MAXN];

int main(void)
{
	int n,p,q;
	scanf("%d%d%d%s",&n,&p,&q,s);
	for(int i=0; p*i<=n; ++i)
	{
		for(int j=0; q*j<=n; ++j)
		{
			if(i*p+j*q == n)
			{
				printf("%d\n",i+j);
				for(int x=1; x<=i; ++x)
				{
					for(int k=(x-1)*p; k<x*p; ++k) putchar(s[k]);
					putchar('\n');
				}
				for(int y=1; y<=j; ++y)
				{
					for(int k=(y-1)*q; k<y*q; ++k) putchar(s[k+i*p]);
					putchar('\n');
				}
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}