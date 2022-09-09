#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	if(n&1)
	{
		for(int i=1; i<=n; i+=2)
			if((s[i]-'0')%2 == 1)
			{
				printf("1\n");
				return;
			}
		printf("2\n");
	}
	else
	{
		for(int i=2; i<=n; i+=2)
			if((s[i]-'0')%2 == 0)
			{
				printf("2\n");
				return;
			}
		printf("1\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}