#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
const int N=50005;
int a[N];
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline bool cmp(int a,int b){return a>b;}
int main()
{
	int n,ans=0,d=0,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),sum+=a[i];
	ans=sum;
	std::sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;++i)
	{
		d=0x3f3f3f3f;
		for(int j=2;j*j<=a[i];++j)
		{
			if(!(a[i]%j))
			{
				d=min(d,a[i]/j+a[n]*j);
				d=min(d,j+a[n]*(a[i]/j));
			}
		}
		ans=min(ans,sum-a[i]-a[n]+d);
	}
	printf("%d\n",ans);
	return 0;
}