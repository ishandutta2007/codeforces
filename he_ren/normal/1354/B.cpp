#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	int lst[4] = {0,0,0,0};
	
	int ans = -1;
	for(int i=1; i<=n; ++i)
	{
		lst[s[i]-'0'] = i;
		if(!lst[1] || !lst[2] || !lst[3]) continue;
		
		int len = i - min(lst[1], min(lst[2],lst[3])) + 1;
		if(ans==-1 || ans>len)
			ans = len;
	}
	
	if(ans == -1) printf("0\n");
	else printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}