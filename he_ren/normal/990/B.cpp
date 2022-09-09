#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;

int a[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int ans=n, cnt=1;
	for(int i=2; i<=n; ++i)
	{	
		if(a[i-1]<a[i] && a[i-1]+d >= a[i]) ans-=cnt;
		
		if(a[i-1]==a[i]) ++cnt;
		else cnt=1;
	}
	printf("%d",ans);
	return 0;
}