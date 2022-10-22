#include<cstdio>
#include<cmath>
using namespace std;
int n,a[100005],now,x;
long long sum;
bool flag;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0) flag=true;
		if(abs(a[i]-1)>=abs(a[i]+1))
		{
			sum+=abs(a[i]+1);
			x++;
		}
		else sum+=abs(a[i]-1);
	}
	if(x%2==1 && !flag) sum+=2;
	printf("%I64d\n",sum);
}