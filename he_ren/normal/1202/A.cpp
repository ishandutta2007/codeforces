#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN], t[MAXN];

void solve(void)
{
	scanf("%s%s",s+1,t+1);
	int n = strlen(s+1);
	int m = strlen(t+1);
	
	reverse(s+1,s+n+1);
	reverse(t+1,t+m+1);
	
	int pos = 0;
	for(int i=1; i<=m; ++i)
		if(t[i] == '1')
		{
			pos = i;
			break;
		}
	
	for(int i=pos; i<=n; ++i)
		if(s[i] == '1')
		{
			printf("%d\n",i-pos);
			return;
		}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}