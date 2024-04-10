#include<cstdio>
#include<algorithm>

using namespace std;

int b,maxt,a[5000],n,i,j;

int main()
{
	scanf("%d%d",&n,&b);
	maxt=b;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(i==1)
			continue;
		for(j=1;j<i;++j)
			maxt=max(maxt,(b/a[j])*a[i]+(b%a[j]));
	}
	printf("%d",maxt);
}