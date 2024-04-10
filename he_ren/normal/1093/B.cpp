#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

char s[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	sort(s+1,s+n+1);
	
	bool flag=0;
	for(int i=1; i<n; ++i)
		if(s[i]!=s[i+1])
		{
			flag=1;
			break;
		}
	if(flag) printf("%s\n",s+1);
	else printf("-1\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}