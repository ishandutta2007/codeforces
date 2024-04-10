#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	if(n<11) printf("NO\n");
	else
	{
		for(int i=1; i<=n; ++i)
			if(s[i] == '8')
			{
				if(n-i+1 < 11) printf("NO\n");
				else printf("YES\n");
				return;
			}
		printf("NO\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}