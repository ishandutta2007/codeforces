#include<cstdio>
#include<algorithm>

int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}

int main()
{
	int a,b,c,x,y,z;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
	if(a>x)
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		x-=a;
	}
	if(b>x+y)
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		if(x+y+z-b-c>=0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		return 0;
	}
	return 0;
}