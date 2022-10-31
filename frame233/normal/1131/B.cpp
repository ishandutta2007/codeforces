#include<cstdio>
#include<algorithm>
typedef long long ll;
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int tmp=a;a=b,b=tmp;}

int main()
{
	int n,x=0,y=0,a,b;
	ll ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&a,&b);
		if(x==y)
		{
			ans+=min(a-x,b-y);
			x=a,y=b;
		}
		else if(x>y)
		{
			if(x<=b)
			{
				y=x;
				++ans;
				ans+=min(a-x,b-y);
				x=a,y=b;
			}
			else
			{
				x=a,y=b;
			}
		}
		else
		{
			if(y<=a)
			{
				x=y;
				++ans;
				ans+=min(a-x,b-y);
				x=a,y=b;
			}
			else
			{
				x=a,y=b;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}