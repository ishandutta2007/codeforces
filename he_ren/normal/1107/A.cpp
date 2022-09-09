#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 3e2 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	if(n==2 && s[1]>=s[2]) printf("NO\n");
	else
	{
		printf("YES\n2\n%c ",s[1]);
		for(int i=2; i<=n; ++i) putchar(s[i]);
		putchar('\n');
	}
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}