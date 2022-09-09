#include<cstdio>
#include<algorithm>
const int MAXN = 150000 + 5;
using namespace std;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	int ans=1;
	if(a[1]>1) --a[1]; 
	for(int i=2, last=a[1]; i<=n; ++i)
	{
		if(a[i]-1 > last)
		{
			last = --a[i];
			++ans;
			continue;
		}
		if(a[i] > last)
		{
			last = a[i];
			++ans;
			continue;
		}
		if(a[i]+1 > last)
		{
			last = ++a[i];
			++ans;
			continue;
		}
	}
	printf("%d",ans);
	return 0;
}