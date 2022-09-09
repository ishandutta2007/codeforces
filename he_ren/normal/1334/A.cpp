#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int n;
	scanf("%d",&n);
	int lp=0,lc=0;
	bool flag=1;
	for(int i=1; i<=n; ++i)
	{
		int p,c;
		scanf("%d%d",&p,&c);
		if(p>=lp && c>=lc && p>=c && p-lp >= c-lc)
		{
			lp=p; lc=c;
			continue;
		}
		flag=0;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}