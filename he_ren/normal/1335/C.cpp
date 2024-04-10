#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

int a[MAXN];
int t[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) t[i]=0;
	for(int i=1; i<=n; ++i) ++t[a[i]];
	
	int tot=0, mx=0;
	for(int i=1; i<=n; ++i)
	{
		if(t[i]) ++tot;
		if(t[i]>mx) mx=t[i];
	}
	
	printf("%d\n",max(min(tot,mx-1), min(tot-1,mx)));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}