#include<cstdio>
#include<algorithm>

int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
inline void swap(int &a,int &b){int tmp=a;a=b,b=tmp;}
const int N=100005;

int a[N],ans[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	int l=0,r=n+1;
	for(int i=1;i<=n;++i)
	{
		if(i&1)
		{
			ans[++l]=a[i];
		}
		else
		{
			ans[--r]=a[i];
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}