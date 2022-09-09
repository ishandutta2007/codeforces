#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	int ans = 0, rem = 0;
	for(int i=n; i>=1; --i)
	{
		if(s[i] == 'A')
		{
			if(rem) --rem;
			else ++ans;
		}
		else ++rem;
	}
	ans += rem%2;
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}