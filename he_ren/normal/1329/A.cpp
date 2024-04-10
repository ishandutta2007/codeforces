#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

int a[MAXM];
int ans[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
		scanf("%d",&a[i]);
	
	int tot=n;
	for(int i=m; i>=1; --i)
	{
		if(min(tot-1,n-a[i]) < i-1){ printf("-1"); return 0;}
		ans[i] = max(tot-a[i]+1, i);
		tot = ans[i]-1;
	}
	if(tot){ printf("-1"); return 0;}
	
	for(int i=1; i<=m; ++i)
		printf("%d ",ans[i]);
	return 0;
}