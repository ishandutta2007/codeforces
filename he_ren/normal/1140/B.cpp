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
	int n;
	scanf("%d%s",&n,s+1);
	if(s[1]=='<' && s[n]=='>')
	{
		int i=1;
		while(s[i]==s[1]) ++i;
		
		int j=n;
		while(s[j]==s[n]) --j;
		
		printf("%d\n",min(i-1,n-j));
	}
	else printf("0\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}