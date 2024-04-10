#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e2 + 5;

int a[MAXN];
void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	
	for(int i=2; i<=n; ++i)
		if(a[i]-a[i-1] == 1)
		{
			printf("2\n");
			return;
		}
	printf("1\n");
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}