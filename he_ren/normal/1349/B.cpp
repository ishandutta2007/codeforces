#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int a[MAXN];
bool can[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	bool flag=0;
	for(int i=1; i<=n; ++i)
		if(a[i]==d)
		{
			flag=1;
			break;
		}
	if(!flag){ printf("no\n"); return;}
	if(n==1){ printf("yes\n"); return;}
	
	a[0] = a[n+1] = 0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i]>=d || (a[i-1]>=d && a[i+1]>=d))
			can[i] = 1;
		else can[i] = 0;
	}
	
	for(int i=1; i<n; ++i)
		if(can[i] && can[i+1])
		{
			printf("yes\n");
			return;
		}
	printf("no\n");
	return;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}