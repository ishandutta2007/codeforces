#include <cstdio>
#include <algorithm>

int n;
int a[200020], b[200020], x,z;
int main(void)
{
	scanf("%d", &n);
	for(int i=0,x=0;i<n;++i)
	{
		scanf("%d", a+(i-x));
		if(!a[(i-x)])
			x=1;
	}
	for(int i=0,x=0;i<n;++i)
	{
		scanf("%d", b+(i-x));
		if(!b[(i-x)])
			x=1;
		if(b[i-x]==a[0])
			z=i-x;
	}
	--n;
	std::rotate(b, b+z, b+n);
	for(int i=0;i<n;++i)
		if(a[i]!=b[i])
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	return 0;
}