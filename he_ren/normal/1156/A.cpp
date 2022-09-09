#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 0;
	for(int i=1; i<n; ++i)
	{
		int x=a[i], y=a[i+1];
		if(x==1) ans += y+1;
		if(x==2)
		{
			if(y==1) ans += 3;
			else
			{
				printf("Infinite\n");
				return;
			}
		}
		if(x==3)
		{
			if(y==1) ans += 4;
			else
			{
				printf("Infinite\n");
				return;
			}
		}
	}
	for(int i=1; i+2<=n; ++i)
	{
		if(a[i]==3 && a[i+1]==1 && a[i+2]==2)
			--ans;
	}
	printf("Finite\n");
	printf("%d\n",ans);
}

int main(void)
{
	int T=1;
	while(T--) solve();
	return 0;
}