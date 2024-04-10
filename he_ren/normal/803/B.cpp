#include<cstdio>
#include<algorithm>
const int MAXN = 2e5 + 5;
using namespace std;

int a[MAXN],t[MAXN],m=0;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		if(!a[i]) t[++m]=i;
	
	for(int i=1; i<=n; ++i)
	{
		int x = lower_bound(t+1,t+m+1,i)-t;
		
		int ans = n;
		if(x<=m) ans=t[x]-i;
		if(x>1 && ans > i-t[x-1]) ans=i-t[x-1];
		printf("%d ",ans);
	}
	return 0;
}