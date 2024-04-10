#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	int cnt[2] = {0,0};
	for(int i=1; i<=n; ++i)
		++cnt[s[i]-'0'];
	
	int tot = min(cnt[0], cnt[1]);
	if(tot&1) printf("DA\n");
	else printf("NET\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}