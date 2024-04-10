#include<cstdio>
#include<algorithm>
const int N=100005;
int a[N],b[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	if(a[1]!=b[1]||a[n]!=b[n])
	{
		printf("No\n");
		return 0;
	}
	for(int i=1;i<n;++i)
	{
		a[i]=a[i+1]-a[i];
		b[i]=b[i+1]-b[i];
	}
	std::sort(a+1,a+n),std::sort(b+1,b+n);
	for(int i=1;i<n;++i)
	{
		if(a[i]!=b[i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}