#include<cstdio>
#include<algorithm>
const int MAXN = 100 + 5;
const int MAXA = 100 + 5;
using namespace std;

int a[MAXN],c[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(!c[a[i]])
		{
			++ans;
			for(int t=a[i]; t<=100; t+=a[i]) c[t]=1;
		}
	}
	
	printf("%d",ans);
	return 0;
}