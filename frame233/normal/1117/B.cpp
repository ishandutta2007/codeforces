#include<cstdio>
#include<algorithm>
typedef unsigned long long ull;
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int tmp=a;a=b,b=tmp;}

int main()
{
	int n,m,k;
	ull max1=0,max2=0,x;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%llu",&x);
		if(x>max1)
		{
			max2=max1;
			max1=x;
		}
		else if(x>max2)
		{
			max2=x;
		}
	}
	// k*max1+max2
	int cnt=m/(k+1);
	ull ans=1ULL*cnt*(1ULL*k*max1+max2)+1ULL*(m-cnt*(k+1))*max1;
	printf("%llu\n",ans);
	return 0;
}