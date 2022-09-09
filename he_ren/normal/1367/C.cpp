#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

char s[MAXN];
int nxt[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	nxt[n+1] = inf;
	for(int i=n; i>=1; --i)
		nxt[i] = s[i]=='1'? i: nxt[i+1];
	
	int lst = -inf, ans = 0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='1'){ lst=i; continue;}
		if(lst < i-d && i+d < nxt[i])
			++ans, lst=i;
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}