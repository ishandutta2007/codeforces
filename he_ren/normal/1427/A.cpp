#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int sum = 0;
	for(int i=1; i<=n; ++i) sum += a[i];
	if(sum == 0){ printf("NO\n"); return;}
	printf("YES\n");
	
	sort(a+1,a+n+1);
	
	bool flag = 1;
	sum = 0;
	for(int i=1; i<=n; ++i)
	{
		sum += a[i];
		if(!sum){ flag = 0; break;}
	}
	if(!flag) reverse(a+1,a+n+1);
	
	for(int i=1; i<=n; ++i)
		printf("%d ",a[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}