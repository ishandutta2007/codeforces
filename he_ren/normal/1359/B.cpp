#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;
const int MAXM = 1e3 + 5;

char s[MAXN][MAXM];

void solve(void)
{
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	if(y > x*2) y=x*2;
	
	ll ans = 0;
	for(int k=1; k<=n; ++k)
	{
		for(int i=1,j=1; i<=m; i=j)
		{
			while(s[k][i]==s[k][j]) ++j;
			if(s[k][i]=='*') continue;
			
			ans += (j-i)/2 * y + (j-i)%2 * x;
		}
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}