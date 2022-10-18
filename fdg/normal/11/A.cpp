#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,d,last=0;
	long long ans=0;
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)
	{
		long a,k;
		scanf("%d",&a);
		if (last<a)
		{
			last=a;
			continue;
		}
		k=(last-a)/d+1;
		a+=k*d;
		ans+=k;
		last=a;
	}
	printf("%I64d\n",ans);
/*	int x;
	scanf("%d",&x);
	double X=labs(x),D=1+8*X,x1=(-1+sqrt(D))/2;
	long long X1=x1;
	long long ans=X1;
	ans+=2*((long long)x-((X1+1)*X1)/2);
	printf("%I64d\n",ans);
*/	return 0;
}